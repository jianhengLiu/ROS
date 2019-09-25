#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/chrisliu/ROS/vrep_ws/src/teleop_twist_keyboard"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/chrisliu/ROS/vrep_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/chrisliu/ROS/vrep_ws/install/lib/python2.7/dist-packages:/home/chrisliu/ROS/vrep_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/chrisliu/ROS/vrep_ws/build" \
    "/usr/bin/python" \
    "/home/chrisliu/ROS/vrep_ws/src/teleop_twist_keyboard/setup.py" \
    build --build-base "/home/chrisliu/ROS/vrep_ws/build/teleop_twist_keyboard" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/chrisliu/ROS/vrep_ws/install" --install-scripts="/home/chrisliu/ROS/vrep_ws/install/bin"
