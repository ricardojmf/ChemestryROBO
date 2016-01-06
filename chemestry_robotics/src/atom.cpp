#include "chemestry_robotics/atom.h"

Atom::Atom(string name, ros::NodeHandle &nodeHandle)
{
  this->name = name;
  string topic = name + "/" + CMD_VEL;
  this->atomPublisher = nodeHandle.advertise <geometry_msgs::Twist > (topic.c_str(), 1000);
}

void Atom::moveFront(double vl, double distance)
{
  double lx = 0;
  int counter = 0;

  ros::Rate rate(1);
  while(ros::ok())
  {
    geometry_msgs::Twist msg;

    if(lx < (distance + 0.5))
    {
      msg.linear.x = vl;
      lx += vl;
      counter++;
      atomPublisher.publish(msg);
      ROS_INFO_STREAM("Sending random velocity: " << "linear=" << msg.linear.x);
      ROS_INFO_STREAM("INFO x=" << lx << " counter=" << counter);
      atomPublisher.publish(msg);
    }
    else
    {
      msg.linear.x = 0;
      counter++;
      atomPublisher.publish(msg);
      break;
    }

    ROS_INFO_STREAM("Sending random velocity: " << "linear=" << msg.linear.x);
    ROS_INFO_STREAM("INFO x=" << lx << " counter=" << counter);

    rate.sleep();
  }
}

void Atom::rotate(double va, double angle)
{
  double ax = 0;
  int counter = 0;

  ros::Rate rate(1);
  while(ros::ok())
  {
    geometry_msgs::Twist msg;

    if(ax < abs(angle))
    {
      msg.angular.z = va;
      ax += va;
      counter++;
      atomPublisher.publish(msg);
      ROS_INFO_STREAM("Sending random velocity: " << "linear=" << msg.angular.z);
      ROS_INFO_STREAM("INFO x=" << ax << " counter=" << counter);
      atomPublisher.publish(msg);
    }
    else
    {
      msg.angular.z = 0;
      counter++;
      atomPublisher.publish(msg);
      break;
    }

    ROS_INFO_STREAM("Sending random velocity: " << "linear=" << msg.linear.x);
    ROS_INFO_STREAM("INFO x=" << ax << " counter=" << counter);

    rate.sleep();
  }
}
