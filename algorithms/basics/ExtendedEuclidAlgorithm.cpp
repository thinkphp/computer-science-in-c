#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid3.in");
ofstream fout("euclid3.out");

int T;

void Euclid(int a, int b, int &d, int &x, int &y)
{
    if (!b) { d = a; x = 1; y = 0; }
    else
    {
        int x0, y0;
        Euclid(b, a % b, d, x0, y0);
        x = y0;
        y = x0 - y0 * (a / b);
    }
}

void Rezolvare()
{
    fin >> T;
    while (T--)
    {
        int a, b, c, d, x, y;
        fin >> a >> b >> c;
        Euclid(a, b, d, x, y);
        if (c % d != 0)
            fout << "0 0\n";
        else
            fout << c / d * x << ' ' << c / d * y << '\n';
    }
}

int main()
{
    Rezolvare();
    fin.close();
    fout.close();
    return 0;
}
