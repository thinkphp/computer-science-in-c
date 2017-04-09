#include <iostream>
#include <fstream>
#define MAXW 10001
#define MAXC 10001
#define MAX 10001
#define FIN "rucsac.in"
#define FOUT "rucsac.out"

using namespace std;

int number_of_objects, W, 
    weight[MAXW], cost[MAXC],Store[MAX][MAX],
    ProfitOptim[MAX][MAX]; 

int main() {

    ifstream fin(FIN);
    ofstream fout(FOUT);

    fin>>number_of_objects>>W;
 
    for(int i = 1; i <= number_of_objects; ++i) {

        fin>>weight[i]>>cost[i]; 
    }
 
    for(int i = 1; i <= number_of_objects; ++i) {

        for(int j = 1; j <= W; ++j) {        

                if(weight[i] <= j) 

                   if(ProfitOptim[i-1][j-weight[i]] + cost[i] > ProfitOptim[i-1][j]) {

                                  ProfitOptim[i][j] = ProfitOptim[i-1][j-weight[i]] + cost[i];

                                  Store[i][j] = i;
                   }

                            else  {
                                  ProfitOptim[i][j] = ProfitOptim[i-1][j];

                                  Store[i][j] = Store[i-1][j];
                            }

                 else {ProfitOptim[i][j] = ProfitOptim[i-1][j]; Store[i][j] = Store[i-1][j];}
        }
    }

    cout<<ProfitOptim[number_of_objects][ W ]<<" : ";

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

 return(0);
}