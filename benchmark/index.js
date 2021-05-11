const addon = require('../official_napi/build/Release/helloworld');

function jsAdd(a, b) {
  return a + b;
}

const COUNT = 1000000;

console.time('js');
for(let i = 0 ; i < COUNT ; ++i) {
  jsAdd(1, 1);
}
console.timeEnd('js');

console.time('cpp');
for(let i = 0 ; i < COUNT ; ++i) {
  addon.Add(1,1);
}
console.timeEnd('cpp');
