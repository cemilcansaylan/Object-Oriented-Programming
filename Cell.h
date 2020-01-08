//Cemil Can Saylan - 15/12/2019

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cmath> 

using namespace std;

class Cell
{
public:
    double * a1;
    double * a2;
    double * a3;
    double Volume;
public:
    Cell();
    Cell(string filename);
    ~Cell();
    virtual void printCell();
    void calculateVolume();
    virtual double getVolume();
};

#endif
