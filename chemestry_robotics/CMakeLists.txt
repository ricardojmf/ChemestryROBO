cmake_minimum_required(VERSION 2.8.3)

project(stdr)

find_package(catkin REQUIRED COMPONENTS geometry_msgs roscpp sensor_msgs)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(stdr_node src/test.cpp)

add_dependencies(stdr_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(stdr_node ${catkin_LIBRARIES})

