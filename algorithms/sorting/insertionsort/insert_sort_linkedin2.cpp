#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define SIZE 500001

using namespace std;

struct Node {

       int info;
       struct Node *next;    
};

struct Node *base, 
            *curr, 
            *c, 
            *c1;

const int MAXINT = 2147483647;

int main() {

    ifstream fin(FIN);
    ofstream fout(FOUT);
 
    int n, 
        arr[SIZE], 
        elem;

    fin>>n;

    for(int i = 0; i < n; ++i) 

        fin>>arr[i]; 

    base = new struct Node;
    base->info = MAXINT;
    base->next = 0;

    for(int i = 0; i < n; ++i) {

        curr = new struct Node;
        curr->info = arr[i];

        if(curr->info < base->info) {

           curr->next = base;
           base = curr;           
               
        } else {

          c = base;

          c1 = c->next;

          while(c1->info < curr->info) {

                c = c->next;

                c1 = c1->next; 
          }

          c->next = curr;

          curr->next = c1;  

        }
          
    }        
  
    c = base;

    while(c->info != MAXINT) {

          fout<<c->info<<" ";

          c = c->next;
    }


 return(0);
};