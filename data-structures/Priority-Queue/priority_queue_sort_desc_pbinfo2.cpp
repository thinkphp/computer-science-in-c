#include <bits/stdc++.h>
#define MAXSIZE 1000
#define filein "sortare.in"
#define fileout "sortare.out"

using namespace std;

int n,
    arr[101];

ifstream fin(filein);
ofstream fout(fileout);

// Analisys Time Complexity:
// - enqueue O(1)
// - dequeue O(n)
// - peek O(n)

//element of the Priority Queue
struct Node {
       int data;
       int priority;
};

//Priority Queue Data Structure For Store Elements
Node PQ[ MAXSIZE ];

int size = -1;//pointer for Priority Queue

void enqueue(int data, int priority) {
     size++;
     PQ[size].data = data;
     PQ[size].priority = priority;
};

int peek() {
    int ind = -1,
        highest_priority = INT_MIN;

    for(int i = 0; i <= size; i++) {
        if(PQ[i].priority > highest_priority){
          highest_priority = PQ[i].priority;
          ind = i;
        }
    }

    return ind;
};

void dequeue() {

      int ind = peek();
      for(int i = ind; i < size; ++i) {
         PQ[i] = PQ[i+1];
      }
      size--;
};

int main(int argc, char const *argv[]) {
    
    fin>>n;       
    
    for(int i = 0; i < n; ++i) {

        fin>>arr[i];
    }

  
  for(int i = 0; i < n; ++i) {

      enqueue(arr[i], arr[i]);
  }

  while(n--){

     fout<<PQ[peek()].data<<" ";

     dequeue();
  }
  return 0;
}
