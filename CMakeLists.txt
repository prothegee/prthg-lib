cmake_minimum_required(VERSION 3.15)
project(prthgdf VERSION 0.0.0 DESCRIPTION "an extended library to work with drogon framework backend")


if (PRTHGDF_VPCKG_ENV_DIR STREQUAL "")
    message(STATUS "(msg) ${PROJECT_NAME}: PRTHGDF_VPCKG_ENV_DIR is not supplied")
else()
include("${PRTHGDF_VPCKG_ENV_DIR}/scripts/buildsystems/vcpkg.cmake")
    message(STATUS "(msg) ${PROJECT_NAME}: PRTHGDF_VPCKG_ENV_DIR is supplied as '${PRTHGDF_VPCKG_ENV_DIR}'")
endif()


include(CheckIncludeFileCXX)

check_include_file_cxx(any HAS_ANY)
check_include_file_cxx(string_view HAS_STRING_VIEW)
check_include_file_cxx(coroutine HAS_COROUTINE)

if (NOT "${CMAKE_CXX_STANDARD}" STREQUAL "")
    # Do nothing
elseif (HAS_ANY AND HAS_STRING_VIEW AND HAS_COROUTINE)
    set(CMAKE_CXX_STANDARD 20)
    message(STATUS "(msg) ${PROJECT_NAME}: using c++20")
else ()
    set(CMAKE_CXX_STANDARD 17)
    message(STATUS "(msg) ${PROJECT_NAME}: using c++17")
endif ()


add_library(${PROJECT_NAME}
    prthgdf/prthgdf.cc

    prthgdf/src/prthgdf/HostAndUrl.cc
    prthgdf/src/prthgdf/LanguageContext.cc
)


if (PRTHGDF_AS_SUBDIR)
    message(STATUS "(msg) ${PROJECT_NAME}: treated as subdirectory")
    # #######################################################################################
    # use this if root project folder already supplied
    target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
    # #######################################################################################
else()
message(STATUS "(msg) ${PROJECT_NAME}: treated as module build")
    # #######################################################################################
    # # use this if this project was your root project
    find_package(Drogon CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
    # #######################################################################################
endif()


target_include_directories(${PROJECT_NAME}
    PRIVATE
        .
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/prthgdf/inc>
)