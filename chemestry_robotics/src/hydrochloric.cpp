#include "chemestry_robotics/atom.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "hydrochloric");

  ros::NodeHandle nh;

  Atom *atom1 = new Atom("robot0", nh);

  atom1->moveToPoint(1, 1, 2, 2);

  return 0;
}
