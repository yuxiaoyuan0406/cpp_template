cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(Threads REQUIRED)

aux_source_directory(. ROOT_SRC)

add_executable(
    ${PROJECT_NAME}
    ${ROOT_SRC}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
