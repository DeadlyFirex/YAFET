cmake_minimum_required(VERSION 3.28)
include(cmake/utilities.cmake)
include(cmake/build.cmake)

loadVersion(YAFET_VERSION)
configureCMake()
project(yafet
        VERSION ${YAFET_VERSION}
        DESCRIPTION "Yet-another-file-encryption-tool built with C++23"
        HOMEPAGE_URL "https://github.com/DeadlyFirex/YAFET"
        LANGUAGES C CXX)

# Options
option(YAFET_STRIP_RELEASE "Strip the release builds" ON)
option(YAFET_IGNORE_BAD_COMPILER "Allow compiling with an unsupported compiler" OFF)
option(YAFET_VERIFY_SUBMODULES "Verify cloning was with --recursive-submodules" ON)
option(YAFET_BUILD_LIBRARIES "Build project libraries from source" ON)
option(YAFET_STATIC_LINK "Statically link all libraries into the main executable" OFF)

# Compiler settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)

# Configure the compiler / build
detectArch()
verifySubmodules()

# Detect environment
setupArguments()
detectOS()
generateName()

if (${YAFET_BUILD_LIBRARIES})
    add_subdirectory(lib/CLI11)
    add_subdirectory(lib/cryptopp)
endif()

add_custom_target(yafet_target ALL)
add_subdirectory(main)

# Packaging
setupOutput()
