project(vector)
cmake_minimum_required(VERSION 2.8)
 
include_directories(include)
enable_testing()

file(GLOB ALL_TESTS test/*.c)

foreach(SOURCE_FILE ${ALL_TESTS})
        string(REPLACE ".c" "" WO_SUFFIX ${SOURCE_FILE})
        string(REPLACE ${CMAKE_CURRENT_SOURCE_DIR}/ "" SRC_BASENAME ${SOURCE_FILE})
        string(REPLACE ${CMAKE_CURRENT_SOURCE_DIR}/test/ "" BIN_BASENAME ${WO_SUFFIX})
        add_executable(${BIN_BASENAME} ${SRC_BASENAME})
        add_test("test_${BIN_BASENAME}" ${BIN_BASENAME})
endforeach(SOURCE_FILE)
