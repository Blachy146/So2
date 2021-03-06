cmake_minimum_required(VERSION 3.0)

project(so2_zad1 CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lpthread -lncurses")

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(INTERFACE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/interface)

set(EXEC_ONLY_SOURCES
  ${SOURCE_DIR}/main.cpp
)

set(SOURCES
  ${SOURCE_DIR}/Fork.cpp
  ${SOURCE_DIR}/Philosopher.cpp
  ${SOURCE_DIR}/RandomGenerator.cpp
)

set(INCLUDES
  ${INCLUDE_DIR}/Fork.hpp
  ${INCLUDE_DIR}/Philosopher.hpp
  ${INCLUDE_DIR}/RandomGenerator.hpp
)

set(INTERFACES
)

set(TARGET_LIBRARY_NAME ${PROJECT_NAME}-lib)

add_library(${TARGET_LIBRARY_NAME} ${SOURCES} ${INCLUDES} ${INTERFACES})
set_target_properties(${TARGET_LIBRARY_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${TARGET_LIBRARY_NAME} PUBLIC ${INCLUDE_DIR} ${INTERFACE_DIR})

add_executable(${PROJECT_NAME} ${EXEC_ONLY_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${TARGET_LIBRARY_NAME})
