# prthgdf

an extended library to work with drogon framework backend

<br>

- dependencies:
    - [required - drogonframework](https://github.com/drogonframework/drogon)

    <br>

    - [optional - fmt](https://github.com/fmtlib/fmt)

    <br>

    - [optional - vcpkg](https://github.com/Microsoft/vcpkg)

<br>

---

## cmake configure settings

- `PRTHGDF_AS_SUBDIR`:
    - required:
        - false
    - type value:
        - bool
    - default value:
        - false
    - note:
        - treat this library as subdirectory

<br>

- `PRTHGDF_VPCKG_ENV_DIR`:
    - required:
        - false
    - type value:
        - path/string
    - default value:
        - ""
    - note:
        - supply a value from your [vcpkg](https://github.com/Microsoft/vcpkg) directory, where it will look a buildsystems scripts and search for dependencies

<br>

---

###### end of readme