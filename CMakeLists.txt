cmake_minimum_required(VERSION 3.10)

project(test)

find_package(Threads)

aux_source_directory(. ROOT_SRC)

add_executable(
    ${PROJECT_NAME}
    ROOT_SRC
)

target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
