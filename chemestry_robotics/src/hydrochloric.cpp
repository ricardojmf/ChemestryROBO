#include "chemestry_robotics/molecule.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "hydrochloric");
  ros::NodeHandle nh;
  Atom *atom1 = new Atom("robot0", nh);
  Atom *atom2 = new Atom("robot1", nh);
  Atom *atom3 = new Atom("robot2", nh);

  Molecule *m1 = new Molecule("test_molecule");
  m1->addAtom(atom1);
  m1->addAtom(atom2);

  m1->moveRandom();

  return 0;
}
