cmake_minimum_required(VERSION 3.4)
project(design)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(design STATIC code/Protocol.h code/CommunicationDevice.h code/SerialDevice.h code/modbus.h code/hdlc.h code/main.cpp)

add_executable(main code/main.cpp)