#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

// comparare după x
bool cmpX(const Point &a, const Point &b) {
    return a.x < b.x;
}

// comparare după y
bool cmpY(const Point &a, const Point &b) {
    return a.y < b.y;
}

// distanța pătratică (fără sqrt)
double dist2(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// brute force pentru n mic
double bruteForce(vector<Point> &pts, int st, int dr) {
    double d = DBL_MAX;
    for (int i = st; i <= dr; i++) {
        for (int j = i + 1; j <= dr; j++) {
            d = min(d, dist2(pts[i], pts[j]));
        }
    }
    return d;
}

// funcția principală divide et impera
double closestUtil(vector<Point> &pts, int st, int dr) {
    // caz mic
    if (dr - st <= 3) {
        return bruteForce(pts, st, dr);
    }

    int mid = (st + dr) / 2;
    Point midPoint = pts[mid];

    // rezolvăm stânga și dreapta
    double dl = closestUtil(pts, st, mid);
    double drt = closestUtil(pts, mid + 1, dr);

    double d = min(dl, drt);

    // construim strip
    vector<Point> strip;
    for (int i = st; i <= dr; i++) {
        if (abs(pts[i].x - midPoint.x) * abs(pts[i].x - midPoint.x) < d) {
            strip.push_back(pts[i]);
        }
    }

    // sortăm strip după y
    sort(strip.begin(), strip.end(), cmpY);

    // verificăm doar vecinii apropiați
    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1; j < (int)strip.size() &&
             (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < d; j++) {

            d = min(d, dist2(strip[i], strip[j]));
        }
    }

    return d;
}

// funcția apelată din main
double closest(vector<Point> &pts) {
    sort(pts.begin(), pts.end(), cmpX);
    return closestUtil(pts, 0, pts.size() - 1);
}

int main() {
    vector<Point> pts = {
        {1,2}, {4,6}, {7,1}, {3,3}, {9,5},
        {2,8}, {6,4}, {5,7}, {8,2}, {0,0}
    };

    double d2 = closest(pts);

    cout << "Distanta minima: " << sqrt(d2) << "\n";

    return 0;
}
