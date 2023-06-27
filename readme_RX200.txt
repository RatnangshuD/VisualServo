##################################################################################################
##################################        Robot Things       #####################################
##################################################################################################
Robot Name:  rx200

arm group name: interbotix_arm
gripper group name: interbotix_gripper

Joint Names: 
  - waist
  - shoulder
  - elbow
  - wrist_angle
  - wrist_rotate
  - gripper
  - left_finger
  - right_finger

END-EFFECTOR:

Holding the camera
nominal position = 0.022m
tight position   = 0.021m 

##################################################################################################
##################################        Launch files       #####################################
##################################################################################################

1. basic robot control

roslaunch interbotix_xsarm_control xsarm_control.launch robot_model:=rx200

1. moveit based control

roslaunch interbotix_xsarm_moveit xsarm_moveit.launch robot_model:=rx200 use_actual:=true dof:=5

2. moveit bsed control -> pops out the cartesan based control	
roslaunch interbotix_xsarm_moveit_interface xsarm_moveit_interface.launch robot_model:=rx200 use_cpp_interface:=true use_actual:=true dof:=5

3. simulation of rx200
roslaunch interbotix_xsarm_moveit_interface xsarm_moveit_interface.launch robot_model:=rx200 use_cpp_interface:=true use_actual:=false use_fake:=true


3. vis test
ROS_NAMESPACE=/rx200 rosrun vis_serv tutorial


4. disable motors
rosservice call /rx200/torque_enable "{cmd_type: 'group', name: 'all', enable: true}"

cmd_type = group -> mean entire arm group
cmd_type = arm -> arrm related


5. Final commands
Terminal 1: roslaunch vis_serv usb_cam-test.launch 
Terminal 2: rosrun ball_tracker ball_tracker.py 
Terminal 3: roslaunch interbotix_xsarm_moveit_interface xsarm_moveit_interface.launch robot_model:=rx200 use_cpp_interface:=true use_actual:=true dof:=5
Terminal 4: ROS_NAMESPACE=/rx200 rosrun vis_serv tutorial
