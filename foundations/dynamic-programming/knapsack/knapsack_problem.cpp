/*
 *  Filename    : knapsack.c
 *  Title      : Knapsack Problem.
 *   
 *  Description
 *
 *   Given weights and values of n items, put these items in a knapsack of capacity W to get
 *   the maximum total value in the knapsack. In other words, given two integers arrays
 *   weight[0..n-1] and cost[0..n-1] which represent values and weights associated with n items respectively.
 *   Also given an integer W which represents knapsack capacity, find out the maximum value subset of cost[] such
 *   that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complet item, 
 *   or do not pick it(0-1 property).
 *     
 *    
 *  MIT License
 */
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
