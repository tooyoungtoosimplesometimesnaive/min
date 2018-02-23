// hello.js
const addon = require('./build/Release/addon');

console.log(addon.hello());
console.log(addon.add( 100, 1 ));
console.log(addon.execute());
// Prints: 'world'

