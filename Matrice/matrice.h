#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class mat
{
    int n, m;
    float A[101][101];
public:
    mat();
    mat(int, int);
    mat(int, int, float);
    int getn() { return n; }
    int getm() { return m; }
    float getElement(int i, int j) { return A[i][j]; }
    void setmn(int value) { n = m = value; }
    void setElement(int i, int j, float value) { this->A[i][j] = value; }
    friend istream& operator >> (istream&, mat&);
    friend ostream& operator << (ostream&, mat&);
    void citire();
    void afisare();
    friend mat operator * (mat, float);
    friend mat operator * (float, mat);
    friend mat operator * (mat, mat);
    friend mat operator + (mat, mat);
    friend mat operator - (mat, mat);
    float determinant();
    mat inversa();
};


