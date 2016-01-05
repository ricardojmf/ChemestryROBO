#include "chemestry_robotics/atom.h"

Atom::Atom(string name, ros::NodeHandle &nodeHandle)
{
  this->name = name;
  string topic = name + "/" + CMD_VEL;
  this->atomPublisher = nodeHandle.advertise <geometry_msgs::Twist > (topic.c_str(), 1000);
}

void Atom::moveRandom(double linear_x, double linear_z)
{
		geometry_msgs::Twist msg;
		msg.linear.x = linear_x;
		msg.angular.z = linear_z;
		atomPublisher.publish(msg);
		ROS_INFO_STREAM("Sending random velocity: " << "linear=" << msg.linear.x << "angular=" << msg.angular.z);
}
