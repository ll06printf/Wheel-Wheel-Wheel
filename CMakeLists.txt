cmake_minimum_required(VERSION 3.30)

project(TriWheel)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(FetchContent)

# 引入第三方库

# Google Test
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Boost
find_package(Boost REQUIRED)

# 项目文件变量设置

set(IncludeRoot ${PROJECT_SOURCE_DIR}/include/TriW)
set(SourceRoot ${PROJECT_SOURCE_DIR}/src)
set(TestRoot ${PROJECT_SOURCE_DIR}/test)

set(SnippetIncludeRoot ${IncludeRoot}/Snippet)
set(TriWSnippetHeader
        ${SnippetIncludeRoot}/Constraint.h
        ${SnippetIncludeRoot}/Config.h
        ${SnippetIncludeRoot}/Macro.h
)
set(TriWSnippetSource

)

# 项目目标

add_library(TriWSnippet ${TriWSnippetHeader})
target_include_directories(TriWSnippet
        PUBLIC Boost::boost
        INTERFACE include
)
set_target_properties(TriWSnippet PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(test)