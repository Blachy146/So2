cmake_minimum_required(VERSION 3.0)

project(so2_zad3 CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lpthread -lncurses")

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(INTERFACE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/interface)

set(EXEC_ONLY_SOURCES
  ${SOURCE_DIR}/main.cpp
)

set(SOURCES
  ${SOURCE_DIR}/Building.cpp
  ${SOURCE_DIR}/Elevator.cpp
  ${SOURCE_DIR}/Person.cpp
  ${SOURCE_DIR}/Queue.cpp
)

set(INCLUDES
  ${INCLUDE_DIR}/Building.hpp
  ${INCLUDE_DIR}/Elevator.hpp
  ${INCLUDE_DIR}/Person.hpp
  ${INCLUDE_DIR}/Queue.hpp
)

set(INTERFACES
)

set(TARGET_LIBRARY_NAME ${PROJECT_NAME}-lib)

add_library(${TARGET_LIBRARY_NAME} ${SOURCES} ${INCLUDES})
target_include_directories(${TARGET_LIBRARY_NAME} PUBLIC ${INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${EXEC_ONLY_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${TARGET_LIBRARY_NAME})
