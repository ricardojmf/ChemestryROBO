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
  void moveFront(double vl, double distance);
  void rotate(double va, double angle);
};



#endif
