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
include CMakeFiles/steer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/steer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/steer.dir/flags.make

CMakeFiles/steer.dir/src/BubbleRob.cpp.o: CMakeFiles/steer.dir/flags.make
CMakeFiles/steer.dir/src/BubbleRob.cpp.o: ../src/BubbleRob.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/steer.dir/src/BubbleRob.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/steer.dir/src/BubbleRob.cpp.o -c /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/src/BubbleRob.cpp

CMakeFiles/steer.dir/src/BubbleRob.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/steer.dir/src/BubbleRob.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/src/BubbleRob.cpp > CMakeFiles/steer.dir/src/BubbleRob.cpp.i

CMakeFiles/steer.dir/src/BubbleRob.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/steer.dir/src/BubbleRob.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/src/BubbleRob.cpp -o CMakeFiles/steer.dir/src/BubbleRob.cpp.s

# Object files for target steer
steer_OBJECTS = \
"CMakeFiles/steer.dir/src/BubbleRob.cpp.o"

# External object files for target steer
steer_EXTERNAL_OBJECTS =

devel/lib/vrep_pkg/steer: CMakeFiles/steer.dir/src/BubbleRob.cpp.o
devel/lib/vrep_pkg/steer: CMakeFiles/steer.dir/build.make
devel/lib/vrep_pkg/steer: CMakeFiles/steer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable devel/lib/vrep_pkg/steer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/steer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/steer.dir/build: devel/lib/vrep_pkg/steer

.PHONY : CMakeFiles/steer.dir/build

CMakeFiles/steer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/steer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/steer.dir/clean

CMakeFiles/steer.dir/depend:
	cd /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chrisliu/ROS/vrep_ws/src/vrep_pkg /home/chrisliu/ROS/vrep_ws/src/vrep_pkg /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug /home/chrisliu/ROS/vrep_ws/src/vrep_pkg/cmake-build-debug/CMakeFiles/steer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/steer.dir/depend

