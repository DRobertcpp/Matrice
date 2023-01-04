#include "matrice.h"
#include <iostream>
using namespace std;
#include <math.h>

mat::mat()
{
    n = 0; m = 0;
    A[0][0] = 0;
}

mat::mat(int lin, int col)
{
    n = lin;
    m = col;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            A[i][j] = 0;
}

mat::mat(int lin, int col, float x)
{
    n = lin;
    m = col;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            A[i][j] = x;
}

istream& operator >> (istream& f, mat& b)
{
    f >> b.n >> b.m;
    for (int i = 1; i <= b.n; i++)
        for (int j = 1; j <= b.m; j++)
            f >> b.A[i][j];
    return f;
}

ostream& operator << (ostream& f, mat& b)
{
    if (b.getm() == -1)
        f << "matrice inexistenta";
    for (int i = 1; i <= b.getn(); i++)
    {
        for (int j = 1; j <= b.getm(); j++)
            f << b.getElement(i, j);
        f << '\n';
    }
    return f;
}

mat operator * (mat a, float x)
{
    for (int i = 1; i <= a.getn(); i++)
        for (int j = 1; j <= a.getm(); j++)
            a.setElement(i, j, a.getElement(i, j) * x);
    return a;
}

mat operator * (float x, mat a)
{
    return a * x;
}

mat operator * (mat a, mat b)
{
    mat c(a.n, b.m);
    if (a.m != b.n)
    {
        c.n = c.m = -1;
        return c;
    }
    else
        for (int i = 1; i <= a.n; i++)
            for (int j = 1; j <= b.m; j++)
                for (int k = 1; k <= b.m; k++)
                    c.A[i][j] += a.A[i][k] * b.A[k][j];
    return c;
}

mat operator + (mat a, mat b)
{
    mat c;
    if (a.n != b.n || a.m != b.m)
    {
        c.n = c.m = -1;
        return c;
    }
    else
        for (int i = 1; i <= a.n; i++)
            for (int j = 1; j <= b.m; j++)
                c.A[i][j] += a.A[i][j] + b.A[i][j];
    return c;
}

mat operator - (mat a, mat b)
{
    return a + (-1) * b;
}

float mat::determinant()
{
    float det = 0;
    mat b(101, 101);
    if (n == 2)
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    else
    {
        for (int x = 0; x < n; x++) {
            int i = 0;
            for (int y = 1; y < n; y++)
            {
                int j = 0;
                for (int z = 0; j < n; j++)
                {
                    if (z == x)
                        continue;
                    b.setElement(i, j, A[y][z]);
                    j++;
                }
                i++;
            }
            b.setmn(n - 1);
            det = det + pow(-1, x) * A[0][x] * b.determinant();
        }
    }
    return det;
}

mat mat::inversa()
{
    float t[100][100];
    mat inv, adj(101, 101);
    float d = this->determinant();
    if (d == 0)
    {
        inv.n = inv.m = -1;
        return inv;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            t[i][j] = A[j][i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            mat b;
            mat copy(n - 1, n - 1);
            for (int l = 0; l < n; l++)
                for (int c = 0; c < n; c++)
                {
                    if (l == i || c == j)
                        continue;
                    else
                        copy.setElement(l, c, t[i][j]);
                }
            adj.setElement(i, j, (t[i][j] * copy.determinant()));
        }
    inv = adj * (1 / d);
    inv.n = inv.m = this->getn();
    return inv;
}

void mat::citire()
{
    cout << "Introduceti nr. de linii: ";
    cin >> n;
    cout << "Introduceti nr. de coloane: ";
    cin >> m;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << "Elementul nr. " << k << " ";
            cin >> A[i][j];
            k++;
        }
    }
}
void mat::afisare()
{
    if (m == -1)
        cout << "mat inexistenta";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << A[i][j] << " ";
        cout << '\n';
    }
}
