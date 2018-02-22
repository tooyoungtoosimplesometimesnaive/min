// hello.js
const addon = require('./build/Release/addon');

console.log(addon.hello());
console.log(addon.add( 100, 1 ));
// Prints: 'world'

