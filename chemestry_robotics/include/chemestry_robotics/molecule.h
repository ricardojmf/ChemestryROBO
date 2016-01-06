#ifndef MOLECULE_H
#define MOLECULE_H

#include "chemestry_robotics/atom.h"

class Molecule
{
  vector<Atom*> atoms;
  string name;

public:
  Molecule(string name);
  void addAtom(Atom* atom);
  void moveFront();
  void rotate();
};



#endif
