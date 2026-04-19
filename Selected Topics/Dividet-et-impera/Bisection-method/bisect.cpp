#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
double f(double x) {
    return x*x*x + x - 1;
}
 
double bisectie(double a, double b, double toleranta, int maxIter) {
    if (f(a) * f(b) >= 0) {
        cout << "Eroare: f(a) si f(b) trebuie sa aiba semne opuse!" << endl;
        return -1;
    }
 
    cout << left
         << setw(5)  << "n"
         << setw(12) << "a"
         << setw(12) << "b"
         << setw(12) << "m"
         << setw(14) << "f(m)"
         << setw(12) << "eroare"
         << endl;
    cout << string(65, '-') << endl;
 
    double m;
    for (int i = 1; i <= maxIter; i++) {
        m = (a + b) / 2.0;
        double fm = f(m);
        double eroare = (b - a) / 2.0;
 
        cout << left
             << setw(5)  << i
             << setw(12) << fixed << setprecision(6) << a
             << setw(12) << b
             << setw(12) << m
             << setw(14) << fm
             << setw(12) << eroare
             << endl;
 
        if (eroare < toleranta || fm == 0.0) {
            cout << "\nConvergenta atinsa dupa " << i << " iteratii." << endl;
            return m;
        }
 
        if (f(a) * fm < 0)
            b = m;
        else
            a = m;
    }
 
    cout << "\nNumar maxim de iteratii atins." << endl;
    return m;
}
 
int main() {
    double a = 0.0;
    double b = 1.0;
    double toleranta = 1e-6;
    int maxIter = 100;
 
    cout << "Metoda bisectiei pentru f(x) = x^3 + x - 1" << endl;
    cout << "Interval: [" << a << ", " << b << "]" << endl;
    cout << "Toleranta: " << toleranta << endl << endl;
 
    double radacina = bisectie(a, b, toleranta, maxIter);
 
    cout << fixed << setprecision(8);
    cout << "\nRadacina aproximativa: x = " << radacina << endl;
    cout << "Verificare f(" << radacina << ") = " << f(radacina) << endl;
 
    return 0;
}
