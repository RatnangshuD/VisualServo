#!/usr/bin/env bash

# This script is called by the xsarm_rpi4_boot.service file when
# the Raspberry Pi boots. It just sources the ROS related workspaces
# and launches the xsarm_joy launch file. It is populated with the correct commands
# from the xsarm_rpi4_install.sh installation script.

source /opt/ros/noetic/setup.bash
source /home/fac/interbotix_ws/devel/setup.bash
roslaunch interbotix_xsarm_joy xsarm_joy.launch use_rviz:=false robot_model:=rx200
