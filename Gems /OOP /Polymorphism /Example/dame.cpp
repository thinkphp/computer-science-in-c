#include "perm.cpp"
#include <math.h>

class Dame: public Perm {
      public:
      Dame(int n):Perm(n){};
      virtual int val();
};

int Dame::val() {    
    for(int i = 1; i < level; ++i) {
      if(stack[i] == stack[level] || abs(stack[i]-stack[level]) == abs(i - level)) return 0;
    }
    return 1;
}
