cmake_minimum_required(VERSION 3.10)
project(RobotFiles VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

set(FILES "Classes.h" "Classes.cpp" "Enum.h" "Struct.h" "Struct.cpp")

add_executable(RobotFiles "RobotFiles.cpp" "${FILES}")

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

set(CPACK_PROJECT NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)