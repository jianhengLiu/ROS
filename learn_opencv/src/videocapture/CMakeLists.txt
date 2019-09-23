cmake_minimum_required(VERSION 2.8.3)
project(videocapture)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS sensor_msgs cv_bridge roscpp std_msgs image_transport rospy)
find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES videocapture
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include ${catkin_INCLUDE_DIRS}
# include
# ${catkin_INCLUDE_DIRS}
)


add_executable(videocapture
  src/videocapture.cpp
)
add_dependencies(videocapture ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(videocapture
  ${catkin_LIBRARIES}
)

add_executable(picturepub
  src/picturepub.cpp
)
add_dependencies(picturepub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(picturepub
  ${catkin_LIBRARIES}
)

add_executable(cameraproc
  src/cameraproc.cpp)
add_dependencies(cameraproc ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(cameraproc
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)

add_executable(picturesub
  src/picturesub.cpp
)
add_dependencies(picturesub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(picturesub
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)

add_executable(cannyproc
  src/cannyproc.cpp
)
add_dependencies(cannyproc ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(cannyproc
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)

add_executable(linedetect
  src/linedetect.cpp
)
add_dependencies(linedetect ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(linedetect
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)