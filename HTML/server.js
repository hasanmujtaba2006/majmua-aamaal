const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const path = require('path');

const app = express();
const server = http.createServer(app);
const io = new Server(server);

// --- FIX FOR BLANK SCREEN: Try both folder paths ---
// 1. Try standard 'public' folder
app.use(express.static(path.join(__dirname, 'public')));
// 2. Try 'HTML/public' (if your structure is nested)
app.use(express.static(path.join(__dirname, 'HTML/public')));

// --- DATA STORAGE ---
let sessions = {}; 

// --- ZIKR CONTENT DATA ---
const zikrData = [
    { 
        id: 1, 
        type: 'count', 
        target: 3, 
        titleUrdu: "تعوذ و تسمیہ", 
        titleEng: "Ta'awwuz & Tasmiyah", 
        bodyText: "أَعُوذُ بِاللَّهِ مِنَ الشَّيْطَانِ الرَّجِيمِ\nبِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ",
        bodyRoman: "A'udhu Billahi Minash-Shaitanir-Rajim\nBismillahir-Rahmanir-Rahim" 
    },
    { 
        id: 2, 
        type: 'count', 
        target: 100, 
        titleUrdu: "استغفار", 
        titleEng: "Astaghfar", 
        bodyText: "أَسْتَغْفِرُ اللَّهَ رَبِّي مِنْ كُلِّ ذَنْبٍ وَأَتُوبُ إِلَيْهِ",
        bodyRoman: "Astaghfirullaha Rabbi Min Kulli Zambin Wa Atubu Ilaih" 
    },
    { 
        id: 3, 
        type: 'count', 
        target: 111, 
        titleUrdu: "درودِ غوثیہ", 
        titleEng: "Durood-e-Ghausia", 
        bodyText: "اللَّهُمَّ صَلِّ عَلَى سَيِّدِنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُودِ وَالْكَرَمِ وَآلِهِ وَبَارِكْ وَسَلِّمْ",
        bodyRoman: "Allahumma Salli Ala Sayyidina Wa Maulana Muhammadin Ma'dinil Judi Wal Karami Wa Aalihi Wa Barik Wa Sallim" 
    },
    { 
        id: 4, 
        type: 'count', 
        target: 111, 
        titleUrdu: "تہلیل", 
        titleEng: "Tahlil", 
        bodyText: "سُبْحَانَ اللَّهِ وَالْحَمْدُ لِلَّهِ وَلَا إِلَٰهَ إِلَّا اللَّهُ وَاللَّهُ أَكْبَرُ\nوَلَا حَوْلَ وَلَا قُوَّةَ إِلَّا بِاللَّهِ الْعَلِيِّ الْعَظِيمِ",
        bodyRoman: "SubhanAllahi Wal Hamdulillahi Wa La Ilaha Illallahu Wallahu Akbar\nWa La Hawla Wa La Quwwata Illa Billahil Aliyl Azim" 
    },
    { 
        id: 5, 
        type: 'count', 
        target: 111, 
        titleUrdu: "سورۃ الم نشرح", 
        titleEng: "Surah Alam Nashrah", 
        bodyText: "أَلَمْ نَشْرَحْ لَكَ صَدْرَكَ ۝ وَوَضَعْنَا عَنكَ وَزْرَكَ ۝ الَّذِي أَنقَضَ ظَهْرَكَ ۝ وَرَفَعْنَا لَكَ ذِكْرَكَ ۝ فَإِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ إِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ فَإِذَا فَرَغْتَ فَانصَبْ ۝ وَإِلَىٰ رَبِّكَ فَارْغَب ۝",
        bodyRoman: "(Recite Full Surah)",
        isUrduBody: true 
    },
    { 
        id: 6, 
        type: 'count', 
        target: 111, 
        titleUrdu: "سورۃ الاخلاص", 
        titleEng: "Surah Ikhlas", 
        bodyText: "قُلْ هُوَ اللَّهُ أَحَدٌ ۝ اللَّهُ الصَّمَدُ ۝ لَمْ يَلِدْ وَلَمْ يُولَدْ ۝ وَلَمْ يَكُن لَّهُ كُفُوًا أَحَدٌ ۝",
        bodyRoman: "(Recite Full Surah)",
        isUrduBody: true 
    },
    { 
        id: 7, 
        type: 'count', 
        target: 111, 
        titleUrdu: "درودِ غوثیہ", 
        titleEng: "Durood-e-Ghausia", 
        bodyText: "اللَّهُمَّ صَلِّ عَلَى سَيِّدِنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُودِ وَالْكَرَمِ وَآلِهِ وَبَارِكْ وَسَلِّمْ",
        bodyRoman: "Allahumma Salli Ala Sayyidina Wa Maulana Muhammadin Ma'dinil Judi Wal Karami Wa Aalihi Wa Barik Wa Sallim" 
    },
    { 
        id: 8, 
        type: 'instruction', 
        target: 0, 
        titleUrdu: "ختمِ خواجگان", 
        titleEng: "Khatm-e-Khwajagan", 
        bodyText: "اب ختم خواجگان پڑھا جائے گا۔ براہ کرم دی گئی لنک پر کلک کریں اور آڈیو کے ساتھ پڑھیں۔",
        bodyRoman: "Now Khatm-e-Khwajagan will be recited. Please click the link below to follow along.",
        links: [
             { label: "Open PDF / Read Online", url: "https://www.rekhta.org/nazms/khatm-e-khwaajgaan-allaah-allaah-allaah-allaah-haafiz-mehmood-sheerani-nazms" }
        ]
    },
    { 
        id: 9, 
        type: 'instruction', 
        target: 0, 
        titleUrdu: "دعا", 
        titleEng: "Dua", 
        bodyText: "اجتماعی دعا",
        bodyRoman: "Collective Dua" 
    }
];

