cmake_minimum_required(VERSION "3.12")
project("TestApplication1")

# This variable stores the string that you put in the project command
# PROJECT_NAME
# To dereference a variable in CMake you use the ${} symbols
# like this (the quotes in case it's a String variable): "${PROJECT_NAME}"
# example at the first parameter of add_executable command

set(CMAKE_CXX_STANDARD 14)

# In CMake when something is marked as - it's a
# PRIVATE       Build Requirement
# INTERFACE     Usage Requirement
# PUBLIC        Usage & Build Requirement

# Static Linked Librares are embedded in the executable (is technically faster)
# Dynamic Linked Libraries are linked at runtime

# Used to specify the include directories with headers for the current project
# include_directories()

# Used to specify the library implementation for the target executable
# target_link_libraries("${PROJECT_NAME}" PRIVATE lib_file.a)
# you can also use target_link_directories (probably?)
# target_link_directories()

# This instruction is used to add preprocessore definition
# CMake adds NDEBUG flag by default which is active when the program is not in debug mode
add_compile_definitions(TESTAPP_DEBUG)

add_executable(
        "${PROJECT_NAME}"

        "main.cpp"
        "models/shapes/Shape.h"
        "models/shapes/Circle.cpp"
        "models/shapes/Circle.h"
        "models/shapes/Rectangle.cpp"
        "models/shapes/Rectangle.h"
        "models/Box.h"
        "functions.cpp"
        "models/shapes/shapestructs.h"
        "Logger.h"
        "models/shapes/Printable.h"
        "models/String.h"
)

# This will tell CMake to go into the sub_project directory and to execute the CMakeLists.txt file there
# add_subdirectory("sub_project")

# Sets the install Target directories inside of relative folders | ${CMAKE_INSTALL_PREFIX}/bin
# install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
# install(FILES "main.cpp" "Logger.h" "main_legacy.cpp" "functions.cpp" "models" DESTINATION src)

# Adds CMake Test Capabilities to the project\
# include(CTest)

# CMAKE_CURRENT_BINARY_DIR points to the binary directory

# Tests pass if they return 0 and fail if they return anything else
# add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}")
# Here we pass an optional parameter to the executable
# add_test("test2" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}", "some_parameter")

# You can use CDash.org to do CI and run tests automatically
# Nightly Builds are run at a specific time and syncs with VCS
# Continuous Builds also sync with VCS
# Experimental Builds don't sync with VCS

# Used to compress your project install files
# include(CPack)
# Uses the directory system specified with the install command
# You can pack as a zip, 7z or NSIS (which is a scriptable install system that allows the creation of an install wizard)

# Used to compile both Static and Shared Libraries
# If the variable ${BUILD_SHARED_LIBS} is set to true add_library will build Shared Libs (static otherwise)
# add_library("libName" "")