cmake_minimum_required(VERSION 3.28)

add_definitions(-DYAFET_VERSION="${YAFET_VERSION}")

add_subdirectory(core)
add_subdirectory(classes)
add_subdirectory(app)
