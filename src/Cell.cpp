//Cemil Can Saylan - 15/12/2019

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cmath> 
#include "Cell.h"

using namespace std;

Cell::Cell()
{
    a1 = new double [3]; // cell file contains 3D information 
    a2 = new double [3];
    a3 = new double [3];
}

Cell::Cell(string filename)
{
    a1 = new double [3];
    a2 = new double [3];
    a3 = new double [3];
    

    double array[3];
    ifstream to_read("cell_file");
    int i = 0;
    while (!to_read.eof())
    {
        double read;
        to_read>>read;
        if (read != 0)
        {
            array[i]=read;
            i++;
        }
        
    }
    
    a1[0] = array[0];
    a2[1] = array[1];
    a3[2] = array[2];

    /*

    ///Optional way///
    
    ifstream file(filename);
    string line;
    getline(file, line);
    int i = 0;
    int j = 0;
    while(!line.empty())
    {
        if (isspace(line[i]))
        {
            a1[j] = stod(line.substr(0,i));
            line.erase(0,i);
            j++;
            i=0;
        }
        i++;
    }
    getline(file, line);
    i = 0;
    j = 0;
    while(!line.empty())
    {
        if (isspace(line[i]))
        {
            a2[j] = stod(line.substr(0,i));
            line.erase(0,i);
            j++;
            i=0;
        }
        i++;
    }
    getline(file, line);
    i = 0;
    j = 0;
    while(!line.empty())
    {
        if (isspace(line[i]))
        {
            a3[j] = stod(line.substr(0,i));
            line.erase(0,i);
            j++;
            i=0;
        }
        i++;
    }
    */

}
    
Cell::~Cell()
{
    delete[] a1;
    delete[] a2;
    delete[] a3;
}

void Cell::printCell()
{
    cout<<"a1"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<a1[i]<<" ";
    }
    cout<<endl;
    cout<<"a2"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<a2[i]<<" ";
    }
    cout<<endl;
    cout<<"a3"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<a3[i]<<" ";
    }
    cout<<endl;
    
}

void Cell::calculateVolume()
{
    Volume = abs(a2[1])*abs(a3[2]);
    Volume = Volume * abs(a1[0]);
}

double Cell::getVolume()
{
    this->calculateVolume();
    return Volume;
}
