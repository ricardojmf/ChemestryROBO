#include "chemestry_robotics/atom.h"

Atom::Atom(string name, ros::NodeHandle &nodeHandle)
{
  this->name = name;
  string topic = name + "/" + CMD_VEL;
  this->atomPublisher = nodeHandle.advertise <geometry_msgs::Twist > (topic.c_str(), 1000);
}

void Atom::moveToPoint(double newX, double newY, double vx, double vy)
{
  srand(time(0));

	ros::Rate rate(2);
	while(ros::ok) {
		geometry_msgs::Twist msg;
		msg.linear.x = double(rand())/double(RAND_MAX);
		msg.angular.z = 2 * double(rand())/double(RAND_MAX) - 1;

		atomPublisher.publish(msg);

		ROS_INFO_STREAM("Sending random velocity: " << " linear=" << msg.linear.x
					<< " angular=" << msg.angular.z);

		rate.sleep();
	}
}
