cmake_minimum_required(VERSION 2.8.3)
project(image_pkg)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS sensor_msgs cv_bridge roscpp std_msgs image_transport)
find_package(OpenCV 3.4.0 REQUIRED)

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

add_executable(filter
        src/filter.cpp
        )
target_link_libraries(filter
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})

add_executable(jiesi
        src/jiesi.cpp
        )
target_link_libraries(jiesi
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})

add_executable(edge_detect
        src/edge_detect.cpp
        )
target_link_libraries(edge_detect
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})

add_executable(rgb_detect
        src/rgb_detect.cpp
        )
target_link_libraries(rgb_detect
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})

add_executable(parking
        src/parking.cpp
        )
target_link_libraries(parking
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})

add_executable(humanfollow
        src/humanfollow.cpp
        )
target_link_libraries(humanfollow
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})

add_executable(sketlon
        src/sketlon.cpp
        )
target_link_libraries(sketlon
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})

add_executable(h_parking
        src/h_parking.cpp
        )
target_link_libraries(h_parking
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS})