# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/chrisliu/software/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/chrisliu/software/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chrisliu/ROS/vrep_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug

# Include any dependencies generated for this target.
include quadcopter/CMakeFiles/main_node.dir/depend.make

# Include the progress variables for this target.
include quadcopter/CMakeFiles/main_node.dir/progress.make

# Include the compile flags for this target's objects.
include quadcopter/CMakeFiles/main_node.dir/flags.make

quadcopter/CMakeFiles/main_node.dir/src/main_node.cpp.o: quadcopter/CMakeFiles/main_node.dir/flags.make
quadcopter/CMakeFiles/main_node.dir/src/main_node.cpp.o: ../quadcopter/src/main_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chrisliu/ROS/vrep_ws/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object quadcopter/CMakeFiles/main_node.dir/src/main_node.cpp.o"
	cd /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug/quadcopter && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_node.dir/src/main_node.cpp.o -c /home/chrisliu/ROS/vrep_ws/src/quadcopter/src/main_node.cpp

quadcopter/CMakeFiles/main_node.dir/src/main_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_node.dir/src/main_node.cpp.i"
	cd /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug/quadcopter && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chrisliu/ROS/vrep_ws/src/quadcopter/src/main_node.cpp > CMakeFiles/main_node.dir/src/main_node.cpp.i

quadcopter/CMakeFiles/main_node.dir/src/main_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_node.dir/src/main_node.cpp.s"
	cd /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug/quadcopter && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chrisliu/ROS/vrep_ws/src/quadcopter/src/main_node.cpp -o CMakeFiles/main_node.dir/src/main_node.cpp.s

# Object files for target main_node
main_node_OBJECTS = \
"CMakeFiles/main_node.dir/src/main_node.cpp.o"

# External object files for target main_node
main_node_EXTERNAL_OBJECTS =

devel/lib/quadcopter/main_node: quadcopter/CMakeFiles/main_node.dir/src/main_node.cpp.o
devel/lib/quadcopter/main_node: quadcopter/CMakeFiles/main_node.dir/build.make
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/libimage_transport.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/libmessage_filters.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/libclass_loader.so
devel/lib/quadcopter/main_node: /usr/lib/libPocoFoundation.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libdl.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/libroscpp.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libboost_signals.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/libxmlrpcpp.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/libroslib.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/librospack.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libpython2.7.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libtinyxml.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/libcv_bridge.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_core3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgproc3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgcodecs3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/librosconsole.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/libroscpp_serialization.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/librostime.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/libcpp_common.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/quadcopter/main_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_stitching3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_superres3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_videostab3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_aruco3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_bgsegm3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_bioinspired3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_ccalib3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_cvv3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_dpm3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_face3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_fuzzy3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_hdf3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_img_hash3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_line_descriptor3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_optflow3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_reg3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_rgbd3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_saliency3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_stereo3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_structured_light3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_surface_matching3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_tracking3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_xfeatures2d3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_ximgproc3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_xobjdetect3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_xphoto3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_shape3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_photo3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_datasets3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_plot3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_text3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_dnn3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_ml3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_video3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_calib3d3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_features2d3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_highgui3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_videoio3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_viz3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_phase_unwrapping3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_flann3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgcodecs3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_objdetect3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgproc3.so.3.3.1
devel/lib/quadcopter/main_node: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_core3.so.3.3.1
devel/lib/quadcopter/main_node: quadcopter/CMakeFiles/main_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chrisliu/ROS/vrep_ws/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../devel/lib/quadcopter/main_node"
	cd /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug/quadcopter && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
quadcopter/CMakeFiles/main_node.dir/build: devel/lib/quadcopter/main_node

.PHONY : quadcopter/CMakeFiles/main_node.dir/build

quadcopter/CMakeFiles/main_node.dir/clean:
	cd /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug/quadcopter && $(CMAKE_COMMAND) -P CMakeFiles/main_node.dir/cmake_clean.cmake
.PHONY : quadcopter/CMakeFiles/main_node.dir/clean

quadcopter/CMakeFiles/main_node.dir/depend:
	cd /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chrisliu/ROS/vrep_ws/src /home/chrisliu/ROS/vrep_ws/src/quadcopter /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug/quadcopter /home/chrisliu/ROS/vrep_ws/src/cmake-build-debug/quadcopter/CMakeFiles/main_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : quadcopter/CMakeFiles/main_node.dir/depend

