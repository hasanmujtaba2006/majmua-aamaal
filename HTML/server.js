const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const path = require('path');
const fs = require('fs');

process.on('uncaughtException', (err) => {
    console.error('CRITICAL ERROR:', err);
});

const app = express();
const server = http.createServer(app);

const io = new Server(server, {
    cors: { origin: "*", methods: ["GET", "POST"] },
    transports: ['websocket', 'polling']
});

const possiblePaths = [
    path.join(__dirname, 'HTML/public'),
    path.join(__dirname, 'public'),
    path.join(__dirname, '')
];

let staticPath = null;
for (const p of possiblePaths) {
    if (fs.existsSync(path.join(p, 'index.html'))) {
        staticPath = p;
        break;
    }
}
if (staticPath) app.use(express.static(staticPath));

let sessions = {}; 

// --- NEW ZIKR LIST (UPDATED PER REQUEST) ---
const zikrData = [
    // 1. Durood (Updated Text)
    { 
        id: 1, type: 'count', target: 111, 
        titleUrdu: "درود شریف", titleEng: "Durood Shareef", 
        bodyText: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِوَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ", 
        font: 'arabic' 
    },
    // 2. Teesra Kalma (Renamed, Removed Enter)
    { 
        id: 2, type: 'count', target: 111, 
        titleUrdu: "تیسرا کلمہ", titleEng: "Teesra Kalma", 
        bodyText: "سُبْحَانَ اللَّهِ وَالْحَمْدُ لِلَّهِ وَلَا إِلَٰهَ إِلَّا اللَّهُ وَاللَّهُ أَكْبَرُ وَلَا حَوْلَ وَلَا قُوَّةَ إِلَّا بِاللَّهِ الْعَلِيِّ الْعَظِيمِ", 
        font: 'arabic' 
    },
    // 3. Alam Nashrah (Arabic Heading)
    { 
        id: 3, type: 'count', target: 111, 
        titleUrdu: "سورة ألم نشرح", titleEng: "Surah Alam Nashrah", 
        bodyText: "أَلَمْ نَشْرَحْ لَكَ صَدْرَكَ ۝ وَوَضَعْنَا عَنكَ وَزْرَكَ ۝ الَّذِي أَنقَضَ ظَهْرَكَ ۝ وَرَفَعْنَا لَكَ ذِكْرَكَ ۝ فَإِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ إِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ فَإِذَا فَرَغْتَ فَانصَبْ ۝ وَإِلَىٰ رَبِّكَ فَارْغَب ۝", 
        font: 'arabic' 
    },
    // 4. Surah Ikhlas (Arabic Heading)
    { 
        id: 4, type: 'count', target: 111, 
        titleUrdu: "سورة الإخلاص", titleEng: "Surah Ikhlas", 
        bodyText: "قُلْ هُوَ اللَّهُ أَحَدٌ ۝ اللَّهُ الصَّمَدُ ۝ لَمْ يَلِدْ وَلَمْ يُولَدْ ۝ وَلَمْ يَكُن لَّهُ كُفُوًا أَحَدٌ ۝", 
        font: 'arabic' 
    },
    // 5. Isma-e-Husna Part 1 (Split)
    { 
        id: 5, type: 'count', target: 111, 
        titleUrdu: "أسماء الله الحسنى", titleEng: "Isma-e-Husna", 
        bodyText: "يَا بَاقِي أَنْتَ الْبَاقِي", 
        font: 'arabic' 
    },
    // 6. Isma-e-Husna Part 2 (Split)
    { 
        id: 6, type: 'count', target: 111, 
        titleUrdu: "أسماء الله الحسنى", titleEng: "Isma-e-Husna", 
        bodyText: "يَا شَافِي أَنْتَ الشَّافِي", 
        font: 'arabic' 
    },
    // 7. Isma-e-Husna Part 3 (Split)
    { 
        id: 7, type: 'count', target: 111, 
        titleUrdu: "أسماء الله الحسنى", titleEng: "Isma-e-Husna", 
        bodyText: "يَا كَافِي أَنْتَ الْكَافِي", 
        font: 'arabic' 
    },
    // 8. Istighatha (Was Ya Rasool Allah) - Fixed Ashkalina
    { 
        id: 8, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا رَسُولَ اللَّهِ اُنْظُرْ حَالَنَا \n يَا حَبِيْبَ اللَّهِ اِسْمَعْ قَالَنَا \n اِنَّنِي فِي بَحْرِ هَمٍّ مُّغْرَقٌ \n خُذْ يَدِي سَهِّلْ لَنَا اَشْكَالَنَا", 
        font: 'arabic' 
    },
    // 9. Istighatha (Was Ya Habib)
    { 
        id: 9, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا حَبِيْبَ الْإِلَهِ خُذْ بِيَدِي \n مَا لِعَجْزِي سِوَاكَ مُسْتَنَدِي", 
        font: 'arabic' 
    },
    // 10. Istighatha (Was Fasahil)
    { 
        id: 10, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "فَسَهِّلْ يَا إِلَهِي كُلَّ صَعْبٍ \n بِحُرْمَةِ سَيِّدِ الْأَبْرَارِ سَهِّلْ", 
        font: 'arabic' 
    },
    // 11. Istighatha (Was Sahaba)
    { 
        id: 11, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا صِدِّيقُ يَا عُمَرُ \n يَا عُثْمَانُ يَا حَيْدَرُ \n دَفْعِ شَر كُنْ خَيْرَ آوَرْ \n يَا شَبِيْرُ يَا شَبَرْ", 
        font: 'arabic' 
    },
    // 12. Istighatha (Was Ya Hazrat Sultan) - Added Almadad
    { 
        id: 12, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا حَضْرَتِ سُلْطَانِ شَيْخ سَيِّد شَاه \n عَبْدَ الْقَادِرِ جِيلَانِي شَيْئًا لِلَّهِ \n الْمَدَدْ", 
        font: 'arabic' 
    },
    // 13. Istighatha (Was Ma Hama)
    { 
        id: 13, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "ما ہمہ محتاج تو حاجت روا \n الَمدَد یا غوثِ اعظم سیّدا", 
        font: 'urdu' 
    },
    // 14. Istighatha (Was Mushkilat)
    { 
        id: 14, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "مشکلاتِ بے عدد داریم ما \n الَمدَد یا غوثِ اعظم پیرا ما", 
        font: 'urdu' 
    },
    // 15. Istighatha (Was Ya Hazrat Sheikh)
    { 
        id: 15, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا حَضْرَتِ شَيْخ \n مُحْيِ الدِّينِ مُشْكِلْ كُشَا بِالْخَيْر", 
        font: 'arabic' 
    },
    // 16. Istighatha (Was Madad Kun) - NEW TEXT
    { 
        id: 16, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "امداد کن امداد کن \n از بندِ غم آزاد کن \n در دین و دنیا شاد کن \n یا غوثِ اعظم دستگیر", 
        font: 'urdu' 
    },
    // 17. Istighatha (Was Ya Hazrat Ghaus)
    { 
        id: 17, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا حَضْرَتِ غَوْث \n أَغِثْنَا بِإِذْنِ اللَّهِ تَعَالَى", 
        font: 'arabic' 
    },
    // 18. Istighatha (Was Khuz Yadi)
    { 
        id: 18, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "خُذْ يَدِي يَا شَاهِ جِيْلَاں خُذْ يَدِي \n شَيْئًا لِلَّهِ أَنْتَ نُوْرٌ أَحْمَدِي", 
        font: 'arabic' 
    },
    // 19. Istighatha (Was Tufail) - NEW TEXT
    { 
        id: 19, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "طفیل حضرت دستگیر \n دشمن ہووے زیر", 
        font: 'urdu' 
    },
    // 20. Surah Yaseen (READING)
    { 
        id: 20, type: 'read', target: 1, 
        titleUrdu: "سورۃ یٰسین", titleEng: "Surah Yaseen", 
        link: "https://quran.com/36"
    },
    // 21. Qaseeda Ghausia (READING)
    { 
        id: 21, type: 'read', target: 1, 
        titleUrdu: "قصیدہ غوثیہ", titleEng: "Qaseeda Ghausia", 
        link: "https://www.alahazrat.net/islam/qasida-ghousia.php"
    },
    // 22. Durood (Ending - Updated Text to match #1)
    { 
        id: 22, type: 'count', target: 111, 
        titleUrdu: "درود شریف", titleEng: "Durood Shareef", 
        bodyText: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِوَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ", 
        font: 'arabic' 
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
    io.emit('updateUserCount', io.engine.clientsCount);
    socket.emit('sessionList', getPublicSessionList());

    socket.on('createSession', ({ name, password, forcedId }) => {
        const sessionId = forcedId || 'sess_' + Math.random().toString(36).substr(2, 9);
        const adminToken = 'adm_' + Math.random().toString(36).substr(2, 9);
        
        sessions[sessionId] = {
            id: sessionId, name: name, password: password, adminToken: adminToken, adminId: socket.id,
            currentZikrIndex: 0, currentCount: 0, users: [socket.id]
        };
        socket.join(sessionId);
        io.to(sessionId).emit('joinedSession', { sessionId: sessionId, isAdmin: true, adminToken: adminToken, state: getSessionState(sessionId) });
        io.broadcast.emit('sessionList', getPublicSessionList());
    });

    socket.on('joinSession', ({ sessionId, password }) => {
        const session = sessions[sessionId];
        if (!session) { socket.emit('sessionError', 'NOT_FOUND'); return; }
        if (session.password && session.password !== password) { socket.emit('sessionError', 'Incorrect Password.'); return; }
        socket.join(sessionId);
        if(!session.users.includes(socket.id)) session.users.push(socket.id);
        io.to(sessionId).emit('joinedSession', { sessionId: sessionId, isAdmin: (socket.id === session.adminId), state: getSessionState(sessionId) });
    });

    socket.on('reJoinSession', ({ sessionId, adminToken }) => {
        const session = sessions[sessionId];
        if (session) {
            socket.join(sessionId);
            if(!session.users.includes(socket.id)) session.users.push(socket.id);
            let isAdmin = (adminToken && session.adminToken === adminToken);
            if(isAdmin) session.adminId = socket.id;
            socket.emit('joinedSession', { sessionId: sessionId, isAdmin: isAdmin, state: getSessionState(sessionId) });
        } else { socket.emit('sessionError', 'NOT_FOUND'); }
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
            io.to(sessionId).emit('sessionComplete', "MashaAllah! Khatm Complete.");
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
        io.to(sessionId).emit('forceExit', 'Session Ended.');
        io.socketsLeave(sessionId);
        delete sessions[sessionId];
        io.emit('sessionList', getPublicSessionList());
    });

    socket.on('disconnect', () => { io.emit('updateUserCount', io.engine.clientsCount); });
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
server.listen(PORT, () => { console.log(`Server running on port ${PORT}`); });