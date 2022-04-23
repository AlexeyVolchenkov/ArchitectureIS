cmake_minimum_required(VERSION 3.10)
project(MergeRobot VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(MergeRobot MergeRobot.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

set(CPACK_PROJECT NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)