
cmake_minimum_required(VERSION 3.16)
project(tiny_server_cpp)

# C++17 표준 사용
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 소스 파일 모으기
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

# 실행 파일 생성
add_executable(tiny-server ${SOURCES})

# include 디렉토리 등록
target_include_directories(tiny-server PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 경고 옵션 (GCC/Clang일 경우)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  target_compile_options(tiny-server PRIVATE -Wall -Wextra -Wpedantic)
endif()
