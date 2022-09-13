#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "dynamixel_msgs/JointState.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */

double cur_pos = -1.33, tar_pos = -1.33;

void stateCallback(const dynamixel_msgs::JointState& msg)
{
  cur_pos = msg.current_pos;
}

void moveCallback(const std_msgs::Float64& msg)
{
  tar_pos = msg.data;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "tester");

  ros::NodeHandle n;
 
  ros::Subscriber sub = n.subscribe("joint2/state", 1000, stateCallback);


	ros::Subscriber sub2 = n.subscribe("tester", 1000, moveCallback);

	ros::Publisher pub = n.advertise<std_msgs::Float64>("/joint2/command", 1000);

	ros::Rate loop_rate(10);

	while (ros::ok()) {
		ros::spinOnce();

		if (tar_pos < cur_pos) tar_pos = cur_pos;

		std_msgs::Float64 msg;
		msg.data = tar_pos;
		pub.publish(msg);

		loop_rate.sleep();

	}


  return 0;
}
