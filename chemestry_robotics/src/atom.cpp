#include "chemestry_robotics/atom.h"

Atom::Atom(string name, ros::NodeHandle &nodeHandle)
{
  this->name = name;
  this->atomPublisher = nodeHandle.advertise <geometry_msgs::Twist > (topicCreation(this->name, CMD_VEL), 1000);
}
