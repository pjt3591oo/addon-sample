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

* vscode include path settup

`.vscode/c_cpp_properties.json` 해당 설정 파일은 확장 프로그램 `C/C++` 설정파일

```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**",
                "${workspaceFolder}/promise/**",
                "/usr/local/include/node/**"
            ],
            "defines": [],
            "macFrameworkPath": [
                "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c17",
            "cppStandard": "c++98",
            "intelliSenseMode": "macos-clang-x64"
        }
    ],
    "version": 4
}
```

`includePath` 3번째(`/usr/localinclude/node`) 사용자 환경에 따라 달라질 수 있음.