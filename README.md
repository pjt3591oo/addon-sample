# cpp addon

* [공식문서 제공코드](https://github.com/pjt3591oo/addon-sample/tree/master/official)

* [공식문서 제공코드(napi.h)](https://github.com/pjt3591oo/addon-sample/tree/master/official_napi)

* [Promise 반환(napi.h)](https://github.com/pjt3591oo/addon-sample/tree/master/promise)

* [비동기 콜백함수1(napi.h)](https://github.com/pjt3591oo/addon-sample/tree/master/asyncCallback)

* [비동기 콜백함수2(napi.h)](https://github.com/pjt3591oo/addon-sample/tree/master/multiCreateCallbackCallByAsync)

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