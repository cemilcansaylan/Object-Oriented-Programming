//Cemil Can Saylan - 15/12/2019

#ifndef ATOM_H
#define ATOM_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cmath>

using namespace std;

class Atom
{
public:
    string e;
    double x;
    double y;
    double z;
public:
    Atom();
    Atom(string E, double X, double Y, double Z);
    ~Atom();
    void printAtom();
    virtual void rotX(double radVal);
    virtual void rotY(double radVal);
    virtual void rotZ(double radVal);
};



#endif
