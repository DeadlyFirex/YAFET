cmake_minimum_required(VERSION 3.28)
project(core)

# Add the library
if(${YAFET_STATIC_LINK})
    add_library(core STATIC)
else()
    add_library(core SHARED)
endif()

# Specify the source files
target_sources(core PRIVATE
        include/core.h
        core.cpp
)

# Specify the required C++ standard
target_compile_features(core PRIVATE cxx_std_23)

# Include directories
target_include_directories(core PUBLIC include)
