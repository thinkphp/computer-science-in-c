#include "bkt.cpp"

class Perm: public Bkt {
      public:
      Perm(int n):Bkt(n){};
      virtual void init();
      virtual int succ();
      virtual int val();
      virtual int sol();
      virtual void print();
};

void Perm::init() {
     stack[level] = 0;
};

int Perm::succ() {
    if(stack[level]<n) {
      stack[level]++;
      return 1;
    }else
    return 0;
};

int Perm::val() {
    for(int i = 1; i < level; ++i)
    if(stack[i]==stack[level]) return 0;
    return 1;
};

int Perm::sol() {
    return level == n;
};

void Perm::print() {
    for(int i = 1; i <= level; ++i) cout<<stack[i]<<" ";
    cout<<"\n";
};
