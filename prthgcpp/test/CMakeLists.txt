cmake_minimum_required(VERSION 3.15)
project(prthg-lib-test VERSION 0.0.0.20230620)


# ########################################################################
add_executable(${PROJECT_NAME}
    main.cc
)
# ########################################################################


target_link_libraries(${PROJECT_NAME} PRIVATE prthg-lib)