var i = 0;
var map;
document.querySelector('#locationForm').addEventListener('submit', function (event) {
    event.preventDefault();
    const formData = new FormData(event.target);
    let usp = new URLSearchParams();
    formData.forEach((value, key) => {
        usp.append(key, value);
    });
    fetch('api-adresses.php', {
        method: 'POST',
        headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
        body: usp
    })
        .then(function(response) {
            let json = response.json();
            return json;
        })
        .then(locations => {
            if (i++ > 0) {
                map.remove();
            }
            map = L.map('map');
            console.log(locations);
            if (locations.length == 0) {
                console.log(locations);
                alert("Pas de rues trouvées !");
            } else {
                map.setView([locations[0].lat, locations[0].lng], 6);
                L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
                    attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
                }).addTo(map);
                displayMap(locations);
            }
        })
        .catch(error => console.error('Erreur :', error));
});

function displayMap(locations) {
    locations.forEach(location => {
        L.marker([location.lat, location.lng]).addTo(map)
            .bindPopup(location.address)
            .openPopup();
    });
}