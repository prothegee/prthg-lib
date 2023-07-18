cmake_minimum_required(VERSION 3.15)
project(prthg-lib)


# ########################################################################
set(PRTHGLIB_MAJOR 0)
set(PRTHGLIB_MINOR 0)
set(PRTHGLIB_PATCH 0)
set(PRTHGLIB_DATES 20230709)

set(PRTHGLIB_VERSION "${PRTHGLIB_MAJOR}.${PRTHGLIB_MINOR}.${PRTHGLIB_PATCH}.${PRTHGLIB_DATES}")

message(STATUS "(MSG) - ${PROJECT_NAME}: configuring v${PRTHGLIB_VERSION}")
# ########################################################################


# ########################################################################
if (VPCKG_ENV_DIR STREQUAL "")
    message(STATUS "(MSG) - ${PROJECT_NAME}: VPCKG_ENV_DIR is not supplied")
else()
    include("${VPCKG_ENV_DIR}/scripts/buildsystems/vcpkg.cmake")
    message(STATUS "(MSG) - ${PROJECT_NAME}: VPCKG_ENV_DIR is supplied as ${VPCKG_ENV_DIR}")
endif()
# ########################################################################


# ########################################################################
include(CheckIncludeFileCXX)

check_include_file_cxx(any HAS_ANY)
check_include_file_cxx(string_view HAS_STRING_VIEW)
check_include_file_cxx(coroutine HAS_COROUTINE)

if (NOT "${CMAKE_CXX_STANDARD}" STREQUAL "")
    # Do nothing
elseif (HAS_ANY AND HAS_STRING_VIEW AND HAS_COROUTINE)
    set(CMAKE_CXX_STANDARD 20)
    message(STATUS "(MSG) - ${PROJECT_NAME}: using c++20")
else ()
    set(CMAKE_CXX_STANDARD 17)
    message(STATUS "(MSG) - ${PROJECT_NAME}: using c++17")
endif ()


if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Debug")
endif()
# ########################################################################


# ########################################################################
add_library(${PROJECT_NAME}
    prthgcpp/prthgcpp.cc

    prthgcpp/src/Cryptography.cc
    prthgcpp/src/DateAndTime.cc
    prthgcpp/src/Utility.cc
    prthgcpp/src/MailSystem.cc

    prthgcpp/src/drogon/HostAndUrl.cc
    prthgcpp/src/drogon/ViewContent.cc
)
# ########################################################################


# ########################################################################
if (PRTHGLIB_AS_SUBDIR)
    message(STATUS "(MSG) - ${PROJECT_NAME}: treated as subdirectory")

    #[===[
    NOTE:
    when PRTHGLIB_AS_SUBDIR true,
    you need to set find_package(foo CONFIG REQUIRED) at your root project 
    ]===]

    find_package(jsoncpp CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
    set(PRTHGLIB_INC_JSONCPP true)

    if (PRTHGLIB_INC_DROGON)
        target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
    endif()

    if (PRTHGLIB_INC_CRYPTOPP)
        target_link_libraries(${PROJECT_NAME}  PRIVATE cryptopp::cryptopp)
    endif()

    if (PRTHGLIB_INC_MAILIO)
        target_link_libraries(${PROJECT_NAME} PRIVATE mailio)
    endif()
else()
    message(STATUS "(MSG) - ${PROJECT_NAME}: treated as project")

    find_package(jsoncpp CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
    set(PRTHGLIB_INC_JSONCPP true)

    if (PRTHGLIB_INC_DROGON)
        find_package(Drogon CONFIG REQUIRED)
        target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
    endif()

    if (PRTHGLIB_INC_CRYPTOPP)
        find_package(cryptopp CONFIG REQUIRED)
        target_link_libraries(${PROJECT_NAME}  PRIVATE cryptopp::cryptopp)
    endif()

    if (PRTHGLIB_INC_MAILIO)
        find_package(mailio CONFIG REQUIRED)
        target_link_libraries(${PROJECT_NAME} PRIVATE mailio)
    endif()
endif()


# ########################################################################


# ########################################################################
add_definitions(-D__PRTHGLIB_MAJOR__=${PRTHGLIB_MAJOR})
add_definitions(-D__PRTHGLIB_MINOR__=${PRTHGLIB_MINOR})
add_definitions(-D__PRTHGLIB_PATCH__=${PRTHGLIB_PATCH})
add_definitions(-D__PRTHGLIB_DATES__=${PRTHGLIB_DATES})
add_definitions(-D__PRTHGLIB_VERSION__=${PRTHGLIB_VERSION})

add_definitions(-D__PRTHGLIB_AS_SUBDIR__=${PRTHGLIB_AS_SUBDIR})
add_definitions(-D__PRTHGLIB_INC_JSONCPP__=${PRTHGLIB_INC_JSONCPP})
add_definitions(-D__PRTHGLIB_INC_DROGON__=${PRTHGLIB_INC_DROGON})
add_definitions(-D__PRTHGLIB_INC_CRYPTOPP__=${PRTHGLIB_INC_CRYPTOPP})
add_definitions(-D__PRTHGLIB_INC_MAILIO__=${PRTHGLIB_INC_MAILIO})
# ########################################################################


# ########################################################################
configure_file( ${PROJECT_SOURCE_DIR}/prthgcpp/config.h.in ${PROJECT_SOURCE_DIR}/prthgcpp/config.h )
include_directories( ${PROJECT_SOURCE_DIR}/ )
# ########################################################################


# ########################################################################
target_include_directories(${PROJECT_NAME}
    PRIVATE
        .
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/prthgcpp/inc>
)
# ########################################################################


# ########################################################################
add_subdirectory(prthgcpp/test)
# ########################################################################