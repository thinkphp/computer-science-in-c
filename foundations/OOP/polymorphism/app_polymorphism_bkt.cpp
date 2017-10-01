#include <iostream>
#include <cmath>

using namespace std;

class bkt_abstract {

      public:
             int stack[100],
             level, 
             n;

      virtual void init() {};       
      virtual int valid() {return 0;};
      virtual int succ() {return 0;};
      virtual int sol(){ return 0;};
      virtual void print(){};
      void run();

/*
void run() {

     int hs, is;

     level = 1;

     init();

     while(level > 0) {
        
           hs = 1; is = 0;

           while(hs && !is) {

                 hs = succ();

                 if( hs ) {
                     is = valid(); 
                 }
           }

           if(hs) {
                   if(sol()) print();

                      else {level++; init();} 
           } else level--;
     }  

};
*/

};

void bkt_abstract::run() {

     int hs, is;

     level = 1;

     init();

     while(level > 0) {
        
           hs = 1; is = 0;

           while(hs && !is) {

                 hs = succ();

                 if( hs ) {
                     is = valid(); 
                 }
           }

           if(hs) {
                   if(sol()) print();

                      else {level++; init();} 
           } else level--;
     }  
};

class Permut: public bkt_abstract {

              public:
              Permut(int _n) {
                  n = _n;
              }
              void init() {
                    stack[level] = 0;
              };
              int succ() {
                  if(stack[level] < n) {
                     stack[level]++;
                     return 1; 
                  }  
                  return 0;
              }; 
              int valid() {
                  for(int i = 1; i < level; ++i) 
                      if(stack[i] == stack[level]) return 0; 
                  return 1; 
              }  
              int sol() {return n == level;}
              void print() {

                  for(int i = 1; i <= level; ++i) cout<<stack[i]<<" ";
                  cout<<endl;
              }
};

class Queens: public Permut {
       
      public:

      Queens(int _n): Permut(_n){}; 

      int valid(){

          for(int i = 1; i < level;++i) 

              if(stack[i] == stack[level] || abs(stack[level] - stack[i]) == abs(level - i)) return 0; 

          return 1;
      } 
      
};


int main( void ) {

    Permut p(3);
           p.run();
    Queens q(4);
           q.run();   
};