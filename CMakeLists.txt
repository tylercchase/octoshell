cmake_minimum_required(VERSION 3.16)
project(octoshell)

include(CTest)
enable_testing()

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.x)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 20)

set(Warnings, $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Wpedantic -Weverything>
        $<$<CXX_COMPILER_ID:MSVC>:
        /W4>)

file(GLOB_RECURSE TESTS RELATIVE ${CMAKE_SOURCE_DIR} "tests/*.cpp")
file(GLOB_RECURSE SRC RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

add_executable(test_suite ${TESTS} src/command.cpp src/parser.cpp src/terminal.cpp)
add_executable(terminal ${SRC})
target_compile_options(test_suite PRIVATE ${Warnings})
target_link_libraries(test_suite PRIVATE Catch2::Catch2)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES Off)


add_test(testing test_suite)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(CPack)