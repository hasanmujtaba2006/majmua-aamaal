const express = require('express');
const http = require('http');
const { Server } = require("socket.io");
const path = require('path');

const app = express();
const server = http.createServer(app);

const io = new Server(server, {
    cors: { origin: "*", methods: ["GET", "POST"] }
});

app.use(express.static(path.join(__dirname, 'public')));

// --- MASTER DATA ---
const masterZikrList = [
    { id: "۱", titleUrdu: "دُرُودِ غوثیہ", titleEng: "Durood Ghousia", bodyText: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِ وَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ", bodyRoman: "Allahumma Salli 'Ala Sayyidina Wa Nabiyyina...", target: 111, isUrduBody: false },
    { id: "۲", titleUrdu: "تیسرا کلمہ", titleEng: "Third Kalima", bodyText: "سُبْحَانَ اللّٰہِ وَالْحَمْدُ لِلّٰہِ وَلَا اِلٰهَ اِلَّا اللّٰہُ وَاللّٰہُ اَکْبَرُ وَلَا حَوْلَ وَلَا قُوَّةَ اِلَّابِاللّٰہِ الْعَلِیِّ الْعَظِیْمِ", bodyRoman: "SubhanAllahi Wal Hamdu Lillahi...", target: 111, isUrduBody: false },
    { id: "۳", titleUrdu: "سور ہ الم نشرح", titleEng: "Surah Alam Nashrah", bodyText: "اَلَمْ نَشْرَحْ لَكَ صَدْرَكَ ۝ وَوَضَعْنَا عَنكَ وِزْرَكَ ۝...", bodyRoman: "Alam Nashrah Laka Sadrak...", target: 111, isUrduBody: false },
    { id: "۴", titleUrdu: "سورہ اِخلاص", titleEng: "Surah Ikhlas", bodyText: "قُلْ هُوَ اللّٰهُ أَحَدٌ ۝ اَللّٰهُ الصَّمَدُ...", bodyRoman: "Qul Huwa Allahu Ahad...", target: 111, isUrduBody: false },
    { id: "۵", titleUrdu: "اَسْمَاءُ الْحُسْنٰی", titleEng: "Asma-ul-Husna", bodyText: "یَا بَاقِی اَنْتَ الْبَاقِی", bodyRoman: "Ya Baqi Antal Baqi", target: 111, isUrduBody: false },
    { id: "۶", titleUrdu: "اَسْمَاءُ الْحُسْنٰی", titleEng: "Asma-ul-Husna", bodyText: "یَا شَافِی اَنْتَ الشَّافِی", bodyRoman: "Ya Shafi Antal Shafi", target: 111, isUrduBody: false },
    { id: "۷", titleUrdu: "اَسْمَاءُ الْحُسْنٰی", titleEng: "Asma-ul-Husna", bodyText: "یَا کَافِی اَنْتَ الْکَافِی", bodyRoman: "Ya Kafi Antal Kafi", target: 111, isUrduBody: false },
    { id: "۸", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یَا رَسُوْلَ اللّٰہِ اُنْظُرْ حَالَنَا...", bodyRoman: "Ya Rasulallahi Unzur Halana...", target: 111, isUrduBody: false },
    { id: "۹", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یَا حَبِیْبَ الْاِلٰـہِ خُذْ بِیَدِیْ...", bodyRoman: "Ya Habibal Ilahi Khuz Biyadi...", target: 111, isUrduBody: false },
    { id: "۱۰", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "فَسَهِّلْ یَا اِلٰهِیْ كُلَّ صَعْبٍ...", bodyRoman: "Fa Sahhil Ya Ilahi Kulla Sa'bin...", target: 111, isUrduBody: false },
    { id: "۱۱", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یَا صِدِّیْقُ یَا عُمَرْ...", bodyRoman: "Ya Siddiqu Ya 'Umar...", target: 111, isUrduBody: false },
    { id: "۱۲", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یَا حَضْرَتْ سُلْطَانْ شَیْخْ سَیِّدْ شَاهْ عَبْدَ الْقَادِرْ جِیْلَانِیْ شَیْئًا لِلّٰہِ اَلْمَدَدْ", bodyRoman: "Ya Hazrat Sultan Sheikh Sayyid Shah...", target: 111, isUrduBody: false },
    { id: "۱۳", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "ماہمہ محتاج تو حاجت روا \n المددیا غوث اعظم سیدا", bodyRoman: "Ma Hama Muhtaje Tu Hajat Rawa...", target: 111, isUrduBody: true },
    { id: "۱۴", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "مشکلات بے عدد داریم ما \n المدد یا غوث اعظم پیرِ ما", bodyRoman: "Mushkilat Be 'Adad Dareem Ma...", target: 111, isUrduBody: true },
    { id: "۱۵", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "يَا حَضْرَتْ شيْخْ مُحْيَ الدِّيْنْ مُشْكِلْ كُشَا بِالْخَيْر", bodyRoman: "Ya Hazrat Sheikh Muhyiddin Mushkil Kusha Bil Khair", target: 111, isUrduBody: false },
    { id: "۱۶", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "امداد کن امداد کن \n از بندِ غم آزاد کن \n در دین و دنیا شاد کن \n یا غوثِ اعظم دستگیر", bodyRoman: "Imdad Kun Imdad Kun...", target: 111, isUrduBody: true },
    { id: "۱۷", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یا حَضْرَتْ غَوثْ! اَغِثْنَا بِاذْنِ اللّٰهِ تَعَالٰی", bodyRoman: "Ya Hazrat Ghaus! Aghithna Bi Izni Llah Ta'ala", target: 111, isUrduBody: true }, // Urdu Font
    { id: "۱۸", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "خُذْ يَدِيْ يَا شَاہِ جِيلَاں خُذْ يَدِيْ \n شَيئًا للّٰهِ أَنْتَ نُورٌ اَحْمَدِيْ", bodyRoman: "Khuz Yadi Ya Shah-e-Jeelan Khuz Yadi...", target: 111, isUrduBody: false },
    
    // ZIKR 17 (Now ID 19 in array index 18) -> UPDATED TO ARABIC FONT
    { id: "۱۹", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "طفیل حضرت دستگیردشمن ہووےزیر", bodyRoman: "Tufail-e-Hazrat Dastagir Dushman Howe Zer", target: 111, isUrduBody: false }, // False = Arabic Font
    
    { id: "!", titleUrdu: "ہدایات", titleEng: "Instructions", bodyText: "تلاوت: سورۃ یٰسین (۱ بار) \n قصیدہ غوثیہ (۱ بار)", bodyRoman: "Please Recite: Surah Yasin (1 time) & Qasida-e-Gausiya...", target: 1, type: 'instruction' },
    { id: "۲۱", titleUrdu: "دُرُودِ غوثیہ (آخر)", titleEng: "Durood Ghousia (Final)", bodyText: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا...", bodyRoman: "Allahumma Salli 'Ala Sayyidina...", target: 111, isUrduBody: false }
];

// --- SESSION STORAGE ---
const sessions = {}; // Format: { 'roomID': { name: "Name", currentIndex: 0, currentCount: 0... } }

io.on('connection', (socket) => {
    
    // 1. Send list of active sessions to anyone joining the lobby
    socket.emit('sessionList', Object.keys(sessions).map(id => ({ id, name: sessions[id].name })));

    // 2. CREATE SESSION (Admin)
    socket.on('createSession', (sessionName) => {
        const sessionId = "room_" + Math.random().toString(36).substr(2, 9);
        
        sessions[sessionId] = {
            name: sessionName || "Khatm Session",
            currentIndex: 0,
            currentCount: 0,
            isFinished: false
        };

        socket.join(sessionId);
        socket.emit('joinedSession', { sessionId, isAdmin: true, state: getSessionState(sessionId) });
        
        // Broadcast new session list to everyone in lobby
        io.emit('sessionList', Object.keys(sessions).map(id => ({ id, name: sessions[id].name })));
    });

    // 3. JOIN SESSION (Reciter)
    socket.on('joinSession', (sessionId) => {
        if (sessions[sessionId]) {
            socket.join(sessionId);
            socket.emit('joinedSession', { sessionId, isAdmin: false, state: getSessionState(sessionId) });
        }
    });

    // 4. GAME LOGIC (Scoped to Room)
    socket.on('increment', (sessionId) => {
        const session = sessions[sessionId];
        if (!session) return;

        const currentTarget = masterZikrList[session.currentIndex].target;
        if (session.currentCount < currentTarget) {
            session.currentCount++;
            if (session.currentCount >= currentTarget) {
                session.isFinished = true;
            }
            io.to(sessionId).emit('updateState', getSessionState(sessionId));
        }
    });

    socket.on('nextZikr', (sessionId) => {
        const session = sessions[sessionId];
        if (!session) return;

        if (session.currentIndex < masterZikrList.length - 1) {
            session.currentIndex++;
            session.currentCount = 0;
            session.isFinished = false;
            io.to(sessionId).emit('updateState', getSessionState(sessionId));
        } else {
            io.to(sessionId).emit('sessionComplete', "Subhanallah you have successfully completed Khatm-e-Qadriya");
        }
    });

    socket.on('resetCurrent', (sessionId) => {
        const session = sessions[sessionId];
        if (!session) return;
        
        session.currentCount = 0;
        session.isFinished = false;
        io.to(sessionId).emit('updateState', getSessionState(sessionId));
    });

    socket.on('restartSession', (sessionId) => {
        const session = sessions[sessionId];
        if (!session) return;

        session.currentIndex = 0;
        session.currentCount = 0;
        session.isFinished = false;
        io.to(sessionId).emit('updateState', getSessionState(sessionId));
    });
});

// Helper to format state for client
function getSessionState(sessionId) {
    const session = sessions[sessionId];
    return {
        zikr: masterZikrList[session.currentIndex],
        currentCount: session.currentCount,
        target: masterZikrList[session.currentIndex].target,
        isFinished: session.isFinished,
        sessionName: session.name
    };
}

const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});