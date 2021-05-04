const hello = require('./build/Release/hello_world');

let promise = hello.add(1.0, 2.0).then(data => {
  console.log(data);
})

console.log('end', promise);