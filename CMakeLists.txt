cmake_minimum_required(VERSION 3.0.0)
project(AES VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(includes)

add_executable(
    AES 
    src/main.cpp 
    src/matrix.cpp 
    src/AES.cpp 
    src/AESKeyGenerator.cpp 
    src/constants.cpp
    src/multiplication.cpp
    src/substitution.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
