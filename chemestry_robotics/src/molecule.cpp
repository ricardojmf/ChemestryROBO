#include "chemestry_robotics/molecule.h"

Molecule::Molecule(string name)
{
  this->name = name;
}

void Molecule::addAtom(Atom* atom)
{
  this->atoms.push_back(atom);
}

void Molecule::moveFront()
{
  ros::Rate rate(2);

  while(ros::ok)
  {
    for(unsigned int i = 0; i < this->atoms.size(); i++)
    {
      //atoms[i]->moveFrontSwarm(VEL_LINEAR);
    }
    rate.sleep();
  }

}

void Molecule::rotate()
{

  ros::Rate rate(2);

  while(ros::ok)
  {
    for(unsigned int i = 0; i < this->atoms.size(); i++)
    {
      //atoms[i]->rotateSwarm(VEL_ANGULAR);
    }
    rate.sleep();
  }
}

/*
void Molecule::moveRandom()
{
  srand(time(0));
  ros::Rate rate(2);

	while(ros::ok)
  {

    double vx = double(rand())/double(RAND_MAX);
    double vz = double(2 * double(rand())/double(RAND_MAX) - 1);


    for(unsigned int i = 0; i < this->atoms.size(); i++)
    {
      atoms[i]->moveRandom(vx, vz);
    }
    rate.sleep();
  }
}
*/
