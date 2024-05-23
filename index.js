const addon = require("./build/Release/addon");

const newYorkLongitude = -74.006;
const newYorkLatitude = 40.7128;

const nycToLondonKm = addon.distanceToLondon(newYorkLongitude, newYorkLatitude);
console.log(`Distance from NYC to London: ${nycToLondonKm.toFixed(2)} km`);
