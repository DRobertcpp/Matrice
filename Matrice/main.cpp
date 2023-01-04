#include <iostream>
#include <fstream>
#include "matrice.h"
using namespace std;

int main()
{
    mat a(2, 2);
    a.citire();
    a.afisare();
    /*cin >> a;
    matrice b;
    cin >> b;
    cout << a + b;*/
    return 0;
}
