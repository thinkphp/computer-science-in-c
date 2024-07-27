#include <iostream>

int n, i, j, T[100], Rank[100];

int arb(int node) {
      while(T[node]) {
            node = T[node];
      }  
    return node;
 }

void add(int i, int j) {

     int v1 = arb(i), 
         v2 = arb(j);
  
     if(v1 != v2) {
           if(Rank[v1] == Rank[v2]) {
              T[v1] = v2;
              Rank[v2]++;
           } else {
                  if(Rank[v1] < Rank[v2]) T[v1] = v2;
                          else 
                                          T[v2] = v1;   
           }
     }
}

int main() {

    fstream fin("graph.in", ios::in);
  
    fin>>n;
  
    while(fin>>i>>j) add(i, j);
  
    fin.close();
  
  cout<<"i = "; cin>>i;
  cout<<"j = "; cin>>j;
  
  if(arb(i) == arb(j)) {
        cout<<"Asemenea";
  } else {
        cout<<"Nu sunt Asemenea";
  }
  
  
 
}
