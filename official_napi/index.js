const addon = require('./build/Release/helloworld');

console.log(addon);

try {
  let added = addon.Add(1);
} catch(err) {
  console.log(err);
}

let added = addon.Add(1, 2)
let subed = addon.Sub(1, 2)

console.log(added);
console.log(subed);

addon.RunCallback((msg1, msg2) => {
  console.log(msg1, msg2);
})

let createdObj = addon.CreateObject()
console.log(createdObj);