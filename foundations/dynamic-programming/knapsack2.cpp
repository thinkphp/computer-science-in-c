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
    weight[MAXW], cost[MAXC], Optim[MAX]; 

int main() {

    ifstream fin(FIN);
    ofstream fout(FOUT);

    fin>>number_of_objects>>W;
 
    for(int i = 1; i <= number_of_objects; ++i) {

        fin>>weight[i]>>cost[i]; 
    }
 
    for(int i = 1; i <= number_of_objects; ++i) {

        for(int j = W; j >= weight[i]; j--) {
  
                Optim[j] = max(Optim[j], Optim[j-weight[i]] + cost[i]);
        }
    }

    fout<<Optim[W];
   
 return(0);
}