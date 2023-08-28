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
