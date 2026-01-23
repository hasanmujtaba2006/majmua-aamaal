const express = require('express');
const http = require('http');
const { Server } = require("socket.io");
const path = require('path');

const app = express();
const server = http.createServer(app);

// Enable CORS for Render
const io = new Server(server, {
    cors: {
        origin: "*",
        methods: ["GET", "POST"]
    }
});

app.use(express.static(path.join(__dirname, 'public')));

// --- DATA: Zikr List (Arabic & Roman) ---
const zikrList = [
    {
        arabic: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِوَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ",
        roman: "Allahumma Salli Ala Sayyidina Wa Nabiyyina Wa Mawlana Muhammadin Ma'dinil Judi Wal Karami...",
        target: 111
    },
    {
        arabic: "سُبْحَانَ اللّٰہِ وَالْحَمْدُ لِلّٰہِ وَلَا اِلٰهَ اِلَّا اللّٰہُ وَاللّٰہُ اَکْبَرُ وَلَا حَوْلَ وَلَا قُوَّةَ اِلَّابِاللّٰہِ الْعَلِیِّ الْعَظِیْمِ",
        roman: "SubhanAllahi Wal Hamdu Lillahi Wa La Ilaha Illallahu Wallahu Akbar...",
        target: 111
    },
    {
        arabic: "اَلَمْ نَشْرَحْ لَكَ صَدْرَكَ ۝ وَوَضَعْنَا عَنكَ وِزْرَكَ ۝ الَّذِىْۤ أَنقَضَ ظَهْرَكَ ۝وَرَفَعْنَا لَكَ ذِكْرَكَ ۝ فَإِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ إِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ فَإِذَا فَرَغْتَ فَانْصَبْ ۝ وَإِلَىٰ رَبِّكَ فَارْغَبْ",
        roman: "Surah Alam Nashrah (Recite Full Surah)",
        target: 111
    },
    {
        arabic: "قُلْ هُوَ اللّٰهُ أَحَدٌ ۝ اَللّٰهُ الصَّمَدُ ۝ لَمْ يَلِدْ وَلَمْ يُولَدْ ۝ وَلَمْ يَكُن لَّهُ كُفُوًا أَحَدٌ",
        roman: "Surah Ikhlas (Recite Full Surah)",
        target: 111
    },
    {
        arabic: "یَا بَاقِی اَنْتَ الْبَاقِی \n یَا شَافِی اَنْتَ الشَّافِی \n یَا کَافِی اَنْتَ الْکَافِی",
        roman: "Ya Baqi Antal Baqi, Ya Shafi Antal Shafi, Ya Kafi Antal Kafi",
        target: 111
    },
    {
        arabic: "یَا رَسُوْلَ اللّٰہِ اُنْظُرْ حَالَنَا \n یَا حَبِیْبَ اللّٰہِ اِسْمَعْ قَالَنَا \n اِنَّنِی فِی بَحْرِ ھَمٍّ مُّغْرَقٌ \n خُذْ یَدِی سَہِّلْ لَنَا اَشْکَالَنَا",
        roman: "Ya Rasulallahi Unzur Halana, Ya Habibal Lahi Isma' Qalana...",
        target: 111
    },
    {
        arabic: "یَا حَبِیْبَ الْاِلٰـہِ خُذْ بِیَدِیْ \n مَا لِعَجْزِیْ سِوَاکَ مُسْتَنَدِیْ",
        roman: "Ya Habibal Ilahi Khuz Biyadi, Ma Li'ajzi Siwaka Mustanadi",
        target: 111
    },
    {
        arabic: "فَسَهِّلْ یَا اِلٰهِیْ كُلَّ صَعْبٍ \n بِحُرْمَةِ سَیِّدِ الْاَبْرَارِ سَهِّلْ",
        roman: "Fa Sahhil Ya Ilahi Kulla Sa'bin, Bi Hurmati Sayyidil Abrari Sahhil",
        target: 111
    },
    {
        arabic: "یَا صِدِّیْقُ یَا عُمَرْ \n یَا عُثْمَانُ یَا حَیْدَرْ \n دَفْعِ شَرْ کُن خَیْر آوَرْ \n یَا شَبِّیْرُ یَا شَبَّرْ",
        roman: "Ya Siddiqu Ya Umar, Ya Uthmanu Ya Haydar...",
        target: 111
    },
    {
        arabic: "یَا حَضْرَتْ سُلْطَانْ شَیْخْ سَیِّدْ شَاهْ عَبْدَ الْقَادِرْ جِیْلَانِیْ شَیْئًا لِلّٰہِ اَلْمَدَدْ",
        roman: "Ya Hazrat Sultan Sheikh Sayyid Shah Abdul Qadir Jilani Shay'an Lillah Al-Madad",
        target: 111
    },
    {
        arabic: "ماہمہ محتاج تو حاجت روا \n المددیا غوث اعظم سیدا",
        roman: "Ma Hama Muhtaje Tu Hajat Rawa, Al-Madad Ya Ghaus-e-Azam Sayyida",
        target: 111
    },
    {
        arabic: "مشکلات بے عدد داریم ما \n المدد یا غوث اعظم پیرِ ما",
        roman: "Mushkilat Be 'Adad Dareem Ma, Al-Madad Ya Ghaus-e-Azam Peer-e-Ma",
        target: 111
    },
    {
        arabic: "يَا حَضْرَتْ شيْخْ مُحْيَ الدِّيْنْ مُشْكِلْ كُشَا بِالْخَيْر",
        roman: "Ya Hazrat Sheikh Muhyiddin Mushkil Kusha Bil Khair",
        target: 111
    },
    {
        arabic: "امداد کن امداد کن \n از بندِ غم آزاد کن \n در دین و دنیا شاد کن \n یا غوثِ اعظم دستگیر",
        roman: "Imdad Kun Imdad Kun, Az Band-e-Gham Azad Kun...",
        target: 111
    },
    {
        arabic: "یا حَضْرَتْ غَوثْ! اَغِثْنَا بِاذْنِ اللّٰهِ تَعَالٰی",
        roman: "Ya Hazrat Ghaus! Aghithna Bi Izni Llah Ta'ala",
        target: 111
    },
    {
        arabic: "خُذْ يَدِيْ يَا شَاہِ جِيلَاں خُذْ يَدِيْ \n شَيئًا للّٰهِ أَنْتَ نُورٌ اَحْمَدِيْ",
        roman: "Khuz Yadi Ya Shah-e-Jeelan Khuz Yadi, Shay'an Lillah Anta Nurun Ahmadi",
        target: 111
    },
    {
        arabic: "طفیل حضرت دستگیردشمن ہووےزیر",
        roman: "Tufail-e-Hazrat Dastagir Dushman Howe Zer",
        target: 111
    },
    // Message Slide
    {
        arabic: "تلاوت: سورۃ یٰسین (۱ بار) \n قصیدہ غوثیہ (۱ بار)",
        roman: "Please Recite: Surah Yasin (1 time) & Qasida-e-Gausiya (1 time). Tap to continue.",
        target: 1
    },
    // Final Zikr
    {
        arabic: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِوَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ",
        roman: "Allahumma Salli Ala Sayyidina Wa Nabiyyina... (Durood Ghousia)",
        target: 111
    }
];

