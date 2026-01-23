const express = require('express');
const http = require('http');
const { Server } = require("socket.io");
const path = require('path');

const app = express();
const server = http.createServer(app);

// Enable CORS so the app works on Render
const io = new Server(server, {
    cors: {
        origin: "*",
        methods: ["GET", "POST"]
    }
});

// Serve static files from the 'public' folder
app.use(express.static(path.join(__dirname, 'public')));

// --- DATA & STATE ---
const zikrList = [
    "Durood Sharif (Start) - 111 times",
    "Subhanallahi Wal Hamdu Lillahi... - 111 times",
    "Allahu Akbar - 111 times",
    "Ya Hayyu Ya Qayyum - 111 times",
    "Ya Qadiyal Hajat - 111 times",
    "Ya Rafial Darajat - 111 times",
    "Ya Dafial Bala - 111 times",
    "Ya Mujeebal Dawat - 111 times",
    "Ya Hallal Mushkilat - 111 times",
    "Durood Sharif (End) - 111 times"
];

let gameState = {
    currentIndex: 0,
    currentCount: 0,
    target: 111,
    isFinished: false
};

// --- SOCKET CONNECTION ---
io.on('connection', (socket) => {
    console.log('A user connected');

    // Send current state to the new user immediately
    socket.emit('updateState', { ...gameState, zikrText: zikrList[gameState.currentIndex] });

    // Handle Increment (Reciter clicks)
    socket.on('increment', () => {
        if (gameState.currentCount < gameState.target) {
            gameState.currentCount++;
            
            // Check if finished
            if (gameState.currentCount >= gameState.target) {
                gameState.isFinished = true;
            }

            // Broadcast new count to ALL users
            io.emit('updateState', { ...gameState, zikrText: zikrList[gameState.currentIndex] });
        }
    });

    // Handle Next Zikr (Admin clicks)
    socket.on('nextZikr', () => {
        if (gameState.currentIndex < zikrList.length - 1) {
            gameState.currentIndex++;
            gameState.currentCount = 0;
            gameState.isFinished = false;
            io.emit('updateState', { ...gameState, zikrText: zikrList[gameState.currentIndex] });
        } else {
            // End of Session
            io.emit('sessionComplete', "Khatm Sharif Completed!");
        }
    });

    // Handle Reset (Admin clicks)
    socket.on('resetCurrent', () => {
        gameState.currentCount = 0;
        gameState.isFinished = false;
        io.emit('updateState', { ...gameState, zikrText: zikrList[gameState.currentIndex] });
    });
});

const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});