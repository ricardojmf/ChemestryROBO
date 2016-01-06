#ifndef ATOM_H
#define ATOM_H

#include "chemestry_robotics/chrlibs.h"

class Atom
{
  ros::Publisher atomPublisher;
  string name;

public:
  Atom(string name, ros::NodeHandle &nodeHandle);
  void moveFront(double vl, double distance);
  void rotate(double va, double angle);
  void moveFrontSwarm(double vl);
  void rotateSwarm(double va);
};

#endif
