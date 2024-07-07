#include <iostream>

using namespace std;

class MyData {
private:
    int data;

public:
    MyData(int info) : data(info) {}

    ostream& print(ostream& os) const {
        os << data;
        return os;
    }

    istream& read(istream& intrare) {
        intrare >> data;
        return intrare;
    }
};

ostream& operator<<(ostream& flux_iesire, const MyData& obj) {
    return obj.print(flux_iesire);
}

istream& operator>>(istream& flux_intrare, MyData& obj) {
    return obj.read(flux_intrare);
}

int main() {
    MyData obj(10);

    cout << obj << endl;  // Output: 10

    // Read into obj from standard input (cin)
    cin >> obj;

    cout << obj << endl;  // Output: (whatever was read into obj)

    return 0;
}
