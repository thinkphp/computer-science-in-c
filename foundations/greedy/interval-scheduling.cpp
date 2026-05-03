#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Examen {
    int start, finish;
};

bool cmp(Examen a, Examen b) {
    return a.finish < b.finish;
}

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<Examen> examene(n);

    for(int i = 0; i < n; i++) {
        fin >> examene[i].start >> examene[i].finish;
    }

    sort(examene.begin(), examene.end(), cmp);

    int cnt = 1;

    fout << "Examene alese:\n";

    fout << examene[0].start
         << " "
         << examene[0].finish
         << "\n";

    int lastFinish = examene[0].finish;

    for(int i = 1; i < n; i++) {

        if(examene[i].start >= lastFinish) {

            cnt++;

            fout << examene[i].start
                 << " "
                 << examene[i].finish
                 << "\n";

            lastFinish = examene[i].finish;
        }
    }

    fout << "\nNumar maxim de examene: "
         << cnt;

    fin.close();
    fout.close();

    return 0;
}
