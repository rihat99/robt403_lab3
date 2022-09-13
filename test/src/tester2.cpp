#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "dynamixel_msgs/JointState.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */

double tar_pos = 1.33;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "tester");

  ros::NodeHandle n;


	ros::Publisher pub = n.advertise<std_msgs::Float64>("/end/command", 1000);

	//ros::Rate loop_rate(10);

	while (ros::ok()) {
		ros::spinOnce();

		std_msgs::Float64 msg;
		msg.data = -0.7;
		pub.publish(msg);

		ros::Duration(1.5).sleep();

		msg.data = 0.3;
		pub.publish(msg);

		ros::Duration(1.5).sleep();

		//loop_rate.sleep();

	}


  return 0;
}
