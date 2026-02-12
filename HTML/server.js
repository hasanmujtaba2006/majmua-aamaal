const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const path = require('path');
const fs = require('fs');

// --- SAFETY NET: PREVENT CRASHES ---
process.on('uncaughtException', (err) => {
    console.error('CRITICAL ERROR:', err);
});

const app = express();
const server = http.createServer(app);

const io = new Server(server, {
    cors: { origin: "*", methods: ["GET", "POST"] },
    transports: ['websocket', 'polling']
});

// --- SMART FOLDER DETECTION ---
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

if (staticPath) {
    app.use(express.static(staticPath));
    console.log(`Serving files from: ${staticPath}`);
} else {
    console.log("WARNING: Index.html not found in standard folders.");
}

let sessions = {}; 

// --- FULL TEXTS FOR READING MODE ---

[cite_start]// Surah Yaseen (Extracted from your PDF) [cite: 73, 82, 85, 91, 98, 104, 111, 117]
const surahYaseenText = `بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ
يس ۝ وَالْقُرْآنِ الْحَكِيمِ ۝ إِنَّكَ لَمِنَ الْمُرْسَلِينَ ۝ عَلَىٰ صِرَاطٍ مُّسْتَقِيمٍ ۝ تَنزِيلَ الْعَزِيزِ الرَّحِيمِ ۝ لِتُنذِرَ قَوْمًا مَّا أُنذِرَ آبَاؤُهُمْ فَهُمْ غَافِلُونَ ۝ لَقَدْ حَقَّ الْقَوْلُ عَلَىٰ أَكْثَرِهِمْ فَهُمْ لَا يُؤْمِنُونَ ۝ إِنَّا جَعَلْنَا فِي أَعْنَاقِهِمْ أَغْلَالًا فَهِيَ إِلَى الْأَذْقَانِ فَهُم مُّقْمَحُونَ ۝ وَجَعَلْنَا مِن بَيْنِ أَيْدِيهِمْ سَدًّا وَمِنْ خَلْفِهِمْ سَدًّا فَأَغْشَيْنَاهُمْ فَهُمْ لَا يُبْصِرُونَ ۝ وَسَوَاءٌ عَلَيْهِمْ أَأَنذَرْتَهُمْ أَمْ لَمْ تُنذِرْهُمْ لَا يُؤْمِنُونَ ۝ إِنَّمَا تُنذِرُ مَنِ اتَّبَعَ الذِّكْرَ وَخَشِيَ الرَّحْمَٰنَ بِالْغَيْبِ ۖ فَبَشِّرْهُ بِمَغْفِرَةٍ وَأَجْرٍ كَرِيمٍ ۝ إِنَّا نَحْنُ نُحْيِي الْمَوْتَىٰ وَنَكْتُبُ مَا قَدَّمُوا وَآثَارَهُمْ ۚ وَكُلَّ شَيْءٍ أَحْصَيْنَاهُ فِي إِمَامٍ مُّبِينٍ ۝

وَاضْرِبْ لَهُم مَّثَلًا أَصْحَابَ الْقَرْيَةِ إِذْ جَاءَهَا الْمُرْسَلُونَ ۝ إِذْ أَرْسَلْنَا إِلَيْهِمُ اثْنَيْنِ فَكَذَّبُوهُمَا فَعَزَّزْنَا بِثَالِثٍ فَقَالُوا إِنَّا إِلَيْكُم مُّرْسَلُونَ ۝ قَالُوا مَا أَنتُمْ إِلَّا بَشَرٌ مِّثْلُنَا وَمَا أَنزَلَ الرَّحْمَٰنُ مِن شَيْءٍ إِنْ أَنتُمْ إِلَّا تَكْذِبُونَ ۝ قَالُوا رَبُّنَا يَعْلَمُ إِنَّا إِلَيْكُمْ لَمُرْسَلُونَ ۝ وَمَا عَلَيْنَا إِلَّا الْبَلَاغُ الْمُبِينُ ۝ قَالُوا إِنَّا تَطَيَّرْنَا بِكُمْ ۖ لَئِن لَّمْ تَنتَهُوا لَنَرْجُمَنَّكُمْ وَلَيَمَسَّنَّكُم مِّنَّا عَذَابٌ أَلِيمٌ ۝ قَالُوا طَائِرُكُم مَّعَكُمْ ۚ أَئِن ذُكِّرْتُم ۚ بَلْ أَنتُمْ قَوْمٌ مُّسْرِفُونَ ۝ وَجَاءَ مِنْ أَقْصَى الْمَدِينَةِ رَجُلٌ يَسْعَىٰ قَالَ يَا قَوْمِ اتَّبِعُوا الْمُرْسَلِينَ ۝ اتَّبِعُوا مَن لَّا يَسْأَلُكُمْ أَجْرًا وَهُم مُّهْتَدُونَ ۝ وَمَا لِيَ لَا أَعْبُدُ الَّذِي فَطَرَنِي وَإِلَيْهِ تُرْجَعُونَ ۝ أَأَتَّخِذُ مِن دُونِهِ آلِهَةً إِن يُرِدْنِ الرَّحْمَٰنُ بِضُرٍّ لَّا تُغْنِ عَنِّي شَفَاعَتُهُمْ شَيْئًا وَلَا يُنقِذُونِ ۝ إِنِّي إِذًا لَّفِي ضَلَالٍ مُّبِينٍ ۝ إِنِّي آمَنتُ بِرَبِّكُمْ فَاسْمَعُونِ ۝ قِيلَ ادْخُلِ الْجَنَّةَ ۖ قَالَ يَا لَيْتَ قَوْمِي يَعْلَمُونَ ۝ بِمَا غَفَرَ لِي رَبِّي وَجَعَلَنِي مِنَ الْمُكْرَمِينَ ۝

وَمَا أَنزَلْنَا عَلَىٰ قَوْمِهِ مِن بَعْدِهِ مِن جُندٍ مِّنَ السَّمَاءِ وَمَا كُنَّا مُنزِلِينَ ۝ إِن كَانَتْ إِلَّا صَيْحَةً وَاحِدَةً فَإِذَا هُمْ خَامِدُونَ ۝ يَا حَسْرَةً عَلَى الْعِبَادِ ۚ مَا يَأْتِيهِم مِّن رَّسُولٍ إِلَّا كَانُوا بِهِ يَسْتَهْزِئُونَ ۝ أَلَمْ يَرَوْا كَمْ أَهْلَكْنَا قَبْلَهُم مِّنَ الْقُرُونِ أَنَّهُمْ إِلَيْهِمْ لَا يَرْجِعُونَ ۝ وَإِن كُلٌّ لَّمَّا جَمِيعٌ لَّدَيْنَا مُحْضَرُونَ ۝ وَآيَةٌ لَّهُمُ الْأَرْضُ الْمَيْتَةُ أَحْيَيْنَاهَا وَأَخْرَجْنَا مِنْهَا حَبًّا فَمِنْهُ يَأْكُلُونَ ۝ وَجَعَلْنَا فِيهَا جَنَّاتٍ مِّن نَّخِيلٍ وَأَعْنَابٍ وَفَجَّرْنَا فِيهَا مِنَ الْعُيُونِ ۝ لِيَأْكُلُوا مِن ثَمَرِهِ وَمَا عَمِلَتْهُ أَيْدِيهِمْ ۖ أَفَلَا يَشْكُرُونَ ۝ سُبْحَانَ الَّذِي خَلَقَ الْأَزْوَاجَ كُلَّهَا مِمَّا تُنبِتُ الْأَرْضُ وَمِنْ أَنفُسِهِمْ وَمِمَّا لَا يَعْلَمُونَ ۝

وَآيَةٌ لَّهُمُ اللَّيْلُ نَسْلَخُ مِنْهُ النَّهَارَ فَإِذَا هُم مُّظْلِمُونَ ۝ وَالشَّمْسُ تَجْرِي لِمُسْتَقَرٍّ لَّهَا ۚ ذَٰلِكَ تَقْدِيرُ الْعَزِيزِ الْعَلِيمِ ۝ وَالْقَمَرَ قَدَّرْنَاهُ مَنَازِلَ حَتَّىٰ عَادَ كَالْعُرْجُونِ الْقَدِيمِ ۝ لَا الشَّمْسُ يَنبَغِي لَهَا أَن تُدْرِكَ الْقَمَرَ وَلَا اللَّيْلُ سَابِقُ النَّهَارِ ۚ وَكُلٌّ فِي فَلَكٍ يَسْبَحُونَ ۝ وَآيَةٌ لَّهُمْ أَنَّا حَمَلْنَا ذُرِّيَّتَهُمْ فِي الْفُلْكِ الْمَشْحُونِ ۝ وَخَلَقْنَا لَهُم مِّن مِّثْلِهِ مَا يَرْكَبُونَ ۝ وَإِن نَّشَأْ نُغْرِقْهُمْ فَلَا صَرِيخَ لَهُمْ وَلَا هُمْ يُنقَذُونَ ۝ إِلَّا رَحْمَةً مِّنَّا وَمَتَاعًا إِلَىٰ حِينٍ ۝ وَإِذَا قِيلَ لَهُمُ اتَّقُوا مَا بَيْنَ أَيْدِيكُمْ وَمَا خَلْفَكُمْ لَعَلَّكُمْ تُرْحَمُونَ ۝ وَمَا تَأْتِيهِم مِّنْ آيَةٍ مِّنْ آيَاتِ رَبِّهِمْ إِلَّا كَانُوا عَنْهَا مُعْرِضِينَ ۝

وَإِذَا قِيلَ لَهُمْ أَنفِقُوا مِمَّا رَزَقَكُمُ اللَّهُ قَالَ الَّذِينَ كَفَرُوا لِلَّذِينَ آمَنُوا أَنُطْعِمُ مَن لَّوْ يَشَاءُ اللَّهُ أَطْعَمَهُ إِنْ أَنتُمْ إِلَّا فِي ضَلَالٍ مُّبِينٍ ۝ وَيَقُولُونَ مَتَىٰ هَٰذَا الْوَعْدُ إِن كُنتُمْ صَادِقِينَ ۝ مَا يَنظُرُونَ إِلَّا صَيْحَةً وَاحِدَةً تَأْخُذُهُمْ وَهُمْ يَخِصِّمُونَ ۝ فَلَا يَسْتَطِيعُونَ تَوْصِيَةً وَلَا إِلَىٰ أَهْلِهِمْ يَرْجِعُونَ ۝ وَنُفِخَ فِي الصُّورِ فَإِذَا هُم مِّنَ الْأَجْدَاثِ إِلَىٰ رَبِّهِمْ يَنسِلُونَ ۝ قَالُوا يَا وَيْلَنَا مَن بَعَثَنَا مِن مَّرْقَدِنَا ۜ ۗ هَٰذَا مَا وَعَدَ الرَّحْمَٰنُ وَصَدَقَ الْمُرْسَلُونَ ۝ إِن كَانَتْ إِلَّا صَيْحَةً وَاحِدَةً فَإِذَا هُمْ جَمِيعٌ لَّدَيْنَا مُحْضَرُونَ ۝ فَالْيَوْمَ لَا تُظْلَمُ نَفْسٌ شَيْئًا وَلَا تُجْزَوْنَ إِلَّا مَا كُنتُمْ تَعْمَلُونَ ۝

إِنَّ أَصْحَابَ الْجَنَّةِ الْيَوْمَ فِي شُغُلٍ فَاكِهُونَ ۝ هُمْ وَأَزْوَاجُهُمْ فِي ظِلَالٍ عَلَى الْأَرَائِكِ مُتَّكِئُونَ ۝ لَهُمْ فِيهَا فَاكِهَةٌ وَلَهُم مَّا يَدَّعُونَ ۝ سَلَامٌ قَوْلًا مِّن رَّبٍّ رَّحِيمٍ ۝ وَامْتَازُوا الْيَوْمَ أَيُّهَا الْمُجْرِمُونَ ۝ أَلَمْ أَعْهَدْ إِلَيْكُمْ يَا بَنِي آدَمَ أَن لَّا تَعْبُدُوا الشَّيْطَانَ ۖ إِنَّهُ لَكُمْ عَدُوٌّ مُّبِينٌ ۝ وَأَنِ اعْبُدُونِي ۚ هَٰذَا صِرَاطٌ مُّسْتَقِيمٌ ۝ وَلَقَدْ أَضَلَّ مِنكُمْ جِبِلًّا كَثِيرًا ۖ أَفَلَمْ تَكُونُوا تَعْقِلُونَ ۝ هَٰذِهِ جَهَنَّمُ الَّتِي كُنتُمْ تُوعَدُونَ ۝ اصْلَوْهَا الْيَوْمَ بِمَا كُنتُمْ تَكْفُرُونَ ۝ الْيَوْمَ نَخْتِمُ عَلَىٰ أَفْوَاهِهِمْ وَتُكَلِّمُنَا أَيْدِيهِمْ وَتَشْهَدُ أَرْجُلُهُم بِمَا كَانُوا يَكْسِبُونَ ۝ وَلَوْ نَشَاءُ لَطَمَسْنَا عَلَىٰ أَعْيُنِهِمْ فَاسْتَبَقُوا الصِّرَاطَ فَأَنَّىٰ يُبْصِرُونَ ۝ وَلَوْ نَشَاءُ لَمَسَخْنَاهُمْ عَلَىٰ مَكَانَتِهِمْ فَمَا اسْتَطَاعُوا مُضِيًّا وَلَا يَرْجِعُونَ ۝

وَمَن نُّعَمِّرْهُ نُنَكِّسْهُ فِي الْخَلْقِ ۖ أَفَلَا يَعْقِلُونَ ۝ وَمَا عَلَّمْنَاهُ الشِّعْرَ وَمَا يَنبَغِي لَهُ ۚ إِنْ هُوَ إِلَّا ذِكْرٌ وَقُرْآنٌ مُّبِينٌ ۝ لِّيُنذِرَ مَن كَانَ حَيًّا وَيَحِقَّ الْقَوْلُ عَلَى الْكَافِرِينَ ۝ أَوَلَمْ يَرَوْا أَنَّا خَلَقْنَا لَهُم مِّمَّا عَمِلَتْ أَيْدِينَا أَنْعَامًا فَهُمْ لَهَا مَالِكُونَ ۝ وَذَلَّلْنَاهَا لَهُمْ فَمِنْهَا رَكُوبُهُمْ وَمِنْهَا يَأْكُلُونَ ۝ وَلَهُمْ فِيهَا مَنَافِعُ وَمَشَارِبُ ۖ أَفَلَا يَشْكُرُونَ ۝ وَاتَّخَذُوا مِن دُونِ اللَّهِ آلِهَةً لَّعَلَّهُمْ يُنصَرُونَ ۝ لَا يَسْتَطِيعُونَ نَصْرَهُمْ وَهُمْ لَهُمْ جُندٌ مُّحْضَرُونَ ۝ فَلَا يَحْزُنكَ قَوْلُهُمْ ۘ إِنَّا نَعْلَمُ مَا يُسِرُّونَ وَمَا يُعْلِنُونَ ۝ أَوَلَمْ يَرَ الْإِنسَانُ أَنَّا خَلَقْنَاهُ مِن نُّطْفَةٍ فَإِذَا هُوَ خَصِيمٌ مُّبِينٌ ۝ وَضَرَبَ لَنَا مَثَلًا وَنَسِيَ خَلْقَهُ ۖ قَالَ مَن يُحْيِي الْعِظَامَ وَهِيَ رَمِيمٌ ۝ قُلْ يُحْيِيهَا الَّذِي أَنشَأَهَا أَوَّلَ مَرَّةٍ ۖ وَهُوَ بِكُلِّ خَلْقٍ عَلِيمٌ ۝ الَّذِي جَعَلَ لَكُم مِّنَ الشَّجَرِ الْأَخْضَرِ نَارًا فَإِذَا أَنتُم مِّنْهُ تُوقِدُونَ ۝ أَوَلَيْسَ الَّذِي خَلَقَ السَّمَاوَاتِ وَالْأَرْضَ بِقَادِرٍ عَلَىٰ أَن يَخْلُقَ مِثْلَهُم ۚ بَلَىٰ وَهُوَ الْخَلَّاقُ الْعَلِيمُ ۝ إِنَّمَا أَمْرُهُ إِذَا أَرَادَ شَيْئًا أَن يَقُولَ لَهُ كُن فَيَكُونُ ۝ فَسُبْحَانَ الَّذِي بِيَدِهِ مَلَكُوتُ كُلِّ شَيْءٍ وَإِلَيْهِ تُرْجَعُونَ`;

