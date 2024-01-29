macro(configureCMake)
    if (NOT YAFET_VERSION)
        message(FATAL_ERROR "YAFET_VERSION is not defined")
    endif()

    if(YAFET_STRIP_RELEASE)
        if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
            add_link_options($<$<CONFIG:RELEASE>:-s>)
        endif()
    endif()

    message(STATUS "Configuring YAFET v${YAFET_VERSION}")
    enable_language(C CXX)

    if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Using RelWithDebInfo build type as it was left unset" FORCE)
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "RelWithDebInfo")
    endif()

    if (WIN32)
        message(STATUS "Adding extra configuration options for Windows")
        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    endif()

    if (CMAKE_BUILD_TYPE MATCHES "Release|RelWithDebInfo|MinSizeRel")
        add_compile_definitions(NDEBUG)
    else (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Building in debug mode")
        add_compile_definitions(DEBUG _GLIBCXX_DEBUG _GLIBCXX_VERBOSE)
    endif()
endmacro()

macro(setupArguments)
    set(YAFET_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin/${YAFET_ARCH}" CACHE PATH "Output path for the binaries")
    set(YAFET_EXECUTABLE_NAME "null" CACHE STRING "Output name for the executable")
    set(YAFET_BASE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Base folder for the project" FORCE)
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

    foreach(target IN ITEMS core classes app)
        if(TARGET ${target})
            set_target_properties(${target} PROPERTIES
                    RUNTIME_OUTPUT_DIRECTORY ${YAFET_OUTPUT_PATH}
                    LIBRARY_OUTPUT_DIRECTORY ${YAFET_OUTPUT_PATH})
        endif()
    endforeach()
endmacro()
