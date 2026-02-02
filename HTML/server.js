const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const path = require('path');
const fs = require('fs');

// --- SAFETY NET ---
process.on('uncaughtException', (err) => {
    console.error('CRITICAL ERROR:', err);
});

const app = express();
const server = http.createServer(app);

// --- CONFIG ---
const io = new Server(server, {
    cors: { origin: "*", methods: ["GET", "POST"] },
    transports: ['websocket', 'polling']
});

// --- PATHS ---
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

// --- ZIKR CONTENT (MATCHING YOUR IMAGE) ---
const zikrData = [
    // 1. Durood Ghausia
    { 
        id: 1, type: 'count', target: 111, 
        titleUrdu: "درودِ غوثیہ", titleEng: "Durood-e-Ghausia", 
        bodyText: "اللَّهُمَّ صَلِّ عَلَى سَيِّدِنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُودِ وَالْكَرَمِ وَآلِهِ وَبَارِكْ وَسَلِّمْ", 
        font: 'arabic' 
    },
    // 2. Tahlil
    { 
        id: 2, type: 'count', target: 111, 
        titleUrdu: "تہلیل", titleEng: "Tahlil", 
        bodyText: "سُبْحَانَ اللَّهِ وَالْحَمْدُ لِلَّهِ وَلَا إِلَٰهَ إِلَّا اللَّهُ وَاللَّهُ أَكْبَرُ\nوَلَا حَوْلَ وَلَا قُوَّةَ إِلَّا بِاللَّهِ الْعَلِيِّ الْعَظِيمِ", 
        font: 'arabic' 
    },
    // 3. Surah Alam Nashrah
    { 
        id: 3, type: 'count', target: 111, 
        titleUrdu: "سورۃ الم نشرح", titleEng: "Surah Alam Nashrah", 
        bodyText: "أَلَمْ نَشْرَحْ لَكَ صَدْرَكَ ۝ وَوَضَعْنَا عَنكَ وَزْرَكَ ۝ الَّذِي أَنقَضَ ظَهْرَكَ ۝ وَرَفَعْنَا لَكَ ذِكْرَكَ ۝ فَإِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ إِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ فَإِذَا فَرَغْتَ فَانصَبْ ۝ وَإِلَىٰ رَبِّكَ فَارْغَب ۝", 
        font: 'arabic' 
    },
    // 4. Surah Ikhlas
    { 
        id: 4, type: 'count', target: 111, 
        titleUrdu: "سورۃ الاخلاص", titleEng: "Surah Ikhlas", 
        bodyText: "قُلْ هُوَ اللَّهُ أَحَدٌ ۝ اللَّهُ الصَّمَدُ ۝ لَمْ يَلِدْ وَلَمْ يُولَدْ ۝ وَلَمْ يَكُن لَّهُ كُفُوًا أَحَدٌ ۝", 
        font: 'arabic' 
    },
    // 5. Ya Baqi (Isma-e-Husna Part 1)
    { 
        id: 5, type: 'count', target: 111, 
        titleUrdu: "اسمائے حسنیٰ (حصہ اول)", titleEng: "Isma-e-Husna (Part 1)", 
        bodyText: "يَا بَاقِي أَنْتَ الْبَاقِي \n يَا شَافِي أَنْتَ الشَّافِي \n يَا كَافِي أَنْتَ الْكَافِي", 
        font: 'arabic' 
    },
    // 6. Ya Rasool Allah
    { 
        id: 6, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا رَسُولَ اللَّهِ اُنْظُرْ حَالَنَا \n يَا حَبِيْبَ اللَّهِ اِسْمَعْ قَالَنَا \n اِنَّنِي فِي بَحْرِ هَمٍّ مُّغْرَقٌ \n خُذْ يَدِي سَهِّلْ لَنَا اِشْكَالَنَا", 
        font: 'arabic' 
    },
    // 7. Ya Habib Allah
    { 
        id: 7, type: 'count', target: 111, 
        titleUrdu: "ندا", titleEng: "Nida", 
        bodyText: "يَا حَبِيْبَ الْإِلَهِ خُذْ بِيَدِي \n مَا لِعَجْزِي سِوَاكَ مُسْتَنَدِي", 
        font: 'arabic' 
    },
    // 8. Fasahil Ya Ilahi
    { 
        id: 8, type: 'count', target: 111, 
        titleUrdu: "مناجات", titleEng: "Munajat", 
        bodyText: "فَسَهِّلْ يَا إِلَهِي كُلَّ صَعْبٍ \n بِحُرْمَةِ سَيِّدِ الْأَبْرَارِ سَهِّلْ", 
        font: 'arabic' 
    },
    // 9. Ya Siddiq Ya Umar (Sahaba)
    { 
        id: 9, type: 'count', target: 111, 
        titleUrdu: "یادِ خلفائے راشدین", titleEng: "Remembrance of Caliphs", 
        bodyText: "يَا صِدِّيقُ يَا عُمَرُ \n يَا عُثْمَانُ يَا حَيْدَرُ \n دَفْعِ شَر كُنْ خَيْرَ آوَرْ \n يَا شَبِيْرُ يَا شَبَرْ", 
        font: 'arabic' // Actually Persian/Arabic mix, but Arabic font works best
    },
    // 10. Ya Hazrat Sultan (Sheikh Abdul Qadir)
    { 
        id: 10, type: 'count', target: 111, 
        titleUrdu: "استمداد غوثیہ", titleEng: "Istimdad Ghausia", 
        bodyText: "يَا حَضْرَتِ سُلْطَانِ شَيْخ سَيِّد شَاه \n عَبْدَ الْقَادِرِ جِيلَانِي شَيْئًا لِلَّهِ", 
        font: 'arabic' 
    },
    // 11. Ma Hama Muhtaj (Persian Couplet)
    { 
        id: 11, type: 'count', target: 111, 
        titleUrdu: "فریاد", titleEng: "Faryad", 
        bodyText: "ما ہمہ محتاج تو حاجت روا \n الَمدَد یا غوثِ اعظم سیّدا", 
        font: 'urdu' // Use Nastaleeq for this
    },
    // 12. Mushkilat-e-Be Adad
    { 
        id: 12, type: 'count', target: 111, 
        titleUrdu: "حل مشکلات", titleEng: "Hall-e-Mushkilat", 
        bodyText: "مشکلاتِ بے عدد داریم ما \n الَمدَد یا غوثِ اعظم پیرا ما", 
        font: 'urdu' 
    },
    // 13. Ya Hazrat Sheikh
    { 
        id: 13, type: 'count', target: 111, 
        titleUrdu: "ندا", titleEng: "Nida", 
        bodyText: "يَا حَضْرَتِ شَيْخ \n مُحْيِ الدِّينِ مُشْكِلْ كُشَا بِالْخَيْر", 
        font: 'arabic' 
    },
    // 14. Madad Kun (Persian)
    { 
        id: 14, type: 'count', target: 111, 
        titleUrdu: "استمداد", titleEng: "Istimdad", 
        bodyText: "مدد کن یا اللہ \n از دل و جانِ شیدا شُدَن \n یا غوثِ اعظم دستگیر", 
        font: 'urdu' 
    },
    // 15. Ya Hazrat Ghaus
    { 
        id: 15, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا حَضْرَتِ غَوْث \n أَغِثْنَا بِإِذْنِ اللَّهِ تَعَالَى", 
        font: 'arabic' 
    },
    // 16. Khuz Yadi
    { 
        id: 16, type: 'count', target: 111, 
        titleUrdu: "مناجات", titleEng: "Munajat", 
        bodyText: "خُذْ يَدِي يَا شَاهِ جِيْلَاں خُذْ يَدِي \n شَيْئًا لِلَّهِ أَنْتَ نُوْرٌ أَحْمَدِي", 
        font: 'arabic' 
    },
    // 17. Tufail-e-Hazrat Dastagir
    { 
        id: 17, type: 'count', target: 111, 
        titleUrdu: "وسیلہ", titleEng: "Wasila", 
        bodyText: "طفیلِ حضرتِ دستگیر دشمن ہوئے زیر", 
        font: 'urdu' 
    },
    // 18. Surah Yaseen (READING MODE)
    { 
        id: 18, type: 'read', target: 1, 
        titleUrdu: "سورۃ یٰسین", titleEng: "Surah Yaseen", 
        bodyText: "بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ\nيس ۝ وَالْقُرْآنِ الْحَكِيمِ ۝ إِنَّكَ لَمِنَ الْمُرْسَلِينَ ۝ عَلَىٰ صِرَاطٍ مُّسْتَقِيمٍ ۝ تَنزِيلَ الْعَزِيزِ الرَّحِيمِ...",
        fullText: "Surah Yaseen Full Text Here...", // You can add full text or I can link to external
        link: "https://quran.com/36"
    },
    // 19. Qaseeda Ghausia (READING MODE)
    { 
        id: 19, type: 'read', target: 1, 
        titleUrdu: "قصیدہ غوثیہ", titleEng: "Qaseeda Ghausia", 
        bodyText: "سَقَانِي الْحُبُّ كَأْسَاتِ الْوِصَالِ \n فَقُلْتُ لِخَمْرَتِي نَحْوِي تَعَالِي...",
        link: "https://www.alahazrat.net/islam/qasida-ghousia.php"
    },
    // 20. Durood (Ending)
    { 
        id: 20, type: 'count', target: 111, 
        titleUrdu: "درودِ غوثیہ", titleEng: "Durood-e-Ghausia", 
        bodyText: "اللَّهُمَّ صَلِّ عَلَى سَيِّدِنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُودِ وَالْكَرَمِ وَآلِهِ وَبَارِكْ وَسَلِّمْ", 
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