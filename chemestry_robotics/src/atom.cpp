#include "chemestry_robotics/atom.h"

Atom::Atom(string name, ros::NodeHandle &nodeHandle)
{
  this->name = name;
  string topic = name + "/" + CMD_VEL;
  this->atomPublisher = nodeHandle.advertise <geometry_msgs::Twist > (topic.c_str(), 1000);
}

void Atom::moveFrontSwarm(double vl)
{
  geometry_msgs::Twist msg;
  msg.linear.x = vl;
  atomPublisher.publish(msg);
  ROS_INFO_STREAM("Sending random velocity: " << "linear=" << msg.linear.x);
}

void Atom::rotateSwarm(double va)
{
    geometry_msgs::Twist msg;
    msg.angular.z = va;
    atomPublisher.publish(msg);
    ROS_INFO_STREAM("Sending random velocity: " << "linear=" << msg.angular.z);
}

void Atom::moveFront(double vl, double distance)
{
  double lx = 0;

  ros::Rate rate(1);
  while(ros::ok())
  {
    geometry_msgs::Twist msg;

    if(lx < (distance))
    {
      msg.linear.x = vl;
      lx += vl;
      atomPublisher.publish(msg);
    }
    else
    {
      msg.linear.x = 0;
      atomPublisher.publish(msg);
      break;
    }

    ROS_INFO_STREAM("Sending random velocity: " << "linear=" << msg.linear.x);
    ROS_INFO_STREAM("INFO x=" << lx);

    rate.sleep();
  }
}

void Atom::rotate(double va, double angle)
{
  double ax = 0;

  ros::Rate rate(1);
  while(ros::ok())
  {
    geometry_msgs::Twist msg;

    if(ax < abs(angle))
    {
      msg.angular.z = va;
      ax += va;
      atomPublisher.publish(msg);
    }
    else
    {
      msg.angular.z = 0;
      atomPublisher.publish(msg);
      break;
    }

    ROS_INFO_STREAM("Sending random velocity: " << "linear=" << msg.linear.x);
    ROS_INFO_STREAM("INFO x=" << ax);

    rate.sleep();
  }
}
