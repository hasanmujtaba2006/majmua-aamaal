const CACHE_NAME = 'khatme-qadirya-v1';
const ASSETS = [
  '/',
  '/index.html',
  '/Al Qalam Quran Majeed Web Regular.ttf',
  '/Jameel Noori Nastaleeq Kasheeda.ttf',
  '/Jameel Noori Nastaleeq Regular.ttf',
  'https://cdn.socket.io/4.8.1/socket.io.min.js',
  'https://fonts.googleapis.com/css2?family=Outfit:wght@300;500;700&family=Gulzar&display=swap'
];

// Install Event
self.addEventListener('install', (e) => {
  e.waitUntil(
    caches.open(CACHE_NAME).then((cache) => {
      return cache.addAll(ASSETS);
    })
  );
});

// Fetch Event
self.addEventListener('fetch', (e) => {
  e.respondWith(
    caches.match(e.request).then((response) => {
      return response || fetch(e.request);
    })
  );
});