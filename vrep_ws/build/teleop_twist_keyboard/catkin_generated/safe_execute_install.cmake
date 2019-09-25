execute_process(COMMAND "/home/chrisliu/ROS/vrep_ws/build/teleop_twist_keyboard/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/chrisliu/ROS/vrep_ws/build/teleop_twist_keyboard/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
