#include "chemestry_robotics/molecule.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "hydrochloric");
  ros::NodeHandle nh;
  Atom *atom1 = new Atom("robot2", nh);
  atom1->rotate(VEL_ANGULAR, -1 * PI);
  return 0;
}
