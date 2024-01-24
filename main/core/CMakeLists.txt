cmake_minimum_required(VERSION 3.28)
project(core)

# Add the library
if(${YAFET_STATIC_LINK})
    add_library(core STATIC)
else()
    add_library(core SHARED)
endif()

if (NOT ${YAFET_BUILD_LIBRARIES})
    message(STATUS "Using system libraries")
    find_library(cryptopp cryptopp REQUIRED)

    # Add the library
    target_link_libraries(core cryptopp)
else()
    message(FATAL_ERROR "Building libraries from source not supported yet")
endif()

# Specify the source files
target_sources(core PUBLIC
        include/core.h
        core.cpp
)

# Specify the required C++ standard
target_compile_features(core PRIVATE cxx_std_23)

# Include directories
target_include_directories(core PUBLIC include)

# Add target dependencies
add_dependencies(yafet_target core)
