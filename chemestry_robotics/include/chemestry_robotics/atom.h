#ifndef ATOM_H
#define ATOM_H

#include "chemestry_robotics/chrlibs.h"

class Atom
{
  ros::Publisher atomPublisher;
  string name;

public:
  Atom(string name, ros::NodeHandle &nodeHandle);
  void moveRandom(double linear_x, double linear_z);
};
#endif