const qaseedaText = `سَقَانِي الْحُبُّ كَأْسَاتِ الْوِصَالِ 
 فَقُلْتُ لِخَمْرَتِي نَحْوِي تَعَالِي

سَعَتْ وَمَشَتْ لِنَحْوِي فِي كُئُوسٍ 
 فَهِمْتُ لِسُكْرَتِي بَيْنَ الْمَوَالِي

فَقُلْتُ لِسَائِرِ الْأَقْطَابِ لُمُّوا 
 بِحَالِي وَادْخُلُوا أَنْتُمْ رِجَالِي

وَهُمُّوا وَاشْرَبُوا أَنْتُمْ جُنُودِي 
 فَسَاقِي الْقَوْمِ بِالْوَافِي الْمَلَالِي

شَرِبْتُمْ فَضْلَتِي مِنْ بَعْدِ سُكْرِي 
 وَلَا نِلْتُمْ عُلُوِّي وَاتِّصَالِي

مَقَامُكُمُ الْعُلَا جَمْعًا وَلَكِنْ 
 مَقَامِي فَوْقَكُمْ مَا زَالَ عَالِي

أَنَا فِي حَضْرَةِ التَّقْرِيبِ وَحْدِي 
 يُصَرِّفُنِي وَحَسْبِي ذُو الْجَلَالِ

أَنَا الْبَازِيُّ أَشْهَبُ كُلِّ شَيْخٍ 
 وَمَنْ ذَا فِي الرِّجَالِ أُعْطِي مِثَالِي

كَسَانِي خِلْعَةً بِطِرَازِ عَزْمٍ 
 وَتَوَّجَنِي بِتِيجَانِ الْكَمَالِ

وَأَطْلَعَنِي عَلَى سِرٍّ قَدِيمٍ 
 وَقَلَّدَنِي وَأَعْطَانِي سُؤَالِي

وَلَانِي عَلَى الْأَقْطَابِ جَمْعًا 
 فَحُكْمِي نَافِذٌ فِي كُلِّ حَالِ

فَلَوْ أَلْقَيْتُ سِرِّي فِي بِحَارٍ 
 لَصَارَ الْكُلُّ غَوْرًا فِي الزَّوَالِ

وَلَوْ أَلْقَيْتُ سِرِّي فِي جِبَالٍ 
 لَدُكَّتْ وَاخْتَفَتْ بَيْنَ الرِّمَالِ

وَلَوْ أَلْقَيْتُ سِرِّي فَوْقَ نَارٍ 
 لَخَمِدَتْ وَانْطَفَتْ مِنْ سِرِّ حَالِي

وَلَوْ أَلْقَيْتُ سِرِّي فَوْقَ مَيْتٍ 
 لَقَامَ بِقُدْرَةِ الْمَوْلَى تَعَالَى

وَمَا مِنْهَا شُهُورٌ أَوْ دُهُورٌ 
 تَمُرُّ وَتَنْقَضِي إِلَّا أَتَى لِي

وَتُخْبِرُنِي بِمَا يَأْتِي وَيَجْرِي 
 وَتُعْلِمُنِي فَأَقْصِرْ عَنْ جِدَالِي

مُرِيدِي هَمَّ وَطِبْ وَاشْطَحْ وَغَنِّ 
 وَافْعَلْ مَا تَشَا فَالْإِسْمُ عَالِي

مُرِيدِي لَا تَخَفْ اللَّهُ رَبِّي 
 عَطَانِي رِفْعَةً نِلْتُ الْمَنَالِ

مُرِيدِي لَا تَخَفْ وَاشٍ فَإِنِّي 
 عَزُومٌ قَاتِلٌ عِنْدَ الْقِتَالِ

طُبُولِي فِي السَّمَا وَالْأَرْضِ دُقَّتْ 
 وَشَاؤُسُ السَّعَادَةِ قَدْ بَدَا لِي

بِلَادُ اللَّهِ مُلْكِي تَحْتَ حُكْمِي 
 وَوَقْتِي قَبْلَ قَلْبِي قَدْ صَفَا لِي

نَظَرْتُ إِلَى بِلَادِ اللَّهِ جَمْعًا 
 كَخَرْدَلَةٍ عَلَى حُكْمِ اتِّصَالِ

وَكُلُّ وَلِيٍّ لَهُ قَدَمٌ وَإِنِّي 
 عَلَى قَدَمِ النَّبِيِّ بَدْرِ الْكَمَالِ

دَرَسْتُ الْعِلْمَ حَتَّى صِرْتُ قُطْبًا 
 وَنِلْتُ السَّعْدَ مِنْ مَوْلَى الْمَوَالِي

رِجَالِي فِي هَوَاجِرِهِمْ صِيَامٌ 
 وَفِي ظُلَمِ اللَّيَالِي كَاللَّآلِي

أَنَا الْحَسَنِيُّ وَالْمُخْدَعْ مَقَامِي 
 وَأَقْدَامِي عَلَى عُنُقِ الرِّجَالِ

أَنَا الْجِيلِيُّ مُحْيِي الدِّينِ إِسْمِي 
 وَأَعْلَامِي عَلَى رَأْسِ الْجِبَالِ

وَعَبْدُ الْقَادِرِ الْمَشْهُورُ إِسْمِي 
 وَجَدِّي صَاحِبُ الْعَيْنِ الْكَمَالِ`;

