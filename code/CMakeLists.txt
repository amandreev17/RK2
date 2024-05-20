cmake_minimum_required(VERSION 3.4)
project(design)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(design STATIC Protocol.h CommunicationDevice.h SerialDevice.h modbus.h hdlc.h main.cpp)

add_executable(main main.cpp)
