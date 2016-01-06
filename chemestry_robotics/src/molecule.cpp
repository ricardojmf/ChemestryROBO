#include "chemestry_robotics/molecule.h"

Molecule::Molecule(string name)
{
  this->name = name;
}

void Molecule::addAtom(Atom* atom)
{
  this->atoms.push_back(atom);
}

void Molecule::moveFront(double vl, double distance)
{
  double lx = 0;

  ros::Rate rate(1);

  while(ros::ok)
  {
    if(lx < (distance))
    {
      for(unsigned int i = 0; i < this->atoms.size(); i++)
      {
        atoms[i]->moveFrontSwarm(vl);
      }
      lx += vl;
    }
    else
    {
      for(unsigned int i = 0; i < this->atoms.size(); i++)
      {
        atoms[i]->moveFrontSwarm(0);
      }
      break;
    }
    rate.sleep();
  }
}

void Molecule::rotate(double va, double angle)
{
  double ax = 0;
  ros::Rate rate(1);
  while(ros::ok())
  {
    geometry_msgs::Twist msg;
    if(ax < abs(angle))
    {
      for(unsigned int i = 0; i < this->atoms.size(); i++)
      {
        atoms[i]->rotateSwarm(va);
      }
      ax += va;
    }
    else
    {
      for(unsigned int i = 0; i < this->atoms.size(); i++)
      {
        atoms[i]->rotateSwarm(0);
      }
      break;
    }
    rate.sleep();
  }
}
