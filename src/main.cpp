//Cemil Can Saylan - 15/12/2019

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cmath>
#include "Atom.h"
#include "Cell.h"
#include "Molecule.h"


int main(int argc, char const *argv[])
{
    Molecule M("../data/16fuCyt.xyz");
    M.assignCell("../data/cell_file");
    M.calcDensity();
    cout << "volume = "<< M.getVolume() <<endl;
    cout << "density = "<< M.getDensity() <<endl;
    M.printCell();
    M.calcTotMass();
    M.printMol();
    M.findCenter();
    M.center2origin();
    M.printMol();
    for (int i = 0; i < 628; i++)
    {
        M.rotZ(0.01);
        M.writeMol("../data/rotated.xyz");
    }
    M.findCenter();


    return 0;
}
