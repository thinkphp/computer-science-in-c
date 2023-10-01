using namespace std;

class Bkt {

   public:
   int n,
       level,
       stack[100];

   Bkt(int n) {
     this->n = n;
   }

   virtual void init(){};
   virtual int succ(){return 0;};
   virtual int val(){return 0;};
   virtual int sol(){return 0;};
   virtual void print(){};

   void run() {
     int s, v;
     level = 1;
     init();
     while(level>0) {
         s = 1;
         v = 0;
         while(s && !v) {
           s = succ();
           if(s) {
             v = val();
           }
         }
         if(s) {
           if(sol()){
             print();
           } else {
             level++;init();
           }
         } else {
           level--;
         }
     }
   }
};
