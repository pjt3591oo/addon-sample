const test = require('./build/Release/test');

test.add(1, 2, (err, data) => {
  console.log(err, data)
})

console.log('end');