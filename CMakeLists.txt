CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
CMAKE_POLICY(SET CMP0002 OLD) #Allow multiple targets with same name

PROJECT(CppPrimer)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Wno-unused-parameter -pedantic -DNDEBUG")

ADD_SUBDIRECTORY(./Chapter_01)
ADD_SUBDIRECTORY(./Chapter_02)
ADD_SUBDIRECTORY(./Chapter_03)
ADD_SUBDIRECTORY(./Chapter_04)
ADD_SUBDIRECTORY(./Chapter_05)
ADD_SUBDIRECTORY(./Chapter_06)
ADD_SUBDIRECTORY(./Chapter_07)
