cmake_minimum_required(VERSION 3.28)
project(core)

# Specify the source files
target_sources(core PRIVATE
        include/file.h
        file.cpp
)

# Include directories
target_include_directories(core PUBLIC include)
