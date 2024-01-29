cmake_minimum_required(VERSION 3.27)
project(app)

# Add source files
add_executable(app main.cpp)

# Link libraries
target_link_libraries(app PUBLIC core CLI11::CLI11)

# Add definitions and properties
set_target_properties(app PROPERTIES OUTPUT_NAME ${YAFET_EXECUTABLE_NAME})

# Include directories
target_include_directories(app PUBLIC include)

# Add dependencies
add_dependencies(app core)

# Specify the required C++ standard
target_compile_features(app PRIVATE cxx_std_23)

add_dependencies(yafet_target app)
