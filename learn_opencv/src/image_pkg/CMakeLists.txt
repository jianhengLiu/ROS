cmake_minimum_required(VERSION 2.8.3)
project(image_pkg)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS sensor_msgs cv_bridge roscpp std_msgs image_transport)
find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES image_pkg
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
 ${catkin_INCLUDE_DIRS}
)

add_executable(histogram_local
        src/histogram_local.cpp
        )
target_link_libraries(histogram_local
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})

add_executable(histogram_camera
        src/histogram_camera.cpp
        )
target_link_libraries(histogram_camera
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})
