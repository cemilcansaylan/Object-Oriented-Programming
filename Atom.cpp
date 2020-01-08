//Cemil Can Saylan - 15/12/2019
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cmath>
#include "Atom.h"

using namespace std;

Atom::Atom()
{
    e = "_"; x=0; y=0; z=0;
}

Atom::Atom(string E, double X, double Y, double Z)
{
    e = E; x = X; y = Y; z = Z;
}

Atom::~Atom()
{
    
}

void Atom::printAtom()
{
    cout<<e<<" "<<x<<" "<<y<<" "<<z<<endl;
}

void Atom::rotX(double radVal)
{
    x = this->x;
    y = (cos(radVal)*this->y)-(sin(radVal)*this->z);
    z = (sin(radVal)*this->y)+(cos(radVal)*this->z);
}

void Atom::rotY(double radVal)
{
    x = (cos(radVal)*this->x)+(sin(radVal)*this->z);
    y = this->y;
    z = -(sin(radVal)*this->y)+(cos(radVal)*this->z);
}

void Atom::rotZ(double radVal)
{
    x = (cos(radVal)*this->x)-(sin(radVal)*this->y);
    y = (sin(radVal)*this->x)+(cos(radVal)*this->y);
    z = this->z;
}
