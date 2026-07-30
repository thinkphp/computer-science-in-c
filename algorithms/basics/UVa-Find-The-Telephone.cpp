#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char convert(char c)
{
    c = toupper(c);

    if (c >= 'A' && c <= 'C') return '2';
    if (c >= 'D' && c <= 'F') return '3';
    if (c >= 'G' && c <= 'I') return '4';
    if (c >= 'J' && c <= 'L') return '5';
    if (c >= 'M' && c <= 'O') return '6';
    if (c >= 'P' && c <= 'S') return '7';
    if (c >= 'T' && c <= 'V') return '8';
    if (c >= 'W' && c <= 'Z') return '9';

    return c; // 0, 1, -, sau orice alt caracter
}

int main()
{
    string s;

    while (getline(cin, s))
    {
        for (char c : s)
            cout << convert(c);

        cout << '\n';
    }

    return 0;
}
