#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_state/robot_state.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/Int16.h>

int regIdx = 4;

void callback(const std_msgs::Int16 &msg){
//	ROS_INFO_STREAM(msg);
	regIdx = msg.data;
}

geometry_msgs::Pose getPosition(int id);
std::vector<double> getJointAngles(int id);
int main(int argc, char** argv){
    ros::init(argc,argv,"rals_moveit_tutorial");
    
    ros::NodeHandle nh;
    ros::Rate rate(10.0);
    
    ros::Subscriber subs = nh.subscribe("/ball_loc", 1, callback);
    
    ros::AsyncSpinner spinner(1);
    
    spinner.start();
    
    static const std::string PLANNING_GRP = "interbotix_arm";
    
    moveit::planning_interface::MoveGroupInterface mgi(PLANNING_GRP);
    ROS_INFO_STREAM(mgi.ROBOT_DESCRIPTION);
    moveit::planning_interface::PlanningSceneInterface mgi_interface;
    
    // initial position target
    std::vector<double> q { 0.0, 0.0, 0.0, 0.0, M_PI/2.0};
    //mgi.setNamedTarget("Home");
    mgi.setJointValueTarget(q);
    mgi.move();
    
    auto H0 = mgi.getCurrentPose("rx200/ee_arm_link");
    ROS_INFO_STREAM("Initial Pose: \n" << H0);
    
    const moveit::core::JointModelGroup* jnt_mdl_grp = mgi.getCurrentState()->getJointModelGroup(PLANNING_GRP);
    
    geometry_msgs::Pose H;
    int prevID = 4;
    while (1){
        if (regIdx < 0)
            regIdx = prevID;
    	//H = getPosition(regIdx);
    	auto q = getJointAngles(regIdx);
    	prevID = regIdx;
    	
    	// moveit planner
    	//mgi.setPoseTarget(H);
    	mgi.setJointValueTarget(q);
    	moveit::planning_interface::MoveGroupInterface::Plan planner;
    	
    	bool success = (mgi.plan(planner)) == moveit::planning_interface::MoveItErrorCode::SUCCESS;
    	mgi.move();
    	//ros::Duration(3.0).sleep();
    	ros::spinOnce();
    }
//    
//    float scale = 5000.0;
//    H1.orientation = H0.pose.orientation;
//    H1.position.x = H0.pose.position.x;
//    H1.position.y = H0.pose.position.y ;//+ x/scale;
//    H1.position.z = H0.pose.position.z + y/scale;
//   
//    //mgi.setPoseTarget(H1);
//    //mgi.setPositionTarget(0.35, 0.037, 0.3730);
//    mgi.setPositionTarget( H1.position.x, H1.position.y, H1.position.z);
//    
//    moveit::planning_interface::MoveGroupInterface::Plan planner;
//    
//    ROS_INFO_STREAM("Postion Target: \n" << H1);
//    
//    bool success = (mgi.plan(planner)) == moveit::planning_interface::MoveItErrorCode::SUCCESS;
//    
//    ROS_INFO_NAMED("tutorial", "Plan 1 is %s", success ? "Succeded": "Failed");
//    if (success){
//    	ROS_INFO_STREAM("EXECUTING YOUR INSTRUCTIONS...");
//    	mgi.execute(planner);
//    	ROS_INFO_STREAM("EXECUTED YOUR INSTRUCTIONS...");
//    }
//    else {
//    	ROS_WARN_STREAM("Could not find a plan to execute the given command");
//    	ros::shutdown();
//    }
//    	
//    ROS_INFO_STREAM("wAITING FOR ROBOT TO COOL DOWN!!!");
//    
//    ros::Duration(5).sleep();
//    
//    mgi.setNamedTarget("Home");
//    
//    mgi.move(); 
//    
    
    ros::shutdown();
    return 0;
}

std::vector<double> getJointAngles(int id){
    std::vector<double> q { 0.0, 0.0, 0.0, 0.0, M_PI/2.0};
    int n = 5;
    int cid = n/2;
    int i = id % n;
    int j = id / n;
    q[0] = M_PI*(i- cid)/16.0;
    q[2] = M_PI*(j- cid)/16.0;
    q[3] = -q[2];
    
    return q;
}
geometry_msgs::Pose getPosition(int id){
    geometry_msgs::Pose H;
    if (id == 0){
	    H.position.x = 0.302777;
	    H.position.y = -0.130891;
	    H.position.z = 0.402771;
	    H.orientation.x = 0.00170935;
	    H.orientation.y = 0.00826182;
	    H.orientation.z = -0.2026;
	    H.orientation.w = 0.979225;
	} else if (id == 1){
	    H.position.x = 0.329576;
	    H.position.y = -0.013658;
	    H.position.z = 0.402771;
	    H.orientation.x = 0.000174703;
	    H.orientation.y = 0.00843499;
	    H.orientation.z = -0.0207065;
	    H.orientation.w = 0.99975;
	} else if (id == 2){
	    H.position.x = 0.295726;
	    H.position.y = -0.147154;
	    H.position.z = 0.402265;
	    H.orientation.x = 0.00210599;
	    H.orientation.y = 0.00895958;
	    H.orientation.z = 0.228809;
	    H.orientation.w = 0.973428;
	} else if (id == 3){
	    H.position.x = 0.329724;
	    H.position.y = -0.145552;
	    H.position.z = 0.283925;
	    H.orientation.x = 0.00696286;
	    H.orientation.y = 0.0330149;
	    H.orientation.z = -0.206243;
	    H.orientation.w = 0.977919;
	} else if (id == 4){
	    H.position.x = 0.359992;
	    H.position.y = -0.0138123;
	    H.position.z = 0.293169;
	    H.orientation.x = 0.000411735;
	    H.orientation.y = 0.0214701;
	    H.orientation.z = -0.0191692;
	    H.orientation.w = 0.999586;
	} else if (id == 5){
	    H.position.x = 0.337892;
	    H.position.y = 0.123831;
	    H.position.z = 0.28503;
	    H.orientation.x = -0.005628;
	    H.orientation.y = 0.0317125;
	    H.orientation.z = 0.174648;
	    H.orientation.w = 0.984104;
	} else if (id == 6){
	    H.position.x = 0.301706;
	    H.position.y = -0.134846;
	    H.position.z = 0.208025;
	    H.orientation.x = -0.00160002;
	    H.orientation.y = -0.00750109;
	    H.orientation.z = -0.208606;
	    H.orientation.w = 0.97797;
	} else if (id == 7){
	    H.position.x = 0.330426;
	    H.position.y = 0.00101374;
	    H.position.z = 0.200901;
	    H.orientation.x = -2.58828e-05;
	    H.orientation.y = 0.016873;
	    H.orientation.z = 0.00153376;
	    H.orientation.w = 0.999856;
	} else if (id == 8){
	    H.position.x = 0.303;
	    H.position.y = 0.131539;
	    H.position.z = 0.207592;
	    H.orientation.x = 0.00140375;
	    H.orientation.y = -0.00675863;
	    H.orientation.z = 0.203353;
	    H.orientation.w = 0.979081;
	} 
	else{
	    H.position.x = 0.359992;
	    H.position.y = -0.0138123;
	    H.position.z = 0.293169;
	    H.orientation.x = 0.000411735;
	    H.orientation.y = 0.0214701;
	    H.orientation.z = -0.0191692;
	    H.orientation.w = 0.999586;
	}
	return H;
}
