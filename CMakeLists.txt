cmake_minimum_required(VERSION 3.0.0)
project(partB VERSION 0.1.0)

set(MIVNI_FLAGS_DEBUG "-std=c++11 -Wall ")
set(MIVNI_FLAGS_RELEASE "${MIVNI_FLAGS_DEBUG} ")

set(CMAKE_CXX_FLAGS ${MIVNI_FLAGS_DEBUG})

add_executable(myprog main.cpp library2.cpp Course.cpp DynamicArray.cpp HashTable.cpp CoursesManager.cpp Lecture.cpp)