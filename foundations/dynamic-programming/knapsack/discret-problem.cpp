/*
Problema distreta a rucsacului
------------------------------

O persoana are la dispozitie un rucsac cu o capacitate de n unitati de greutate
si intentioneaza sa efectueze  un transport in urma caruia sa obtina un castig. persoana
are la dispozitie n Obiecte. Pentru fiecare obiect se cunoaste greutatea sa Gr(i) (numar natural)
si castigul obtinul in urma transportului sau: Ci. Ce obiecte trebuie sa aleaga persoana
pentru a-si maximiza castigul si care este acesta?


Observatie: Odata ales un obiect, acesat trebuie transportat integral (nu se admite transportul unei prati din el)
in acest fel trebuie sa rezolvam problema discreta a rucsacului.

Vom nota obiectele cu 1, 2, 3, ....,n. Exista posibilitatea ca problam sa admita mai multe solutii optime.
Fie S = {i1, i2,...in} o solutie optima a problemei unde i1 < i2 < i3 <....<in sunt obiecte dintre cele n.

Daca se inlatura obiectul ik atunci greutatea G - Gr(ik) este incarcata optim cu obiectele i1 < i2 < ...i(k-1), Daca

prin absurd , ar exista o alta incarcare a rucscacului  pentru greutatea G - Gr(ik), care aduce un castig mai mare
, atunci , la acea incarcatura  s-ar adauga  obiectul ik, am obtine o solutie mai buna decat cea initiala, ceea ce contrazice optimalitatea solutiei.


Greutatile 1, 2, ...., G se incarca optim, la inceput cu obiectul 1, apoi se imbunatateste solutia cu obiectul 2,...si la sfarsit cu obiectul n.


Pentru a calcula castigul maxim vom utiliza matricea

Castig (n+1, g+1)

unde Castig(i, j) va retine castigul obtinut prin transportul obiectele 1, 2, ...i, daca greutatea de transportat este j.


Castig(i,0) = 0, i = 1...n;
Castig(0,j) = 0 , j = 1...G


              Castig(i-1,j-Gr(i)) + C(i) daca Castig(i-1,k) < Castig(i-1,j - Gr(i) + C(i))
Castig(i,j) =

               Castig(i-1,j) altfel

*/

#include <iostream>
#include <fstream>
#define MAXW 10001
#define MAXC 10001
#define MAX 10001
#define FIN "rucsac.in"
#define FOUT "rucsac.out"

using namespace std;

int matrix[100][100][100][100];



int number_of_objects, W,

    weight[MAXW], cost[MAXC], Store[MAX][MAX],

    ProfitOptim[MAX][MAX];

int main(int argc, char const *argv[]) {

  ifstream fin(FIN);
  ofstream fout(FOUT);

  fin>>number_of_objects>>W;

  for(int i = 1; i <= number_of_objects; ++i) {

      fin>>weight[i]>>cost[i];
  }


  for(int i = 1; i <= number_of_objects; ++i) {

        for(int j = 1; j <= W; ++j)  {

                if(weight[i] <= j)

                          if(ProfitOptim[i-1][j-weight[i]] + cost[i] > ProfitOptim[i-1][j]) {


                              ProfitOptim[i][j] = ProfitOptim[i-1][j-weight[i]] + cost[i];

                              Store[i][j] = i;

                          }   else {

                              ProfitOptim[i][j] = ProfitOptim[i-1][j];

                              Store[i][j] = Store[i-1][j];

                          }

                 else {

                        ProfitOptim[i][j] = ProfitOptim[i-1][j];
                        Store[i][j] = Store[i-1][j];
                 }

        }

  }


 cout<<ProfitOptim[number_of_objects][ W ]<<" :";

 int i = number_of_objects, j = W;

 int object;

 while(Store[i][j]) {

      object = Store[i][j];

      cout<<Store[i][j]<<" ";

      while(object == Store[i][j]) {

            j -= weight[Store[i][j]];

            i--;
      }
 }

matrix[0][0][0][0]=12;

cout<<matrix[0][0][0][0];
  return 0;
}

/*

1 9

5 15

4 19

19 + 15 + 9 = 34+9 = 43
*/
