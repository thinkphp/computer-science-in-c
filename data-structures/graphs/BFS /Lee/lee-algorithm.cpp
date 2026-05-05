#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

const int di[]={-1, 0, 1, 0},
          dj[]={ 0, 1, 0,-1};

int A[101][101], n , m, istart , jstart;


void Lee(int istart ,int jstart)
{
    queue<pair<int,int>> Q;
    //initializare coada
    Q.push(make_pair(istart , jstart));
    //marcare pozitie de start
    A[istart][jstart] = 1;
    while(! Q.empty()) // cat timp coada este nevida
    {   
        int i = Q.front().first, j = Q.front().second; // determinam elementul de la inceputul cozii
        for(int k = 0 ; k < 4 ; k ++)
        {
            int iv = i + di[k], jv = j + dj[k]; // coordonatele vecinului
            if(iv >= 1 && iv <= n && jv >= 1 && jv <= m // element în matrice
                && A[iv][jv] == 0) // element liber si nemarcat
            {
                // marcam elementul vecin cu o valoare mai mare
                A[iv][jv] = A[i][j] + 1;
                // il adaugam in coada
                Q.push(make_pair(iv , jv));
            }
        }
        Q.pop(); // eliminam din coada
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ;i ++)
        for(int j = 1 ; j <= m ; j ++)
            cin >> A[i][j];
    // 0 - zona libera, -1 - zona ocupata
    cin >> istart >> jstart;
    
    Lee(istart, jstart);
    
    for(int i =1 ; i <= n ;i ++, cout << endl)
        for(int j = 1; j <= m ; j ++)
            cout << setw(3) << A[i][j];
    
    return 0;
}
