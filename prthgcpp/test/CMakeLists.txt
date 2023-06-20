cmake_minimum_required(VERSION 3.15)
project(prthg-lib-test)


# ########################################################################
add_executable(${PROJECT_NAME}
    main.cc
)
# ########################################################################


# ########################################################################
if (PRTHGLIB_INC_DROGON)
    target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE prthg-lib)
# ########################################################################