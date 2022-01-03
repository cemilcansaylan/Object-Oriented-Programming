//Cemil Can Saylan - 15/12/2019

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cmath>
#include <map>
#include "Atom.h"
#include "Cell.h"
#include "Molecule.h"

using namespace std;

Molecule::Molecule(string filename)
{
    ifstream file(filename);

    string line;
    getline(file, line);
    nAtom = stoi(line);

    getline(file,line);
    comment = line;
    
    atoms = new Atom [nAtom];
    for (int i = 0; i < nAtom; i++)
    {
        getline(file,line);
        Atom temp(line.substr(1,1),stod(line.substr(2,12)),stod(line.substr(15,12)),stod(line.substr(26,12)));
        atoms[i] = temp;
    }
       
}

void Molecule::assignCell(string filename)
{
    Cell temp(filename);
    for (int i = 0; i < 3; i++)
    {
        this->cell.a1[i]=temp.a1[i];
        this->cell.a2[i]=temp.a2[i];
        this->cell.a3[i]=temp.a3[i];
    }
}

void Molecule::printMol()
{
    cout<<this->nAtom<<endl;
    cout<<this->comment<<endl;
    for (int i = 0; i < this->nAtom; i++)
    {
        this->atoms[i].printAtom();
    }   
}

void Molecule::writeMol(string filename)
{
    ofstream xyz;
    xyz.open(filename,ios_base::app);
    xyz<<this->nAtom<<endl;
    xyz<<this->comment<<endl;
    for (int  i = 0; i < this->nAtom; i++)
    {
        xyz<<this->atoms[i].e<<" "<<this->atoms[i].x<<" "<<this->atoms[i].y<<" "<<this->atoms[i].z<<endl;
    } 
}

void Molecule::findCenter()
{
    double x_center=0;
    for (int i = 0; i < nAtom; i++)
    {
        x_center=x_center + atoms[i].x;
    }
    center[0]=x_center/nAtom;
    
    double y_center=0;
    for (int i = 0; i < nAtom; i++)
    {
        y_center=y_center + atoms[i].y;
    }
    center[1]=y_center/nAtom;

    double z_center=0;
    for (int i = 0; i < nAtom; i++)
    {
        z_center=z_center + atoms[i].z;
    }
    center[2]=z_center/nAtom;
    
    for (int i = 0; i < 3; i++)
    {
        cout<<center[i]<<" ";
    }
    cout << endl;
    
}

void Molecule::center2origin()
{
    for (int i = 0; i < this->nAtom; i++)
    {
        this->atoms[i].x=this->atoms[i].x-this->center[0];
        this->atoms[i].y=this->atoms[i].y-this->center[1];
        this->atoms[i].z=this->atoms[i].z-this->center[2];
    }
}

void Molecule::rotX(double radVal)
{
    for (int i = 0; i < this->nAtom; i++)
    {
        this->atoms[i].rotX(radVal);
    }
}

void Molecule::rotY(double radVal)
{
    for (int i = 0; i < this->nAtom; i++)
    {
        this->atoms[i].rotY(radVal);
    }
}

void Molecule::rotZ(double radVal)
{
    for (int i = 0; i < this->nAtom; i++)
    {
        this->atoms[i].rotZ(radVal);
    }
}

double Molecule::getVolume()
{
    volume = this->cell.getVolume();
    return volume;
}

void Molecule::printCell()
{
    this->cell.printCell();  
}

void Molecule::calcTotMass()
{

    map<string,double> mass_map = {
                { "H", 1.008 },
                { "C", 12.011 },
                { "N", 14.007 },
                { "O", 15.999 } 
    };


    totalMass = 0;
    for (int i = 0; i < nAtom; i++)
    {
        totalMass += mass_map[this->atoms[i].e];
        
    }

    /*
    
    /// Optional way///


    totalMass = 0;
    for (int i = 0; i < nAtom; i++)
    {
        if (this->atoms[i].e=="H")
        {
            totalMass=totalMass+1.008;
        }
        else if (this->atoms[i].e=="C")
        {
            totalMass=totalMass+12.011;
        }
        else if (this->atoms[i].e=="N")
        {
            totalMass=totalMass+14.007;
        }
        else if (this->atoms[i].e=="O")
        {
            totalMass=totalMass+15.999;
        }
    }
    */
}

void Molecule::calcDensity()
{
    volume = this->getVolume();
    this->calcTotMass();
    this->density=this->totalMass/this->volume;
}

double Molecule::getDensity()
{
    this->calcDensity();
    return density;
}

Molecule::~Molecule()
{
    delete[] atoms;
}
