//Cemil Can Saylan - 15/12/2019

#ifndef MOLUCULE_H
#define MOLECULE_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cmath>
#include "Atom.h"
#include "Cell.h"

using namespace std;

class Atom;
class Cell;

class Molecule: public Atom, public Cell
{
private:
    int nAtom;
    Atom *atoms;
    string comment;
    double center[3];
    Cell cell;
    double volume;
    double totalMass;
    double density;
public:
    Molecule(string filename);
    ~Molecule();
    void assignCell(string filename);
    void printMol();
    void writeMol(string filename);
    void findCenter();
    void center2origin();
    void rotX(double radVal);
    void rotY(double radVal);
    void rotZ(double radVal);
    double getVolume();
    void printCell();
    void calcTotMass();
    void calcDensity();
    double getDensity();
};

#endif
