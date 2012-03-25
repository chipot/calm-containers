project(vector)
cmake_minimum_required(VERSION 2.8)
 
include_directories(include)

enable_testing()

add_executable(test1
    test/test1.c)

add_executable(test2
    test/test2.c)

add_test(TestInsertErase ./test1 5000)
add_test(TestInsertSortedErase ./test2 5000)
