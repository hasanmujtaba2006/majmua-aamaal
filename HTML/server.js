const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const path = require('path');
const fs = require('fs');

process.on('uncaughtException', (err) => { console.error('CRITICAL ERROR:', err); });

const app = express();
const server = http.createServer(app);
const io = new Server(server, { cors: { origin: "*" }, transports: ['websocket', 'polling'] });

const staticPath = fs.existsSync(path.join(__dirname, 'public')) ? path.join(__dirname, 'public') : __dirname;
app.use(express.static(staticPath));

let sessions = {}; 
let disconnectTimeouts = {};

const surahYaseenText = `بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ...`; 
const qaseedaText = `سَقَانِي الْحُبُّ كَأْسَاتِ الْوِصَالِ...`; 

const zikrData = [
    { id: 1, type: 'count', target: 111, titleUrdu: "درود شریف", titleEng: "Durood Shareef", bodyText: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِوَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ", font: 'arabic' },
    { id: 2, type: 'count', target: 111, titleUrdu: "تیسرا کلمہ", titleEng: "Teesra Kalma", bodyText: "سُبْحَانَ اللَّهِ وَالْحَمْدُ لِلَّهِ وَلَا إِلَٰهَ إِلَّا اللَّهُ وَاللَّهُ أَكْبَرُ وَلَا حَوْلَ وَلَا قُوَّةَ إِلَّا بِاللَّهِ الْعَلِيِّ الْعَظِيمِ", font: 'arabic' },
    { id: 20, type: 'read', target: 1, titleUrdu: "سورۃ یٰسین", titleEng: "Surah Yaseen", bodyText: surahYaseenText, font: 'arabic' },
    { id: 21, type: 'read', target: 1, titleUrdu: "قصیدہ غوثیہ", titleEng: "Qaseeda Ghausia", bodyText: qaseedaText, font: 'arabic' },
    { id: 22, type: 'count', target: 111, titleUrdu: "درود شریف", titleEng: "Durood Shareef", bodyText: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِوَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ", font: 'arabic' }
];

function getSessionState(sessionId) {
    const session = sessions[sessionId];
    if(!session) return null;
    const zikr = zikrData[session.currentZikrIndex];
    return {
        sessionName: session.name, currentCount: session.currentCount,
        target: zikr.target, zikr: zikr,
        isFinished: (zikr.type === 'count' && session.currentCount >= zikr.target),
        isLast: (session.currentZikrIndex === zikrData.length - 1)
    };
}

io.on('connection', (socket) => {
    socket.on('createSession', ({ name, password }) => {
        const sessionId = 'sess_' + Math.random().toString(36).substr(2, 9);
        const adminToken = 'adm_' + Math.random().toString(36).substr(2, 9);
        sessions[sessionId] = { id: sessionId, name, password, adminToken, adminId: socket.id, currentZikrIndex: 0, currentCount: 0, users: [socket.id] };
        socket.join(sessionId);
        socket.emit('joinedSession', { sessionId, isAdmin: true, adminToken, state: getSessionState(sessionId) });
    });

    socket.on('joinSession', ({ sessionId, password }) => {
        const session = sessions[sessionId];
        if (!session) return socket.emit('sessionError', 'NOT_FOUND');
        if (session.password && session.password !== password) return socket.emit('sessionError', 'Wrong Password');
        socket.join(sessionId);
        if(!session.users.includes(socket.id)) session.users.push(socket.id);
        socket.emit('joinedSession', { sessionId, isAdmin: false, state: getSessionState(sessionId) });
    });

    socket.on('increment', (sessionId) => {
        const session = sessions[sessionId];
        if (session) {
            const zikr = zikrData[session.currentZikrIndex];
            if (zikr.type === 'count' && session.currentCount < zikr.target) {
                session.currentCount++;
                io.to(sessionId).emit('updateState', getSessionState(sessionId));
            }
        }
    });

    socket.on('nextZikr', (sessionId) => {
        const session = sessions[sessionId];
        if (session && socket.id === session.adminId) {
            if (session.currentZikrIndex < zikrData.length - 1) {
                session.currentZikrIndex++; session.currentCount = 0;
                io.to(sessionId).emit('updateState', getSessionState(sessionId));
            } else { io.to(sessionId).emit('sessionComplete', "MashaAllah! Khatm Complete."); }
        }
    });

    socket.on('endSession', (sessionId) => {
        const session = sessions[sessionId];
        if (session && socket.id === session.adminId) {
            io.to(sessionId).emit('forceExit', 'Session Ended by Admin.');
            delete sessions[sessionId];
        }
    });

    socket.on('disconnect', () => {
        for (const id in sessions) {
            if (sessions[id].adminId === socket.id) {
                disconnectTimeouts[id] = setTimeout(() => { delete sessions[id]; }, 10000);
            }
        }
    });
});

const PORT = process.env.PORT || 3000;
server.listen(PORT, () => console.log(`Server running on port ${PORT}`));