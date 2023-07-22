# `prthg-lib`

__*prthg-lib project source code*__

__*currently only used on internal projects as extended libraries*__

<br>

---

## libraries

- `prthgcpp`:

    - about:
        ```
        N\A
        ```
    
    - dependencies:
        - required:
            - N\A

        - optional:
            - [jsoncpp](https://github.com/open-source-parsers/jsoncpp):
                - main json parsing
            - [drogonframework](https://github.com/drogonframework/drogon):
                - drogon framework backend integration
            - [cryptopp](https://github.com/weidai11/cryptopp):
                - hash & stream cipher integration
            - [mailio](https://github.com/karastojko/mailio):
                - mail system with mailio

    - note:
        - using *c++20* by default, otheriwse *c++17*
        - all coroutine function will be marked with Task suffix ( e.g. __*MyCallerTask()*__ )

<br>

- `prthgnode`:

    - about:
        ```
        N\A
        ```
    
    - dependencies:
        - required:
            - [typescript](https://github.com/microsoft/typescript):
                - superset javascript
            - [tslib](https://github.com/microsoft/tslib):
                - runtime library for typescript
            - [rollup](https://rollupjs.org):
                - build tool

        - optional:
            - N\A

    - note:
        ```
        N\A
        ```

<br>

---

###### end of readme