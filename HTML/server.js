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

// --- DATA: Zikr List (Formatted with Titles & Flags) ---
const zikrList = [
    {
        // 1
        arabic: "۱- دُرُودِغوثیہ\nاللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِوَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ",
        roman: "1. Durood Ghousia:\nAllahumma Salli 'Ala Sayyidina Wa Nabiyyina Wa Mawlana Muhammadin Ma'dinil Judi Wal Karami...",
        target: 111
    },
    {
        // 2
        arabic: "۲- تیسرا کلمہ\nسُبْحَانَ اللّٰہِ وَالْحَمْدُ لِلّٰہِ وَلَا اِلٰهَ اِلَّا اللّٰہُ وَاللّٰہُ اَکْبَرُ وَلَا حَوْلَ وَلَا قُوَّةَ اِلَّابِاللّٰہِ الْعَلِیِّ الْعَظِیْمِ",
        roman: "2. Third Kalima:\nSubhanAllahi Wal Hamdu Lillahi Wa La Ilaha Illallahu Wallahu Akbar...",
        target: 111
    },
    {
        // 3
        arabic: "۳- سور ہ الم نشرح\nاَلَمْ نَشْرَحْ لَكَ صَدْرَكَ ۝ وَوَضَعْنَا عَنكَ وِزْرَكَ ۝ الَّذِىْۤ أَنقَضَ ظَهْرَكَ ۝وَرَفَعْنَا لَكَ ذِكْرَكَ ۝ فَإِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ إِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ فَإِذَا فَرَغْتَ فَانْصَبْ ۝ وَإِلَىٰ رَبِّكَ فَارْغَبْ",
        roman: "3. Surah Alam Nashrah (Recite Full Surah):\nAlam Nashrah Laka Sadrak...",
        target: 111
    },
    {
        // 4
        arabic: "۴- سورہ اِخلاص\nقُلْ هُوَ اللّٰهُ أَحَدٌ ۝ اَللّٰهُ الصَّمَدُ ۝ لَمْ يَلِدْ وَلَمْ يُولَدْ ۝ وَلَمْ يَكُن لَّهُ كُفُوًا أَحَدٌ",
        roman: "4. Surah Ikhlas (Recite Full Surah):\nQul Huwa Allahu Ahad...",
        target: 111
    },
    {
        // 5
        arabic: "۵- اَسْمَاءُ الْحُسْنٰی\nیَا بَاقِی اَنْتَ الْبَاقِی \n یَا شَافِی اَنْتَ الشَّافِی \n یَا کَافِی اَنْتَ الْکَافِی",
        roman: "5. Asma-ul-Husna:\nYa Baqi Antal Baqi, Ya Shafi Antal Shafi, Ya Kafi Antal Kafi",
        target: 111
    },
    {
        // 6
        arabic: "۶- اِسْتِغَاثَہ\nیَا رَسُوْلَ اللّٰہِ اُنْظُرْ حَالَنَا \n یَا حَبِیْبَ اللّٰہِ اِسْمَعْ قَالَنَا \n اِنَّنِی فِی بَحْرِ ھَمٍّ مُّغْرَقٌ \n خُذْ یَدِی سَہِّلْ لَنَا اَشْکَالَنَا",
        roman: "6. Istighasah:\nYa Rasulallahi Unzur Halana, Ya Habibal Lahi Isma' Qalana...",
        target: 111
    },
    {
        // 7
        arabic: "۷- اِسْتِغَاثَہ\nیَا حَبِیْبَ الْاِلٰـہِ خُذْ بِیَدِیْ \n مَا لِعَجْزِیْ سِوَاکَ مُسْتَنَدِیْ",
        roman: "7. Istighasah:\nYa Habibal Ilahi Khuz Biyadi, Ma Li'ajzi Siwaka Mustanadi",
        target: 111
    },
    {
        // 8
        arabic: "۸- اِسْتِغَاثَہ\nفَسَهِّلْ یَا اِلٰهِیْ كُلَّ صَعْبٍ \n بِحُرْمَةِ سَیِّدِ الْاَبْرَارِ سَهِّلْ",
        roman: "8. Istighasah:\nFa Sahhil Ya Ilahi Kulla Sa'bin, Bi Hurmati Sayyidil Abrari Sahhil",
        target: 111
    },
    {
        // 9
        arabic: "۹- اِسْتِغَاثَہ\nیَا صِدِّیْقُ یَا عُمَرْ \n یَا عُثْمَانُ یَا حَیْدَرْ \n دَفْعِ شَرْ کُن خَیْر آوَرْ \n یَا شَبِّیْرُ یَا شَبَّرْ",
        roman: "9. Istighasah:\nYa Siddiqu Ya 'Umar, Ya 'Uthmanu Ya Haydar...",
        target: 111
    },
    {
        // 10
        arabic: "۱۰- اِسْتِغَاثَہ\nیَا حَضْرَتْ سُلْطَانْ شَیْخْ سَیِّدْ شَاهْ عَبْدَ الْقَادِرْ جِیْلَانِیْ شَیْئًا لِلّٰہِ اَلْمَدَدْ",
        roman: "10. Istighasah:\nYa Hazrat Sultan Sheikh Sayyid Shah Abdul Qadir Jilani Shay'an Lillah Al-Madad",
        target: 111
    },
    {
        // 11 (URDU FONT)
        arabic: "۱۱- اِسْتِغَاثَہ\nماہمہ محتاج تو حاجت روا \n المددیا غوث اعظم سیدا",
        roman: "11. Istighasah:\nMa Hama Muhtaje Tu Hajat Rawa, Al-Madad Ya Ghaus-e-Azam Sayyida",
        target: 111,
        isUrdu: true
    },
    {
        // 12 (URDU FONT)
        arabic: "۱۲- اِسْتِغَاثَہ\nمشکلات بے عدد داریم ما \n المدد یا غوث اعظم پیرِ ما",
        roman: "12. Istighasah:\nMushkilat Be 'Adad Dareem Ma, Al-Madad Ya Ghaus-e-Azam Peer-e-Ma",
        target: 111,
        isUrdu: true
    },
    {
        // 13
        arabic: "۱۳- اِسْتِغَاثَہ\nيَا حَضْرَتْ شيْخْ مُحْيَ الدِّيْنْ مُشْكِلْ كُشَا بِالْخَيْر",
        roman: "13. Istighasah:\nYa Hazrat Sheikh Muhyiddin Mushkil Kusha Bil Khair",
        target: 111
    },
    {
        // 14 (URDU FONT)
        arabic: "۱۴- اِسْتِغَاثَہ\nامداد کن امداد کن \n از بندِ غم آزاد کن \n در دین و دنیا شاد کن \n یا غوثِ اعظم دستگیر",
        roman: "14. Istighasah:\nImdad Kun Imdad Kun, Az Band-e-Gham Azad Kun...",
        target: 111,
        isUrdu: true
    },
    {
        // 15 (URDU FONT)
        arabic: "۱۵- اِسْتِغَاثَہ\nیا حَضْرَتْ غَوثْ! اَغِثْنَا بِاذْنِ اللّٰهِ تَعَالٰی",
        roman: "15. Istighasah:\nYa Hazrat Ghaus! Aghithna Bi Izni Llah Ta'ala",
        target: 111,
        isUrdu: true
    },
    {
        // 16
        arabic: "۱۶- اِسْتِغَاثَہ\nخُذْ يَدِيْ يَا شَاہِ جِيلَاں خُذْ يَدِيْ \n شَيئًا للّٰهِ أَنْتَ نُورٌ اَحْمَدِيْ",
        roman: "16. Istighasah:\nKhuz Yadi Ya Shah-e-Jeelan Khuz Yadi, Shay'an Lillah Anta Nurun Ahmadi",
        target: 111
    },
    {
        // 17
        arabic: "۱۷- اِسْتِغَاثَہ\nطفیل حضرت دستگیردشمن ہووےزیر",
        roman: "17. Istighasah:\nTufail-e-Hazrat Dastagir Dushman Howe Zer",
        target: 111
    },
    // Special Section: Surah Yasin & Qasida
    {
        arabic: "تلاوت: سورۃ یٰسین (۱ بار) \n قصیدہ غوثیہ (۱ بار)",
        roman: "Please Recite:\nSurah Yasin (1 time)\nQasida-e-Gausiya (1 time)",
        target: 1,
        type: 'instruction' // Flags frontend to show special UI
    },
    // Final Zikr
    {
        arabic: "۱۹- دُرُودِغوثیہ\nاللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِوَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ",
        roman: "19. Durood Ghousia (Final):\nAllahumma Salli 'Ala Sayyidina Wa Nabiyyina...",
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
    const currentZikr = zikrList[gameState.currentIndex];
    if (currentZikr) {
        socket.emit('updateState', { 
            ...gameState, 
            zikr: currentZikr,
            target: currentZikr.target 
        });
    }

    // Handle Tap
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

    // Handle Admin: Next Zikr
    socket.on('nextZikr', () => {
        if (gameState.currentIndex < zikrList.length - 1) {
            gameState.currentIndex++;
            gameState.currentCount = 0;
            gameState.isFinished = false;
            
            const nextZikr = zikrList[gameState.currentIndex];
            io.emit('updateState', { 
                ...gameState, 
                zikr: nextZikr,
                target: nextZikr.target
            });
        } else {
            // Updated Final Message
            io.emit('sessionComplete', "Subhanallah you have successfully completed Khatm-e-Qadriya");
        }
    });

    // Handle Admin: Reset Current Counter
    socket.on('resetCurrent', () => {
        gameState.currentCount = 0;
        gameState.isFinished = false;
        const currentZikr = zikrList[gameState.currentIndex];
        io.emit('updateState', { 
            ...gameState, 
            zikr: currentZikr,
            target: currentZikr.target
        });
    });

    // Handle Admin: Restart Entire Session
    socket.on('restartSession', () => {
        gameState.currentIndex = 0;
        gameState.currentCount = 0;
        gameState.isFinished = false;
        const firstZikr = zikrList[0];
        io.emit('updateState', { 
            ...gameState, 
            zikr: firstZikr,
            target: firstZikr.target
        });
    });
});

const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});