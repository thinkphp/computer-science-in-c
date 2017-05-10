#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template<typename T>
void print_queue(T& q) {

    ofstream cout(FOUT);

    while(!q.empty()) {

           cout<<q.top()<<" ";

           q.pop();          
    }
};

int main() {

 int n;

 ifstream cin(FIN);

 cin>>n;

 vector<int> arr(n);

 for(int i = 0; i < n; i++) cin>>arr[i];


 priority_queue<int,vector<int>,greater<int>> q;
 
 for(int i: arr) q.push(i);
      
 print_queue(q);


 return(0); 
};