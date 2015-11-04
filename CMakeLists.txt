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
   message_runtime
   geometry_msgs
   std_msgs
)
x

# lwr hw fri node
##(lwr_test ${catkin_LIBRARIES} ${OpenCV_LIBS} ${PCL_LIBRARIES})
#add_dependencies(lwr_test lwr_testing_generate_messages_cpp)
