/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value 
in the knapsack. Note that we have only one quantity of each item, In other words, given two integer arrays val[0..N-1] 
and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which 
represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is
 smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case
consists of four lines. The first line consists of N the number of items. The second line consists of W,
the maximum capacity of the knapsack. In the next  line are N space separated positive integers denoting the values 
of the N items and in the fourth line are N space separated positive integers denoting the weights of the corresponding 
items.
 

Output:
Print the maximum possible value you can get with the given conditions that you can obtain for each test case in a 
new line.

 **/
#include <stdio.h>
#define MAXW 500
#define MAXC 500
#define MAX 500

int number_of_objects, W, 
    weight[MAXW], cost[MAXC], 
    T; //number of test cases

int max(int a, int b) {return (a>b)? a : b;}

int main() {

    int i, 
        j;

    //freopen("rucsac.in","r",stdin);
 
    scanf("%d", &T);

    while(T--) 
    {
      int Optim[MAX] = {0};

      scanf("%d", &number_of_objects);

      scanf("%d", &W);

      for(i = 1; i <= number_of_objects; i++) scanf("%d", &cost[i]); 


      for(i = 1; i <= number_of_objects; ++i) scanf("%d ", &weight[i]); 

 
      for(i = 1; i <= number_of_objects; ++i) {

         for(j = W; j >= weight[i]; j--) {
   
                Optim[j] = max(Optim[j], Optim[j-weight[i]] + cost[i]);
         }
      }

 
      printf("%d\n", Optim[W]);

    }

 return(0);
}