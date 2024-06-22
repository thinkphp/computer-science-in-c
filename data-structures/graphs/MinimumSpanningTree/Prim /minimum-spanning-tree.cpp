/*
Fie G = (X, V) un graf neorientat si connex, unde X = multimea de noduri si V multimea de muchii. Graful este dat prin matricea ponderilor, adica fiecare muchie are asociata o anumita pondere, un cost. Prin eliminarea unor muchii din G se obtine un graf partial al lui G. Daca acesta este arbore, se va numi arbore partial. 
Problema. Definim un arbore partial ca suma costurilor muchiilor sale. 
Se cere sa se obtina un arbore partial de cost minim, adica:
- intre oricare doua noduri sa existe un drum;
- suma muchiilor sa fie minima;
Dorim sa gasim un Arbore Partial T = (X', V'), unde X' inclus in X si V' inclus in V care sa satisfaca urmatoarele conditii:
- T este arbore (graf conex si aciclic).
- Suma costurilor muchiilor sa fie minima.
O Problema concreta, in care intervine problema enuntata, este cea a conectarii oraselor cu cost minim:
Se dau n orase precum si costul conectarii anumitor perechi de orase. Se cere sa se aleaga acele muchii care 
asigura existenta unui drum intre oricare doua orase astfel incat costul total sa fie minim.
Pentru rezolvare  se folosesc 2 vectori:
=> vectorul S are urmatoarea semnificatie:
       0, daca nodul i apartine arborelui deja construit       
S[i] = 
       k, daca sunt respectate cele doua conditii de mai jos:
       
       1. Nodul i nu apartine arborelui deja construit
       2. muchia de cost minim care uneste pe i cu  unul din nodurile grafului deja construit este [i,k]
       
=> vectorul T retine pentru fiecarenod care se adauga arborelui nodul parinte al acestuia (legatura de tip TATA cu ajutorul
acestui vector se poate reconstutuie arborele);
Prezentarea algoritmului:
1) Se citesc N - numarul nodurilor, matricea ponderilor si nodul de pornire V, S[V] = 0 si S[i] = V, pentru i != V
2) Se alege muchia de cost minim (i,j) care are o extremitate intr-un din nodurile arborelui deja construit, iar cealalta intr-un nod care nu apartine arborelui (S[i]=0, S[j]!=0). Se pune T[j] = S[j] si se actualizeaza vectorul S pentru nodul j.
3) Daca nu au fost alese n-1 muchii , se reia pasul 2.
*/