function getPublicSessionList() {
    return Object.values(sessions).map(s => ({
        id: s.id,
        name: s.name,
        hasPassword: !!s.password
    }));
}

io.on('connection', (socket) => {
    console.log('User connected:', socket.id);
    io.emit('updateUserCount', io.engine.clientsCount);
    socket.emit('sessionList', getPublicSessionList());

    socket.on('createSession', ({ name, password }) => {
        const sessionId = 'sess_' + Math.random().toString(36).substr(2, 9);
        sessions[sessionId] = {
            id: sessionId,
            name: name,
            password: password,
            adminId: socket.id,
            currentZikrIndex: 0,
            currentCount: 0,
            users: [socket.id]
        };
        socket.join(sessionId);
        io.to(sessionId).emit('joinedSession', {
            sessionId: sessionId,
            isAdmin: true,
            state: getSessionState(sessionId)
        });
        io.broadcast.emit('sessionList', getPublicSessionList());
    });

    socket.on('joinSession', ({ sessionId, password }) => {
        const session = sessions[sessionId];
        if (!session) {
            socket.emit('sessionError', 'Session not found.');
            return;
        }
        if (session.password && session.password !== password) {
            socket.emit('sessionError', 'Incorrect Password.');
            return;
        }
        socket.join(sessionId);
        session.users.push(socket.id);
        io.to(sessionId).emit('joinedSession', {
            sessionId: sessionId,
            isAdmin: (socket.id === session.adminId),
            state: getSessionState(sessionId)
        });
    });

    socket.on('increment', (sessionId) => {
        const session = sessions[sessionId];
        if (!session) return;
        const zikr = zikrData[session.currentZikrIndex];
        if (zikr.type === 'count' && session.currentCount < zikr.target) {
            session.currentCount++;
            io.to(sessionId).emit('updateState', getSessionState(sessionId));
        }
    });

    socket.on('nextZikr', (sessionId) => {
        const session = sessions[sessionId];
        if (!session || socket.id !== session.adminId) return;
        if (session.currentZikrIndex < zikrData.length - 1) {
            session.currentZikrIndex++;
            session.currentCount = 0;
            io.to(sessionId).emit('updateState', getSessionState(sessionId));
        } else {
            io.to(sessionId).emit('sessionComplete', "MashaAllah! Session Complete.");
        }
    });

    socket.on('resetCurrent', (sessionId) => {
        const session = sessions[sessionId];
        if (!session || socket.id !== session.adminId) return;
        session.currentCount = 0;
        io.to(sessionId).emit('updateState', getSessionState(sessionId));
    });

    socket.on('restartSession', (sessionId) => {
        const session = sessions[sessionId];
        if (!session || socket.id !== session.adminId) return;
        session.currentZikrIndex = 0;
        session.currentCount = 0;
        io.to(sessionId).emit('updateState', getSessionState(sessionId));
    });

    socket.on('endSession', (sessionId) => {
        const session = sessions[sessionId];
        if (!session || socket.id !== session.adminId) return;
        io.to(sessionId).emit('forceExit', 'The Admin has ended this session.');
        io.socketsLeave(sessionId);
        delete sessions[sessionId];
        io.emit('sessionList', getPublicSessionList());
    });

    socket.on('disconnect', () => {
        io.emit('updateUserCount', io.engine.clientsCount);
        for (const sessId in sessions) {
            const sess = sessions[sessId];
            const idx = sess.users.indexOf(socket.id);
            if (idx !== -1) {
                sess.users.splice(idx, 1);
            }
        }
    });
});

function getSessionState(sessionId) {
    const session = sessions[sessionId];
    const zikr = zikrData[session.currentZikrIndex];
    return {
        sessionName: session.name,
        currentCount: session.currentCount,
        target: zikr.target,
        zikr: zikr,
        isFinished: (zikr.type === 'count' && session.currentCount >= zikr.target),
        isLast: (session.currentZikrIndex === zikrData.length - 1)
    };
}

const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});