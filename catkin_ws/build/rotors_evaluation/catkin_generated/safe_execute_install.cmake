execute_process(COMMAND "/home/chris/catkin_ws/build/rotors_evaluation/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/chris/catkin_ws/build/rotors_evaluation/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
