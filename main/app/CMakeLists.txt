cmake_minimum_required(VERSION 3.28)
project(app)

add_executable(app main.cpp)

# Add definitions and properties
set_target_properties(app PROPERTIES OUTPUT_NAME ${YAFET_EXECUTABLE_NAME})

# Include directories
target_include_directories(app PUBLIC include)

# Add dependencies
add_dependencies(app core)

# Link libraries
if(${FUKUTO_STATIC_LINK})
    target_link_libraries(app -Wl,-Bstatic core)
else()
    target_link_libraries(app -Wl,-Bdynamic core)
endif()

# Specify the required C++ standard
target_compile_features(core PRIVATE cxx_std_23)

add_dependencies(yafet_target app)
