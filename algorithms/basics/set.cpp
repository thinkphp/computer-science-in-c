#include <iostream>
 
using namespace std;
 
class Multime {
 
    public:
    //constructor of the class
    Multime() {
      for(int i = 0; i < 100; ++i) buffer[i] = 0;
    }
 
    int check(int n) {
      int mask = 1;
      int nr_byte, nr_bit;
      nr_bit = 7 - n%8;
      nr_byte = n/8;
      mask = mask << nr_bit;
      return buffer[nr_byte] & mask;
    }
 
    Multime operator+(Multime&M){
 
       Multime Union;
 
       for (size_t i = 0; i < 100; i++) {
 
              Union.buffer[i] = buffer[i] | M.buffer[i];
       }
 
       return Union;
    }
 
 
    friend Multime operator+(int n, Multime&M);
    friend Multime operator+(Multime&M, int n);
    friend ostream& operator<<(ostream&out,Multime&M);
 
    private:
    char buffer[100];
};
 
ostream& operator<<(ostream&out,Multime&M) {
 
    for(int i = 0; i < 800;++i) if(M.check(i)) cout<<i<<" ";
    return out;
}
 
Multime operator+(int n, Multime&M) {
      int mask = 1;
      int nr_byte, nr_bit;
      nr_bit = 7 - n%8;
      nr_byte = n/8;
      mask = mask << nr_bit;
      M.buffer[nr_byte] = M.buffer[nr_byte] | mask;
      return M;
};
 
Multime operator+(Multime&M, int n) {
      int mask = 1;
      int nr_byte, nr_bit;
      nr_bit = 7 - n%8;
      nr_byte = n/8;
      mask = mask << nr_bit;
      M.buffer[nr_byte] = M.buffer[nr_byte] | mask;
      return M;
};
 
int main(int argc, char const *argv[]) {
 
  Multime M, M1, union_set, M2;
  //add elements to the set
  M = 1 + M;
  M = 23 + M;
  M = 2 + M;
  M = 16 + M;
  M = 32 + M;
 
  M1 = 3 + M1;
  M1 = 4 + M1;
  M1 = 101 + M1;
 
  //for(int i = 0; i < 800;++i) if(M.check(i)) cout<<i<<" ";
  union_set = M + M1;
 
  for(int i = 0; i < 800;++i) if(union_set.check(i)) cout<<i<<" ";
 
  Multime set;
  char str[50] = "MayAnnCampeneraVergara";
  int i = 0;
  while(str[i] != '\0') {
    set = set + str[i];
    i++;
  }
 
  cout<<endl;
 
  for(int i = 0; i < 256;++i) if(set.check(i)) cout<<(char)i<<" ";
 
  cout<<endl;
 
  //added to the set
  M2 = M2 + 0;
  M2 = M2 + 1;
  M2 = M2 + 2;
  M2 = M2 + 3;
  M2 = M2 + 4;
  M2 = M2 + 5;
  cout<<M2;
 
  return 0;
}
