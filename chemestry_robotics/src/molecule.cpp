#include "chemestry_robotics/molecule.h"

Molecule::Molecule(string name)
{
  this->name = name;
}

void Molecule::addAtom(Atom* atom)
{
  this->atoms.push_back(atom);
}

void Molecule::moveRandom()
{
  srand(time(0));
  ros::Rate rate(2);

  double vx = double(rand())/double(RAND_MAX);
  double vz = double(2 * double(rand())/double(RAND_MAX) - 1);

	while(ros::ok)
  {
    for(unsigned int i = 0; i < this->atoms.size(); i++)
    {
      atoms[i]->moveRandom(vx, vz);
    }
    rate.sleep();
  }
}