let gameState = {
    currentIndex: 0,
    currentCount: 0,
    isFinished: false
};

io.on('connection', (socket) => {
    // Send state immediately
    if (zikrList[gameState.currentIndex]) {
        socket.emit('updateState', { 
            ...gameState, 
            zikr: zikrList[gameState.currentIndex],
            target: zikrList[gameState.currentIndex].target 
        });
    }

    socket.on('increment', () => {
        const currentTarget = zikrList[gameState.currentIndex].target;
        if (gameState.currentCount < currentTarget) {
            gameState.currentCount++;
            if (gameState.currentCount >= currentTarget) {
                gameState.isFinished = true;
            }
            io.emit('updateState', { 
                ...gameState, 
                zikr: zikrList[gameState.currentIndex],
                target: currentTarget 
            });
        }
    });

    socket.on('nextZikr', () => {
        if (gameState.currentIndex < zikrList.length - 1) {
            gameState.currentIndex++;
            gameState.currentCount = 0;
            gameState.isFinished = false;
            io.emit('updateState', { 
                ...gameState, 
                zikr: zikrList[gameState.currentIndex],
                target: zikrList[gameState.currentIndex].target
            });
        } else {
            io.emit('sessionComplete', "Khatm Sharif Completed! Dua Time.");
        }
    });

    socket.on('resetCurrent', () => {
        gameState.currentCount = 0;
        gameState.isFinished = false;
        io.emit('updateState', { 
            ...gameState, 
            zikr: zikrList[gameState.currentIndex],
            target: zikrList[gameState.currentIndex].target
        });
    });
});

const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});