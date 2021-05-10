### dependency

* 초기에 셋팅할 경우

```sh
$ npm init -y
$ npm install bindings
$ npm install node-addon-api # napi.h를 사용할 수 있도록 한다.
```

* package.json에 의존 모듈이 명시 되어있을 경우

```sh
$ npm install
```

* build 

```
$ node-gyp rebuild
```

* run 

```
$ node index.js
```