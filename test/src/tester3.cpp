#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "dynamixel_msgs/JointState.h"
#include <cmath>

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */

double tar_pos = 1.33;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "tester");

  ros::NodeHandle n;


	ros::Publisher pub = n.advertise<std_msgs::Float64>("/end/command", 1000);

	ros::Rate loop_rate(60);

	while (ros::ok()) {
		ros::spinOnce();

		tar_pos = 0.5 * std::sin(ros::Time::now().toSec()* 2) + 0;

		std_msgs::Float64 msg;
		msg.data = tar_pos;
		pub.publish(msg);

		

		loop_rate.sleep();

	}


  return 0;
}
