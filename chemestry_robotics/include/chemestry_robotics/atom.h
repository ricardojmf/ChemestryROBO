#ifndef ATOM_H
#define ATOM_H

#include "chemestry_robotics/chrlibs.h"

class Atom
{
  ros::Publisher atomPublisher;

  string name;

public:
  //Public main constructor
  Atom(string name, ros::NodeHandle &nodeHandle);

  //Motion functions
  void moveToPoint(double newX, double newY, double vX, double vY);
  void rotateangle(double newT);
}
#endif