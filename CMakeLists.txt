#Source: http://derekmolloy.ie/hello-world-introductions-to-cmake/
################################
## General project settings
################################
cmake_minimum_required(VERSION 3.22)

################################################################
## Build options
##      Turn on with 'cmake -Dtest=ON'.
################################################################
option(test          "Build all tests."  OFF) # Makes boolean 'test' available.
option(HappyNumber   "Happy number only" OFF)
option(Pivot         "Pivot"             OFF)
option(RunningSum    "Running sum only"  OFF)
option(TwoSum        "TwoSum"            OFF)
option(AnswerQuery   "AnswerQuery"     OFF)

################################################################
## Project description
## Syntax:
##       project(<project_name> DESCRIPTION <string_description> LANGUAGES CXX)
################################################################
if (test)
    project(exe_test DESCRIPTION "Hello world" LANGUAGES CXX)
    set(TEST_PROJECT_NAME LeetCodeTests)
else()
    project(exe DESCRIPTION "Hello world" LANGUAGES CXX)
endif()

################################################################
## Compiler settings
################################################################
# set(CMAKE_C_COMPILER            /usr/bin/gcc)
# set(CMAKE_CXX_COMPILER          /usr/bin/g++)
# set(CMAKE_CXX_STANDARD          17)
set(CMAKE_C_COMPILER            /usr/bin/gcc-12)
set(CMAKE_CXX_COMPILER          /usr/bin/g++-12)
set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

################################################################
## Libraries
################################################################
## Used for Rust-like printing
##   e.g. fmt::print("{}", var)
find_package(fmt)

################################################################
## Project-specific settings
################################################################
# Include the header files
include_directories(headers)

# Link libraries
link_directories(${CMAKE_SOURCE_DIR}/libs)
# this means that under the ./libs folder, there are the libfoo.so and libbar.so files
# target_link_libraries(foo bar)

################################################################
## Ready to compile/build!
################################################################
## Assuming no testing...
file(GLOB SOURCES "sources/*.cpp")              # These are the source files

## Otherwise
## Enabled with 'cmake -Dtest=ON'.
if (test)
    enable_testing()

    # Use GoogleTest
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # Fetch all the source files needed for testing
    file(GLOB SOURCES "sources/*.cpp" "tests/Test_main.cpp")

    # ...except the ./sources/main.cpp file
    foreach(ITEM ${SOURCES})
        if(${ITEM} MATCHES "sources/main.cpp")
            list(REMOVE_ITEM SOURCES ${ITEM})
        endif(${ITEM} MATCHES "sources/main.cpp")
    endforeach(ITEM)

    # Depending on the flag, pick the specific test
    if(HappyNumber)
        file(GLOB TEST_NAMES "tests/Test_HappyNumber.cpp")
    elseif(Pivot)
        file(GLOB TEST_NAMES "tests/Test_Pivot.cpp")
    elseif(RunningSum)
        file(GLOB TEST_NAMES "tests/Test_RunningSum.cpp")
    elseif(TwoSum)
        file(GLOB TEST_NAMES "tests/Test_TwoSum.cpp")
    elseif(AnswerQuery)
        file(GLOB TEST_NAMES "tests/Test_AnswerQueries.cpp")
    else()
        file(GLOB TEST_NAMES "tests/*.cpp")
    endif()
    list(APPEND      SOURCES    ${TEST_NAMES})
    # list(REMOVE_ITEM TEST_NAMES tests/Test_main.cpp)

    # Add the tests to GoogleTest
    add_test(NAME ${TEST_PROJECT_NAME} COMMAND ${CMAKE_PROJECT_NAME})

    # Compile the unit test binary file
    add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Werror -O3 -fPIC -std=c++20 --coverage -fprofile-arcs -ftest-coverage)

    # In the linkers, add the GoogleTest libraries
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE fmt::fmt ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} gcov)
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
else()
    # Compile the main binary file
    add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Werror -O3 -fPIC -std=c++20)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE fmt::fmt)
endif()


