#include <fstream>

using namespace std;

ifstream cin("hanoi.in");
ofstream cout("hanoi.out");

void hanoi(int n, char sursa, char aux, char destinatie){

    if(n == 1) // mut de pe tija sursa(A) pe tija destinatie(C) ultimul disc 
        cout << sursa << "->" << destinatie << "\n";
    else{
		
        // mut de pe tija sursa(A) pe tija aux(B) n - 1 discuri
        hanoi(n - 1, sursa, destinatie, aux);
        cout << sursa << "->" << destinatie << "\n";
        hanoi(n - 1, aux, sursa, destinatie); // dupa ce am mutat ultimul disc de pe A, mut cele n - 1 discuri de pe B pe C

    }

}

int main(){

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    hanoi(n, 'A', 'B', 'C');

}
