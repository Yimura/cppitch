cmake_minimum_required(VERSION 3.10)

project(cpppitch)

ADD_SUBDIRECTORY(vendor/curlcpp)
INCLUDE_DIRECTORIES(vendor/curlcpp/include)

file(GLOB_RECURSE SOURCE_FILES src/**.cpp)
file(GLOB_RECURSE SOURCE_HEADERS src/**.hpp)

add_executable(cpppitch ${SOURCE_FILES} ${SOURCE_HEADERS})

target_link_libraries(cpppitch curlcpp)