// THE KILL SWITCH
self.addEventListener('install', function(e) {
    // Force this new "cleaner" worker to activate immediately
    self.skipWaiting();
});

self.addEventListener('activate', function(e) {
    e.waitUntil(
        // Find every single cache saved on the user's phone for this app
        caches.keys().then(function(cacheNames) {
            return Promise.all(
                cacheNames.map(function(cacheName) {
                    // Delete it all
                    console.log('Deleting old cache:', cacheName);
                    return caches.delete(cacheName);
                })
            );
        }).then(function() {
            // Once caches are dead, unregister this service worker permanently
            self.registration.unregister().then(function() {
                // Force all open tabs of this app to reload and grab the fresh live code
                return self.clients.claim();
            });
        })
    );
});