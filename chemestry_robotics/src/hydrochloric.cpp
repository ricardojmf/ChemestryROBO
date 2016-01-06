#include "chemestry_robotics/molecule.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "hydrochloric");
  ros::NodeHandle nh;

  Atom *atom1 = new Atom("robot0", nh);
  Atom *atom2 = new Atom("robot1", nh);
  Atom *atom3 = new Atom("robot2", nh);
  Atom *atom4 = new Atom("robot3", nh);
  Atom *atom5 = new Atom("robot4", nh);
  Atom *atom6 = new Atom("robot5", nh);
  Atom *atom7 = new Atom("robot6", nh);
  Atom *atom8 = new Atom("robot7", nh);
  Atom *atom9 = new Atom("robot8", nh);

  Molecule *m1 = new Molecule("ch4");
  Molecule *m2 = new Molecule("O2_1");
  Molecule *m3 = new Molecule("O2_2");

  //carregar o ch4
  m1->addAtom(atom1);
  m1->addAtom(atom2);
  m1->addAtom(atom3);
  m1->addAtom(atom4);
  m1->addAtom(atom5);

  // carregar
  m2->addAtom(atom6);
  m2->addAtom(atom7);
  m3->addAtom(atom8);
  m3->addAtom(atom9);

  //:::::::::::::::LEVAR REAGENTE1 PARA O TABULEIRO:::::::::::::::::::::::

  m1->rotate(VEL_ANGULAR, (PI / 2) + VEL_ANGULAR);
  m1->moveFront(VEL_LINEAR, 6 + VEL_LINEAR);

  //:::::::::::::::LEVAR REAGENTE2 PARA O TABULEIRO:::::::::::::::::::::::

  m2->rotate(VEL_ANGULAR, (PI / 2));
  m2->moveFront(VEL_LINEAR, 6);

  m3->rotate(VEL_ANGULAR, (PI / 2));
  m3->moveFront(VEL_LINEAR, 6);

  //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  //REAÇÃO

  atom5->moveFront(VEL_LINEAR, 0.85);
  atom6->moveFront(VEL_LINEAR, 0.45);
  atom8->moveFront(VEL_LINEAR, 0.45);
  atom7->rotate(VEL_ANGULAR, PI - VEL_ANGULAR);
  atom9->rotate(VEL_ANGULAR, PI - VEL_ANGULAR);
  atom7->moveFront(VEL_LINEAR, 0.45);
  atom9->moveFront(VEL_LINEAR, 0.45);
  atom1->rotate(VEL_ANGULAR, 3 * (PI / 2));
  atom1->moveFront(VEL_LINEAR, 8);
  atom4->rotate(VEL_ANGULAR, PI - VEL_ANGULAR);
  atom4->moveFront(VEL_LINEAR, 0.4);
  atom4->rotate(VEL_ANGULAR, PI / 2);
  atom4->moveFront(VEL_LINEAR, 6);
  atom2->rotate(VEL_ANGULAR, PI - VEL_ANGULAR);
  atom2->moveFront(VEL_LINEAR, 0.3);
  atom2->rotate(VEL_ANGULAR, (PI / 2));
  atom2->moveFront(VEL_LINEAR, 4.95);
  atom3->rotate(VEL_ANGULAR, 3 * (PI / 2));
  atom3->moveFront(VEL_LINEAR, 5.1);
  atom5->rotate(VEL_ANGULAR, 3 * (PI / 2));
  atom5->moveFront(VEL_LINEAR, 4.3);
  atom5->rotate(VEL_ANGULAR, PI - VEL_ANGULAR);
  atom7->rotate(VEL_ANGULAR, 3 * (PI / 2));
  atom6->rotate(VEL_ANGULAR, (PI / 2));
  atom8->rotate(VEL_ANGULAR, (PI / 2));

  //FORMAÇÃO dos Produtos da Reação

  /*
  Molecule *m4 = new Molecule("H2O_1");
  Molecule *m5 = new Molecule("H2O_2");
  Molecule *m6 = new Molecule("CO2");

  m4->addAtom(atom2);
  m4->addAtom(atom7);
  m4->addAtom(atom4);

  m5->addAtom(atom3);
  m5->addAtom(atom5);
  m5->addAtom(atom6);

  m6->addAtom(atom1);
  m6->addAtom(atom8);
  m6->addAtom(atom9);
  */
  //Produtos da Reação
  /*
  m6->moveFront(VEL_LINEAR, 1);
  m6->rotate(VEL_ANGULAR, PI / 2);
  m6->moveFront(VEL_LINEAR, 2.5);

  m4->rotate(VEL_ANGULAR, PI);
  m4->moveFront(VEL_LINEAR, 1.5);
  m4->rotate(VEL_ANGULAR, 3 * (PI / 2));
  m4->moveFront(VEL_LINEAR, 2.5);

  m5->rotate(VEL_ANGULAR, PI);
  m5->moveFront(VEL_LINEAR, 7);
  m5->rotate(VEL_ANGULAR, 3 * (PI / 2));
  m5->moveFront(VEL_LINEAR, 1.5);
  */

  
  return 0;
}