```c++
/*
Arborele partial de cost minim
-------------------------------
Fie G = (X, V) un graf neorientat si conex, unde X = multimea de noduri si V = multimea de muchii. Graful este dat prin
matricea ponderilor, adica fiecare muchie are asociata o anumita pondere, un cost. Prin eliminearea unor muchii din G se
obtine un graf partial al lui G. Daca acesta este arbore, se va numi arbore partial.
Problema:
Fie un arbore partial un arbore cu  suma costurilor muchiilor sale.
Se cere sa se obtina un arbore partial de cost minim daca:
- intre oricare doua noduri sa existe un drum
- suma muchiilor sa fie minima.
Cu alte cuvinte: dorim sa gasim un Arbore Partial T = (X', V') unde X' este inclus in X si V' este inclus in V care sa satisfaca
urmatoarele conditii:
- T este este un abore (graf connex si aciclic)
- suma costurilor sa fie minima
O problema concreta , in care intervine arborele partial de cost minim, este cea a conectarii oraselor cu cost minim:
Se da n orase precum si costul conectarii anumitor perechi de orase. Se cere sa se aleaga acele muchii care asigura
existenta unui drum intre oricare doua orase astfel incat costul sa fie minim.
Pentru rezolvare vom folosi 2 vectori:
---> vectorul S are urmatoarea semnificatie:
        0, daca nodul i apartine arborelui deja construit
S[i] =
        k, daca sunt respectate cele doua conditii de mai jos:
        1) nodul i nu apartine arborelui deja construit
        2) muchia de cost minim care uneste pe i cu unul din nodurile grafului deja construit este [i,k]
---> vectorul T retine pentru fiecare nod care se adauga arborelui nodul parinte al acestuia (legatura de tip TATA) cu
ajutorul acestui vector se poate reconstitui arborele.
Algoritmul:
Pasul 1: Se citesc N - numarul de noduri, matricea ponderilor si nodul de pornire V, S[V] = 0 si S[i] = V, pentru i != V
Pasul 2: Se alege muchia de cost minim (i,j) care are o extremitate intr-unul din nodurile arboreului deja construit, iar
cealalta intr-un nod care nu apartine arboreului (S[i]=0, S[j]!=0). Se pune T[j] = S[j] si se actualizeaza vectorul S pentru nodul j
Pasul 3: Daca nu au fost alese n-1 muchii , se reia Pasul 2.
input:
7 11
1 2 2
1 7 4
2 3 3
2 5 2
2 6 3
2 7 3
3 4 1
3 5 2
4 5 1
5 6 3
6 7 5
Citire graf neorientat cu costuri:
#define INF 10000000
cin>>n>>m;
for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
         matrix[i][j] = INF
       matrix[i][j] = 0
while(m--){
      cin>>i>>j>>c;
      matrix[i][j] = matrix[j][i] = c;
      m--;
}
*/
#include <iostream>
#define FIN "graph.in"
#define SIZE 100

using namespace std;

float matrix[SIZE][SIZE], mini, cost = 0;
int S[SIZE],T[SIZE], n,m,i,j,c,k,v;

const float INFINITY = (1<<31-1);

void read_graph() {

     freopen(FIN, "r", stdin);

     cin>>n>>m>>v;

     for( int i = 1; i <= n; ++i ) {

         for( int j = 1; j <= n; ++j ) {

                matrix[i][j] = matrix[j][i] = INFINITY;
         }

         matrix[ i ][ i ] = 0;
     }

     for(int k = 1; k <= m; ++k) {

          cin>>i>>j>>c;

          matrix[i][j] = matrix[j][i] = c;
     }

     fclose( stdin );
}

void display_graph() {

  cout<<"Noduri = "<<n<<"\nMuchii = "<<m<<endl;

  for(int i = 1; i <= n; ++i) {

      for(int j = 1; j <= n; ++j) {

        cout<<matrix[i][j]<<" ";

      }
      cout<<endl;
  }
}

int main(int argc, char const *argv[]) {

  read_graph();

  display_graph();

  cout<<"Nodul de pornire: "<<v<<endl;

  cout<<endl;
  /*
          0,
  S[i] =
  */
  //pasul 1:
  for(int i = 1; i <= n; ++i)

     // daca i este egal cu nodul de pornire
     if(i == v) S[ i ] = 0;

        else
                S[ i ] = v;//nodul de pornire

   cout<<"Configuratia lui S: ";

   for(int i = 1; i <= n; ++i) cout<<S[i]<<" ";
//S = [0,1,0,0,0,0,0]

  //for(int i = 1; i <= n; ++i) cout<<S[i]<<" ";

  //pasul 2: se alege muchia de cost minim (i, j) care are o extremitate intr-un din nodurule arborelui deja construit ,
  //iar cealalta intr-un nod care nu apartine arborelui  S[i] = 0, S[j] != 0

//Algoritmul are complexitate O(n^2) n(n+1) = n^2 + n

  //primul for selecteaza n-1 muchii
  for(int k = 1; k <= n - 1; k++) {
      mini = INFINITY;
       //selectezi muchia de cost minim care are o extremitate intr-unul din nodurile  arborelui deja construit, iar
       //cealalta intr-unul din nodurile grafului care nu apartine arborelui
      for(int i = 1; i <= n; ++i)
            if( S[i] != 0)
              if( matrix[ S[i] ][ i ] < mini ) {
                  mini = matrix[ S[ i ] ] [i];
                  j = i;
              }
        T[j] = S[j];//vectorul TATA pentru a reconstitui arborele
        cost += matrix[ S[j] ][j];//calculam suma costurilor
        S[j] = 0;//adaugam nodul j la Arborele partial de cost minim construit dinamic
        for( int i = 1; i <= n; ++i ) if( S[i] && matrix[ i ][ S[i] ] > matrix[i][j] ) S[i] = j;
        cout<<endl<<"Configuratia lui S: ";
        for(int i = 1; i <= n; ++i) cout<<S[i]<<" ";
  }

  cout<<"\nCost = "<<cost<<endl;

  for(int i = 1; i <= n; ++i) cout<<T[i]<<" ";

  return 0;
}

```
