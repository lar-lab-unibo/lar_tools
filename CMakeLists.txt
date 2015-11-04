cmake_minimum_required(VERSION 2.8.3)

project(lar_tools)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  geometry_msgs
  tf
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CMAKE_INCLUDE_PATH}
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/cmake/Modules/")
set(CMAKE_INCLUDE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include/")

catkin_package(
   CATKIN_DEPENDS
   roscpp
   rospy
   message_runtime
   geometry_msgs
   std_msgs
   INCLUDE_DIRS include  include/lar_tool_utils
   LIBRARIES ${PROJECT_NAME}
)

include_directories(
  include
  include/lar_tool_utils
  ${Boost_INCLUDE_DIR}
  ${catkin_INCLUDE_DIRS}
)

## LWR HW BASE CLASS TO RULE'EM ALL
add_library(
  ${PROJECT_NAME}
  src/lar_tool_utils/UDPNode.cpp
)
target_link_libraries(
  ${PROJECT_NAME}
  ${catkin_LIBRARIES}
)


# NODES

# TESTING NODE
add_executable(
    testing_node
    src/nodes/test/testing_node.cpp
)
target_link_libraries(
    testing_node
    ${PROJECT_NAME}
    ${catkin_LIBRARIES}
)


# INSTALL

## Install project namespaced headers
