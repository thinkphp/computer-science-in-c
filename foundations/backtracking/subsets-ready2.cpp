#include <iostream>
#include <vector>
 
using namespace std;

vector<int> Stack(100);
int level,
    N;
 
void printSolution() {
 
     for(int i = 1; i <= level; ++i) cout<<Stack[i]<<" ";

     cout<<endl;
}
 
int solution() {
 
    return 1;   
}
 
int successor() {
 
    if(Stack[ level ] < N) {

       Stack[ level ]++;

       return 1;
    } 
 
    return 0;  
}
 
int valid() {
 
    return 1; 
}
 
void init() {


     Stack[ level ] = Stack[level-1];
}
 
void back() {
 
   int HN, is;

   level = 1; 

   init();
 
   while(level > 0) {   
  
     HN = 1; is = 0;

     while(HN && !is){

           HN = successor();

           if(HN) is = valid();
     }
 
     if( HN ) {
 
              printSolution();

              level++;

              init();
             
     } else {
 
       level--; 
     }
 
   }
}
 

 
int main() {
 

  N = 3;
 
  back();   

 
 return(0);
};