// --- UPDATED ZIKR LIST ---
const zikrData = [
    // 1. Durood 
    { 
        id: 1, type: 'count', target: 111, 
        titleUrdu: "درود شریف", titleEng: "Durood Shareef", 
        bodyText: "اللّٰهُمَّ صَلِّ عَلٰی سَیِّدِنَا وَنَبِیِّنَا وَمَوْلَانَا مُحَمَّدٍ مَعْدِنِ الْجُوْدِوَالْکَرَمِ وَآلِهِ الْکِرَامِ وَابْنِہِ الْکَرِیْمِ وَبَارِكْ وَسَلِّمْ", 
        font: 'arabic' 
    },
    // 2. Teesra Kalma
    { 
        id: 2, type: 'count', target: 111, 
        titleUrdu: "تیسرا کلمہ", titleEng: "Teesra Kalma", 
        bodyText: "سُبْحَانَ اللَّهِ وَالْحَمْدُ لِلَّهِ وَلَا إِلَٰهَ إِلَّا اللَّهُ وَاللَّهُ أَكْبَرُ وَلَا حَوْلَ وَلَا قُوَّةَ إِلَّا بِاللَّهِ الْعَلِيِّ الْعَظِيمِ", 
        font: 'arabic' 
    },
    // 3. Alam Nashrah
    { 
        id: 3, type: 'count', target: 111, 
        titleUrdu: "سورة ألم نشرح", titleEng: "Surah Alam Nashrah", 
        bodyText: "أَلَمْ نَشْرَحْ لَكَ صَدْرَكَ ۝ وَوَضَعْنَا عَنكَ وَزْرَكَ ۝ الَّذِي أَنقَضَ ظَهْرَكَ ۝ وَرَفَعْنَا لَكَ ذِكْرَكَ ۝ فَإِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ إِنَّ مَعَ الْعُسْرِ يُسْرًا ۝ فَإِذَا فَرَغْتَ فَانصَبْ ۝ وَإِلَىٰ رَبِّكَ فَارْغَب ۝", 
        font: 'arabic' 
    },
    // 4. Surah Ikhlas
    { 
        id: 4, type: 'count', target: 111, 
        titleUrdu: "سورة الإخلاص", titleEng: "Surah Ikhlas", 
        bodyText: "قُلْ هُوَ اللَّهُ أَحَدٌ ۝ اللَّهُ الصَّمَدُ ۝ لَمْ يَلِدْ وَلَمْ يُولَدْ ۝ وَلَمْ يَكُن لَّهُ كُفُوًا أَحَدٌ ۝", 
        font: 'arabic' 
    },
    // 5. Isma-e-Husna Part 1
    { 
        id: 5, type: 'count', target: 111, 
        titleUrdu: "أسماء الله الحسنى", titleEng: "Isma-e-Husna", 
        bodyText: "يَا بَاقِي أَنْتَ الْبَاقِي", 
        font: 'arabic' 
    },
    // 6. Isma-e-Husna Part 2
    { 
        id: 6, type: 'count', target: 111, 
        titleUrdu: "أسماء الله الحسنى", titleEng: "Isma-e-Husna", 
        bodyText: "يَا شَافِي أَنْتَ الشَّافِي", 
        font: 'arabic' 
    },
    // 7. Isma-e-Husna Part 3
    { 
        id: 7, type: 'count', target: 111, 
        titleUrdu: "أسماء الله الحسنى", titleEng: "Isma-e-Husna", 
        bodyText: "يَا كَافِي أَنْتَ الْكَافِي", 
        font: 'arabic' 
    },
    // 8. Istighatha
    { 
        id: 8, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا رَسُولَ اللَّهِ اُنْظُرْ حَالَنَا \n يَا حَبِيْبَ اللَّهِ اِسْمَعْ قَالَنَا \n اِنَّنِي فِي بَحْرِ هَمٍّ مُّغْرَقٌ \n خُذْ يَدِي سَهِّلْ لَنَا اَشْكَالَنَا", 
        font: 'arabic' 
    },
    // 9. Istighatha
    { 
        id: 9, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا حَبِيْبَ الْإِلَهِ خُذْ بِيَدِي \n مَا لِعَجْزِي سِوَاكَ مُسْتَنَدِي", 
        font: 'arabic' 
    },
    // 10. Istighatha
    { 
        id: 10, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "فَسَهِّلْ يَا إِلَهِي كُلَّ صَعْبٍ \n بِحُرْمَةِ سَيِّدِ الْأَبْرَارِ سَهِّلْ", 
        font: 'arabic' 
    },
    // 11. Istighatha
    { 
        id: 11, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا صِدِّيقُ يَا عُمَرُ \n يَا عُثْمَانُ يَا حَيْدَرُ \n دَفْعِ شَر كُنْ خَيْرَ آوَرْ \n يَا شَبِيْرُ يَا شَبَرْ", 
        font: 'arabic' 
    },
    // 12. Istighatha
    { 
        id: 12, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا حَضْرَتِ سُلْطَانِ شَيْخ سَيِّد شَاه \n عَبْدَ الْقَادِرِ جِيلَانِي شَيْئًا لِلَّهِ \n الْمَدَدْ", 
        font: 'arabic' 
    },
    // 13. Istighatha
    { 
        id: 13, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "ما ہمہ محتاج تو حاجت روا \n الَمدَد یا غوثِ اعظم سیّدا", 
        font: 'urdu' 
    },
    // 14. Istighatha
    { 
        id: 14, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "مشکلاتِ بے عدد داریم ما \n الَمدَد یا غوثِ اعظم پیرا ما", 
        font: 'urdu' 
    },
    // 15. Istighatha
    { 
        id: 15, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا حَضْرَتِ شَيْخ \n مُحْيِ الدِّينِ مُشْكِلْ كُشَا بِالْخَيْر", 
        font: 'arabic' 
    },
    // 16. Istighatha
    { 
        id: 16, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "امداد کن امداد کن \n از بندِ غم آزاد کن \n در دین و دنیا شاد کن \n یا غوثِ اعظم دستگیر", 
        font: 'urdu' 
    },
    // 17. Istighatha
    { 
        id: 17, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "يَا حَضْرَتِ غَوْث \n أَغِثْنَا بِإِذْنِ اللَّهِ تَعَالَى", 
        font: 'arabic' 
    },
    // 18. Istighatha
    { 
        id: 18, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "خُذْ يَدِي يَا شَاهِ جِيْلَاں خُذْ يَدِي \n شَيْئًا لِلَّهِ أَنْتَ نُوْرٌ أَحْمَدِي", 
        font: 'arabic' 
    },
    // 19. Istighatha
    { 
        id: 19, type: 'count', target: 111, 
        titleUrdu: "استغاثہ", titleEng: "Istighatha", 
        bodyText: "طفیل حضرت دستگیر \n دشمن ہووے زیر", 
        font: 'urdu' 
    },
    // 20. Surah Yaseen
    { 
        id: 20, type: 'read', target: 1, 
        titleUrdu: "سورۃ یٰسین", titleEng: "Surah Yaseen", 
        bodyText: surahYaseenText, 
        font: 'arabic'
    },
    // 21. Qaseeda Ghausia
    { 
        id: 21, type: 'read', target: 1, 
        titleUrdu: "قصیدہ غوثیہ", titleEng: "Qaseeda Ghausia", 
        bodyText: qaseedaText, 
        font: 'arabic'
    },
    // 22. Durood
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