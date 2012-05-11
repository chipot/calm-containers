project(vector)
cmake_minimum_required(VERSION 2.8)
 
include_directories(include)

enable_testing()

add_executable(test1
    test/test1.c)

add_executable(test2
    test/test2.c)

add_executable(test3
    test/test3.c)

add_executable(test4
    test/test4.c)

add_executable(test5
    test/test5.c)

add_test(TestInsertErase ./test1 5000)
add_test(TestInsertSortedErase ./test2 5000)
add_test(TestMultiple ./test3)
add_test(TestMapInsert ./test4)
add_test(TestMapRemove ./test5)
