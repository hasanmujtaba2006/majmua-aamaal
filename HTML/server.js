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
    { id: "۱", titleUrdu: "دُرُودِ غوثیہ", titleEng: "Durood Ghousia", bodyText: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِ وَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ", bodyRoman: "Allahumma Salli 'Ala Sayyidina Wa Nabiyyina Wa Mawlana Muhammadin Ma'dinil Judi Wal Karami Wa 'Aalihi Al-Kirami Wabnihi Al-Kareemi Wa Barik Wa Sallim", target: 111, isUrduBody: false },
    { id: "۲", titleUrdu: "تیسرا کلمہ", titleEng: "Third Kalima", bodyText: "سُبْحَانَ اللّٰہِ وَالْحَمْدُ لِلّٰہِ وَلَا اِلٰهَ اِلَّا اللّٰہُ وَاللّٰہُ اَکْبَرُ وَلَا حَوْلَ وَلَا قُوَّةَ اِلَّابِاللّٰہِ الْعَلِیِّ الْعَظِیْمِ", bodyRoman: "SubhanAllahi Wal Hamdu Lillahi Wa La Ilaha Illallahu Wallahu Akbar Wa La Hawla Wa La Quwwata Illa Billahil 'Aliyyil 'Azeem", target: 111, isUrduBody: false },
    { id: "۳", titleUrdu: "سور ہ الم نشرح", titleEng: "Surah Alam Nashrah", bodyText: "اَلَمْ نَشْرَحْ لَكَ صَدْرَكَ ۝ وَوَضَعْنَا عَنكَ وِزْرَكَ ۝ الَّذِىْۤ أَنقَضَ ظَهْرَكَ ۝وَرَفَعْنَا لَكَ ذِكْرَكَ ۝ فَإِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ إِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ فَإِذَا فَرَغْتَ فَانْصَبْ ۝ وَإِلَىٰ رَبِّكَ فَارْغَبْ", bodyRoman: "Alam Nashrah Laka Sadrak. Wa Wada'na 'Anka Wizrak. Allazi Anqada Zahrak. Wa Rafa'na Laka Zikrak. Fa Inna Ma'al 'Usri Yusra. Inna Ma'al 'Usri Yusra. Fa Iza Faraghta Fansab. Wa Ila Rabbika Farghab.", target: 111, isUrduBody: false },
    { id: "۴", titleUrdu: "سورہ اِخلاص", titleEng: "Surah Ikhlas", bodyText: "قُلْ هُوَ اللّٰهُ أَحَدٌ ۝ اَللّٰهُ الصَّمَدُ ۝ لَمْ يَلِدْ وَلَمْ يُولَدْ ۝ وَلَمْ يَكُن لَّهُ كُفُوًا أَحَدٌ", bodyRoman: "Qul Huwa Allahu Ahad. Allahu As-Samad. Lam Yalid Wa Lam Yulad. Wa Lam Yakun Lahu Kufuwan Ahad.", target: 111, isUrduBody: false },
    { id: "۵", titleUrdu: "اَسْمَاءُ الْحُسْنٰی", titleEng: "Asma-ul-Husna", bodyText: "یَا بَاقِی اَنْتَ الْبَاقِی", bodyRoman: "Ya Baqi Antal Baqi", target: 111, isUrduBody: false },
    { id: "۶", titleUrdu: "اَسْمَاءُ الْحُسْنٰی", titleEng: "Asma-ul-Husna", bodyText: "یَا شَافِی اَنْتَ الشَّافِی", bodyRoman: "Ya Shafi Antal Shafi", target: 111, isUrduBody: false },
    { id: "۷", titleUrdu: "اَسْمَاءُ الْحُسْنٰی", titleEng: "Asma-ul-Husna", bodyText: "یَا کَافِی اَنْتَ الْکَافِی", bodyRoman: "Ya Kafi Antal Kafi", target: 111, isUrduBody: false },
    { id: "۸", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یَا رَسُوْلَ اللّٰہِ اُنْظُرْ حَالَنَا \n یَا حَبِیْبَ اللّٰہِ اِسْمَعْ قَالَنَا \n اِنَّنِی فِی بَحْرِ ھَمٍّ مُّغْرَقٌ \n خُذْ یَدِی سَہِّلْ لَنَا اَشْکَالَنَا", bodyRoman: "Ya Rasulallahi Unzur Halana \n Ya Habibal Lahi Isma' Qalana \n Innani Fi Bahri Hammin Mughraqun \n Khuz Yadi Sahhil Lana Ashkalana", target: 111, isUrduBody: false },
    { id: "۹", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یَا حَبِیْبَ الْاِلٰـہِ خُذْ بِیَدِیْ \n مَا لِعَجْزِیْ سِوَاکَ مُسْتَنَدِیْ", bodyRoman: "Ya Habibal Ilahi Khuz Biyadi \n Ma Li'ajzi Siwaka Mustanadi", target: 111, isUrduBody: false },
    { id: "۱۰", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "فَسَهِّلْ یَا اِلٰهِیْ كُلَّ صَعْبٍ \n بِحُرْمَةِ سَیِّدِ الْاَبْرَارِ سَهِّلْ", bodyRoman: "Fa Sahhil Ya Ilahi Kulla Sa'bin \n Bi Hurmati Sayyidil Abrari Sahhil", target: 111, isUrduBody: false },
    { id: "۱۱", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یَا صِدِّیْقُ یَا عُمَرْ \n یَا عُثْمَانُ یَا حَیْدَرْ \n دَفْعِ شَرْ کُن خَیْر آوَرْ \n یَا شَبِّیْرُ یَا شَبَّرْ", bodyRoman: "Ya Siddiqu Ya 'Umar \n Ya 'Uthmanu Ya Haydar \n Daf'e Shar Kun Khair Aawar \n Ya Shabbiru Ya Shabbar", target: 111, isUrduBody: false },
    { id: "۱۲", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یَا حَضْرَتْ سُلْطَانْ شَیْخْ سَیِّدْ شَاهْ عَبْدَ الْقَادِرْ جِیْلَانِیْ شَیْئًا لِلّٰہِ اَلْمَدَدْ", bodyRoman: "Ya Hazrat Sultan Sheikh Sayyid Shah Abdul Qadir Jilani Shay'an Lillah Al-Madad", target: 111, isUrduBody: false },
    { id: "۱۳", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "ماہمہ محتاج تو حاجت روا \n المددیا غوث اعظم سیدا", bodyRoman: "Ma Hama Muhtaje Tu Hajat Rawa \n Al-Madad Ya Ghaus-e-Azam Sayyida", target: 111, isUrduBody: true },
    { id: "۱۴", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "مشکلات بے عدد داریم ما \n المدد یا غوث اعظم پیرِ ما", bodyRoman: "Mushkilat Be 'Adad Dareem Ma \n Al-Madad Ya Ghaus-e-Azam Peer-e-Ma", target: 111, isUrduBody: true },
    { id: "۱۵", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "يَا حَضْرَتْ شيْخْ مُحْيَ الدِّيْنْ مُشْكِلْ كُشَا بِالْخَيْر", bodyRoman: "Ya Hazrat Sheikh Muhyiddin Mushkil Kusha Bil Khair", target: 111, isUrduBody: false },
    { id: "۱۶", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "امداد کن امداد کن \n از بندِ غم آزاد کن \n در دین و دنیا شاد کن \n یا غوثِ اعظم دستگیر", bodyRoman: "Imdad Kun Imdad Kun \n Az Band-e-Gham Azad Kun \n Dar Din-o-Dunya Shad Kun \n Ya Ghaus-e-Azam Dastagir", target: 111, isUrduBody: true },
    { id: "۱۷", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "یا حَضْرَتْ غَوثْ! اَغِثْنَا بِاذْنِ اللّٰهِ تَعَالٰی", bodyRoman: "Ya Hazrat Ghaus! Aghithna Bi Izni Llah Ta'ala", target: 111, isUrduBody: true },
    { id: "۱۸", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "خُذْ يَدِيْ يَا شَاہِ جِيلَاں خُذْ يَدِيْ \n شَيئًا للّٰهِ أَنْتَ نُورٌ اَحْمَدِيْ", bodyRoman: "Khuz Yadi Ya Shah-e-Jeelan Khuz Yadi \n Shay'an Lillah Anta Nurun Ahmadi", target: 111, isUrduBody: false },
    { id: "۱۹", titleUrdu: "اِسْتِغَاثَہ", titleEng: "Istighasah", bodyText: "طفیل حضرت دستگیردشمن ہووےزیر", bodyRoman: "Tufail-e-Hazrat Dastagir Dushman Howe Zer", target: 111, isUrduBody: false },
    { id: "!", titleUrdu: "ہدایات", titleEng: "Instructions", bodyText: "تلاوت: سورۃ یٰسین (۱ بار) \n قصیدہ غوثیہ (۱ بار)", bodyRoman: "Please Recite: Surah Yasin (1 time) & Qasida-e-Gausiya (1 time).\nTap to continue when done.", target: 1, type: 'instruction' },
    { id: "۲۱", titleUrdu: "دُرُودِ غوثیہ (آخر)", titleEng: "Durood Ghousia (Final)", bodyText: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِ وَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ", bodyRoman: "Allahumma Salli 'Ala Sayyidina Wa Nabiyyina Wa Mawlana Muhammadin Ma'dinil Judi Wal Karami Wa 'Aalihi Al-Kirami Wabnihi Al-Kareemi Wa Barik Wa Sallim", target: 111, isUrduBody: false }
];

const sessions = {};

io.on('connection', (socket) => {
    
    // Send list
    socket.emit('sessionList', Object.keys(sessions).map(id => ({ id, name: sessions[id].name })));

    // Create Session
    socket.on('createSession', (sessionName) => {
        const sessionId = "room_" + Math.random().toString(36).substr(2, 9);
        sessions[sessionId] = { name: sessionName || "Khatm Session", currentIndex: 0, currentCount: 0, isFinished: false };
        socket.join(sessionId);
        socket.emit('joinedSession', { sessionId, isAdmin: true, state: getSessionState(sessionId) });
        io.emit('sessionList', Object.keys(sessions).map(id => ({ id, name: sessions[id].name })));
    });

    // Join Session (Fixed with re-join support)
    socket.on('joinSession', (sessionId) => {
        if (sessions[sessionId]) {
            socket.join(sessionId);
            socket.emit('joinedSession', { sessionId, isAdmin: false, state: getSessionState(sessionId) });
        } else {
            socket.emit('sessionError', "Session not found or ended.");
        }
    });

    // Re-Join (New Handler for auto-reconnect)
    socket.on('reJoinSession', (sessionId) => {
        if (sessions[sessionId]) {
            socket.join(sessionId);
            // Don't emit joinedSession fully, just ensure room membership
            socket.emit('updateState', getSessionState(sessionId));
        } else {
            socket.emit('sessionError', "Session expired. Please restart.");
        }
    });

    // Increment
    socket.on('increment', (sessionId) => {
        const session = sessions[sessionId];
        if (!session) {
            socket.emit('sessionError', "Session invalid. Reloading...");
            return;
        }

        const currentTarget = masterZikrList[session.currentIndex].target;
        if (session.currentCount < currentTarget) {
            session.currentCount++;
            if (session.currentCount >= currentTarget) {
                session.isFinished = true;
            }
            io.to(sessionId).emit('updateState', getSessionState(sessionId));
        }
    });

    // Next Zikr
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

    // Reset
    socket.on('resetCurrent', (sessionId) => {
        const session = sessions[sessionId];
        if (!session) return;
        session.currentCount = 0;
        session.isFinished = false;
        io.to(sessionId).emit('updateState', getSessionState(sessionId));
    });

    // Restart
    socket.on('restartSession', (sessionId) => {
        const session = sessions[sessionId];
        if (!session) return;
        session.currentIndex = 0;
        session.currentCount = 0;
        session.isFinished = false;
        io.to(sessionId).emit('updateState', getSessionState(sessionId));
    });

    // End Session
    socket.on('endSession', (sessionId) => {
        if (sessions[sessionId]) {
            delete sessions[sessionId];
            io.to(sessionId).emit('forceExit', "Session Ended by Admin.");
            io.emit('sessionList', Object.keys(sessions).map(id => ({ id, name: sessions[id].name })));
        }
    });
});

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