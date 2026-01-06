cmake_minimum_required(VERSION 3.16)
project(crc)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

set(SOURCES 
    ${SOURCE_DIR}/crc16.c
)


add_library(crc STATIC ${SOURCES})

target_include_directories(crc
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)