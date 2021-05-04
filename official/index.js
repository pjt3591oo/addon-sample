const hello = require('./build/Release/hello_world');

console.log(hello);
console.log();

hello.runCallback((msg) => {
  console.log(msg);
})

console.log(hello.add(1, 2));
console.log(hello.sub(1, 2));

console.log(hello.createObject('mung', 'pjt'));

const madeFunction = hello.createFunction();
console.log(madeFunction());