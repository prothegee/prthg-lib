cmake_minimum_required(VERSION 3.15)
project(prthgcpp)


# ########################################################################
set(PRTHGCPP_MAJOR 0)
set(PRTHGCPP_MINOR 0)
set(PRTHGCPP_PATCH 1)
set(PRTHGCPP_DATES 20230722)

set(PRTHGCPP_VERSION "${PRTHGCPP_MAJOR}.${PRTHGCPP_MINOR}.${PRTHGCPP_PATCH}.${PRTHGCPP_DATES}")

message(STATUS "(MSG) - ${PROJECT_NAME}: configuring v${PRTHGCPP_VERSION}")
# ########################################################################


# ########################################################################
if(INC_VPCKG)
    include("${INC_VPCKG_DIR}/scripts/buildsystems/vcpkg.cmake")
    message(STATUS "(MSG) - ${PROJECT_NAME}: INC_VPCKG_DIR is supplied as ${INC_VPCKG_DIR}")
else()
    message(STATUS "(MSG) - ${PROJECT_NAME}: INC_VPCKG_DIR is not supplied, will assume library already include from workstation environment")
endif(INC_VPCKG)
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
set(PRTHGCPP_FILE_SOURCE
    src/prthgcpp/prthgcpp.cc

    # internal region
    src/prthgcpp/classes/Cryptography.cc
    src/prthgcpp/classes/DateAndTime.cc
    src/prthgcpp/classes/Utility.cc
    src/prthgcpp/classes/MailSystem.cc

    # drogon framework region
    src/prthgcpp/classes/HostAndUrl.cc
    src/prthgcpp/classes/ViewContent.cc
)
# ########################################################################


# ########################################################################
add_library(${PROJECT_NAME}
    ${PRTHGCPP_FILE_SOURCE}
)
# ########################################################################


# ########################################################################
if (INC_PRTHGCPP_AS_SUBDIR)
    message(STATUS "(MSG) - ${PROJECT_NAME}: treated as subdirectory")

    #[===[
    NOTE:
    when INC_PRTHGCPP_AS_SUBDIR true,
    you need to set find_package(foo CONFIG REQUIRED) at your root project 
    ]===]

    if (INC_PRTHGCPP_JSONCPP)
        target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
    endif()

    if (INC_PRTHGCPP_DROGON)
        target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
    endif()

    if (INC_PRTHGCPP_CRYPTOPP)
        target_link_libraries(${PROJECT_NAME}  PRIVATE cryptopp::cryptopp)
    endif()

    if (INC_PRTHGCPP_MAILIO)
        target_link_libraries(${PROJECT_NAME} PRIVATE mailio)
    endif()
else()
    message(STATUS "(MSG) - ${PROJECT_NAME}: treated as project")

    if (INC_PRTHGCPP_JSONCPP)
        find_package(jsoncpp CONFIG REQUIRED)
        target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
    endif()

    if (INC_PRTHGCPP_DROGON)
        find_package(Drogon CONFIG REQUIRED)
        target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
    endif()

    if (INC_PRTHGCPP_CRYPTOPP)
        find_package(cryptopp CONFIG REQUIRED)
        target_link_libraries(${PROJECT_NAME}  PRIVATE cryptopp::cryptopp)
    endif()

    if (INC_PRTHGCPP_MAILIO)
        find_package(mailio CONFIG REQUIRED)
        target_link_libraries(${PROJECT_NAME} PRIVATE mailio)
    endif()
endif(INC_PRTHGCPP_AS_SUBDIR)

if(INC_PRTHGCPP_ALLDEPS)
    message(STATUS "(MSG) - ${PROJECT_NAME}: forcing prthgcpp deps to find all packages")

    find_package(jsoncpp CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
    set(INC_PRTHGCPP_MAILIO TRUE)

    find_package(Drogon CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
    set(INC_PRTHGCPP_DROGON TRUE)

    find_package(cryptopp CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME}  PRIVATE cryptopp::cryptopp)
    set(INC_PRTHGCPP_CRYPTOPP TRUE)

    find_package(mailio CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE mailio)
    set(INC_PRTHGCPP_MAILIO TRUE)
endif(INC_PRTHGCPP_ALLDEPS)

# ########################################################################


# ########################################################################
add_definitions(-D__PRTHGCPP_MAJOR__=${PRTHGCPP_MAJOR})
add_definitions(-D__PRTHGCPP_MINOR__=${PRTHGCPP_MINOR})
add_definitions(-D__PRTHGCPP_PATCH__=${PRTHGCPP_PATCH})
add_definitions(-D__PRTHGCPP_DATES__=${PRTHGCPP_DATES})
add_definitions(-D__PRTHGCPP_VERSION__=${PRTHGCPP_VERSION})

add_definitions(-D__INC_PRTHGCPP__=${INC_PRTHGCPP_AS_SUBDIR})
add_definitions(-D__INC_PRTHGCPP_JSONCPP__=${INC_PRTHGCPP_JSONCPP})
add_definitions(-D__INC_PRTHGCPP_DROGON__=${INC_PRTHGCPP_DROGON})
add_definitions(-D__INC_PRTHGCPP_CRYPTOPP__=${INC_PRTHGCPP_CRYPTOPP})
add_definitions(-D__INC_PRTHGCPP_MAILIO__=${INC_PRTHGCPP_MAILIO})
# ########################################################################


# ########################################################################
configure_file(
    ${PROJECT_SOURCE_DIR}/inc/prthgcpp/config.h.in
    ${PROJECT_SOURCE_DIR}/inc/prthgcpp/config.gen.h
)

include_directories(${PROJECT_SOURCE_DIR}/
)
# ########################################################################


# ########################################################################
aux_source_directory(inc/prthgcpp/classes PRTHGCPP_CLASSES_INC)
aux_source_directory(inc/prthgcpp/enums PRTHGCPP_ENUMS_INC)
aux_source_directory(inc/prthgcpp/types PRTHGCPP_TYPES_INC)
# ########################################################################


# ########################################################################
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
)
# ########################################################################


# ########################################################################
target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc/prthgcpp
        ${PRTHGCPP_CLASSES_SRC}
        ${PRTHGCPP_ENUMS_SRC}
        ${PRTHGCPP_TYPES_SRC}
)
# ########################################################################


# ########################################################################
add_subdirectory(test)
# ########################################################################


# ########################################################################
if (PRTHGCPP_NET_EXPORT)
    # # TODO
    # set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/prthgnet/obj)
    # set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/prthgnet/obj)
    # set(CMAKE_PDB_OUTPUT_DIRECTORY      ${CMAKE_CURRENT_SOURCE_DIR}/prthgnet/obj)
    # set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/prthgnet/obj)
endif()
# ########################################################################