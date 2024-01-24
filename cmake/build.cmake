if(YAFET_STRIP_RELEASE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_link_options($<$<CONFIG:RELEASE>:-s>)
    endif()
endif()

function(verifyCompiler)
if (YAFET_IGNORE_BAD_COMPILER)
    return()
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "12.0.0")
    message(FATAL_ERROR "YAFET requires GCC 12.0.0 or newer. Please use the latest GCC version.")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "17.0.0")
    message(FATAL_ERROR "YAFET requires Clang 17.0.0 or newer. Please use the latest Clang version.")
elseif (NOT (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
    message(FATAL_ERROR "YAFET can only be compiled with GCC or Clang. ${CMAKE_CXX_COMPILER_ID} is not supported.")
endif()
endfunction()

macro(configureCMake)
    # Check if version is defined
    if (NOT YAFET_VERSION)
        message(FATAL_ERROR "YAFET_VERSION is not defined")
    endif()

    if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Using RelWithDebInfo build type as it was left unset" FORCE)
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "RelWithDebInfo")
    endif()

    set(YAFET_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin/${YAFET_ARCH}" CACHE PATH "Output path for the binaries")
    set(YAFET_EXECUTABLE_NAME "null" CACHE STRING "Output name for the executable")
    set(YAFET_BASE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})

    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_definitions(NDEBUG)
    elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_definitions(DEBUG _GLIBCXX_DEBUG _GLIBCXX_VERBOSE)
    elseif (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
        add_compile_definitions(NDEBUG)
    elseif (CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
        add_compile_definitions(NDEBUG)
    endif ()

    message(STATUS "Configuring YAFET v${YAFET_VERSION}")

    # Enable C and C++ languages
    enable_language(C CXX)

    # Configure use of recommended build tools
    if (YAFET_USE_DEFAULT_BUILD_SETTINGS)
        message(STATUS "Configuring CMake to use recommended build tools...")

        find_program(NINJA_PATH ninja)

        if (NINJA_PATH)
            set(CMAKE_GENERATOR Ninja)
        else ()
            message(WARNING "ninja not found, using default generator!")
        endif ()
    endif()
endmacro()

function(loadVersion version)
    set(VERSION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/VERSION")
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${VERSION_FILE})
    file(READ "${VERSION_FILE}" read_version)
    string(STRIP ${read_version} read_version)
    set(${version} ${read_version} PARENT_SCOPE)
endfunction()

function(verifySubmodules)
    if (YAFET_IGNORE_BAD_CLONE)
        return()
    endif()

    file (GLOB EXTERNAL_DIRS "lib/*")
    foreach (EXTERNAL_DIR ${EXTERNAL_DIRS})
        file(GLOB_RECURSE RESULT "${EXTERNAL_DIR}/*")
        list(LENGTH RESULT ENTRY_COUNT)
        if(ENTRY_COUNT LESS_EQUAL 1)
            message(FATAL_ERROR "External dependency ${EXTERNAL_DIR} is empty!\n
            Make sure to clone using the --recurse-submodules git option or initialize the submodules manually.")
        endif()
    endforeach ()
endfunction()

macro(setupOutput)
    message(STATUS "Outputting to <${YAFET_OUTPUT_PATH}>")

    if(TARGET core)
        set_target_properties(core PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${YAFET_OUTPUT_PATH})
        set_target_properties(core PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${YAFET_OUTPUT_PATH})
    endif()

    if(TARGET classes)
        set_target_properties(classes PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${YAFET_OUTPUT_PATH})
        set_target_properties(classes PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${YAFET_OUTPUT_PATH})
    endif()

    if(TARGET app)
        set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${YAFET_OUTPUT_PATH})
        set_target_properties(app PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${YAFET_OUTPUT_PATH})
    endif()
endmacro()