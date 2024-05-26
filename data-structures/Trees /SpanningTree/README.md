Notiunea de arbore partial:
--------------------------

Practica. Unde folosim arbori partiali

Sa presupunem ca intr-un judet se impune repararea tututor soselelor care unesc diverse localitati.

Pentru aceasta s-a obtinut un credit extern care permite  ca toate soselele sa fie reparate. Se doreste

ca repararea soselelor sa se faca cat mai repede,dar in acelasi timp pe parcursul reparatiilor sa se poata circula,

a.i. sa nu ramana localitati inaccesibile pentru traficul rutier. SE cere un numar minim de sosele, care sa nu intre in reparatii in prima faza.


Daca consideram graful in care nodurile sunt localitatile , iar muchii sunt seselele, va trebui sa pastram un numar minim de muchii,
a.i. graful sa ramana conex. Care este numarul minim de muchii care conserva aceasta proprietate.

Numarul minim de muchii n - 1


Problema:

            1

      2          3                                1
                                            2         3
                                            4          5
      4          5


      5
      1 2
      1 3
      2 3
      2 4
      4 5
      3 5
      2 5
      3 4

stergi muchiile [1 3] [2,4] [3 5] [2 5] obtinem un arbore partial

Problema:

Se da un graf neorientat, G = (V, E). Se cere un graf partial al sau care este arbore. O astfel de structura se numeste ARBORE PARTIAL.

Arborele partial de cost minim: KRUSKAL si PRIM (Clasici)


```c++

#include <iostream>
#define FIN "graph.in"
#define FOUT "graph.out"
#define SIZE 100

using namespace std;

int mat[SIZE][SIZE],
    used[100],
    n;

void read_graph() {
     int i, j;
     freopen(FIN,"r",stdin);
     cin>>n;
     while(cin>>i>>j) {
       mat[i][j] = mat[j][i] = 1;
     }
}

void DFS(int node) {

     int k;

     used[ node ] = 1;

     for(k = 1; k <= n; ++k) {

         if(mat[node][k] == 1 && used[k] == 0) {

           cout<<"["<<node<<","<<k<<"]"<<endl;

           DFS( k );
         }
     }
}

int main(int argc, char const *argv[]) {
  read_graph();
  cout<<"Arborele partial este urmatorul:\n";
  DFS(1);
  return 0;
}
```
