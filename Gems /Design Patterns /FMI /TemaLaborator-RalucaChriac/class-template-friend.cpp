
/*
	Author:	Raluca Chriac
	Copyright:	Free to use and distribute as long as this note is kept
	Date:		6:54 AM, Dec 19, 2023
*/

#include <iostream>
#include <cmath>

template <typename T>
class Complex {
public:
    // Constructors
    Complex();
    Complex(T real, T imag);

    // Member functions
    void display() const;

    // Operator overloads
    Complex<T> operator+(const Complex<T>& other) const;
    Complex<T> operator+(T scalar) const;

    // Friend functions
    friend std::ostream& operator<<(std::ostream& stream, const Complex<T>& c) {
        stream << c.real;
        if (c.imag > 0) stream << " + ";
        stream << c.imag << "i" << "\n";
        return stream;
    }

    friend std::istream& operator>>(std::istream& stream, Complex<T>& c) {
        std::cout << "real=";
        stream >> c.real;
        std::cout << "imag=";
        stream >> c.imag;
        return stream;
    }

    template <typename U>
    friend Complex<U> operator+(U scalar, const Complex<U>& c);

    friend double module(const Complex<T>& z) {
        return std::sqrt(z.real * z.real + z.imag * z.imag);
    }

private:
    T real;
    T imag;
};

// Constructor implementations
template <typename T>
Complex<T>::Complex() : real(1), imag(0) {}

template <typename T>
Complex<T>::Complex(T pr, T pi) : real(pr), imag(pi) {}

// Member function implementation
template <typename T>
void Complex<T>::display() const {
    std::cout << real;
    if (imag > 0) std::cout << " + ";
    std::cout << imag << " i" << "\n";
}

// Operator overloads implementation
template <typename T>
Complex<T> Complex<T>::operator+(const Complex<T>& z) const {
    return Complex<T>(real + z.real, imag + z.imag);
}

template <typename T>
Complex<T> Complex<T>::operator+(T scalar) const {
    return Complex<T>(real + scalar, imag);
}

// Friend function implementation
template <typename U>
Complex<U> operator+(U scalar, const Complex<U>& c) {
    return Complex<U>(scalar + c.real, c.imag);
}

int main() {
    Complex<double> z(4, 5), z1;
    std::cin >> z1;
    std::cout << z1;
    z.display();
    std::cout << z;

    z = 1.0 + z;
    z.display();

    z = z + 3.0;
    z.display();

    std::cout << module(z) << "\n";

    Complex<double> sum;
    sum = z1 + z;
    std::cout << z1 + z << sum;

    return 0;
}
