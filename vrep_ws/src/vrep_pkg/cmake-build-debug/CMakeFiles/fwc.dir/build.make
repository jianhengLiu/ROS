# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/chrisliu/ROS/vrep_ws/src/vrep_pkg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fwc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fwc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fwc.dir/flags.make

CMakeFiles/fwc.dir/src/FourWheelControl.cpp.o: CMakeFiles/fwc.dir/flags.make
CMakeFiles/fwc.dir/src/FourWheelControl.cpp.o: ../src/FourWheelControl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fwc.dir/src/FourWheelControl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fwc.dir/src/FourWheelControl.cpp.o -c /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/src/FourWheelControl.cpp

CMakeFiles/fwc.dir/src/FourWheelControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fwc.dir/src/FourWheelControl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/src/FourWheelControl.cpp > CMakeFiles/fwc.dir/src/FourWheelControl.cpp.i

CMakeFiles/fwc.dir/src/FourWheelControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fwc.dir/src/FourWheelControl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/src/FourWheelControl.cpp -o CMakeFiles/fwc.dir/src/FourWheelControl.cpp.s

# Object files for target fwc
fwc_OBJECTS = \
"CMakeFiles/fwc.dir/src/FourWheelControl.cpp.o"

# External object files for target fwc
fwc_EXTERNAL_OBJECTS =

devel/lib/libfwc.so: CMakeFiles/fwc.dir/src/FourWheelControl.cpp.o
devel/lib/libfwc.so: CMakeFiles/fwc.dir/build.make
devel/lib/libfwc.so: CMakeFiles/fwc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library devel/lib/libfwc.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fwc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fwc.dir/build: devel/lib/libfwc.so

.PHONY : CMakeFiles/fwc.dir/build

CMakeFiles/fwc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fwc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fwc.dir/clean

CMakeFiles/fwc.dir/depend:
	cd /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chrisliu/ROS/vrep_ws/src/vrep_pkg /home/chrisliu/ROS/vrep_ws/src/vrep_pkg /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug/CMakeFiles/fwc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fwc.dir/depend

