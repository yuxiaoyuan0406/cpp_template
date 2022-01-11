cmake_minimum_required(VERSION 3.10)

project(test)

find_package(Threads)

add_executable(
    ${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
