#include <iostream>

void* read(int n, int m) {

      int (*adr)[10] = new int[10][10];
      for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            std::cin>>adr[i][j];
        }
      }

      return adr;
};

void display(int m, int n, int(*adr)[10]) {

  for(int i = 0; i < n; ++i) {

    for(int j = 0; j < m; ++j) {

        std::cout<<adr[i][j]<<" ";
    }
        std::cout<<std::endl;
  }

};

void * suma(int m, int n, int (*adr1)[10], int (*adr2)[10]){

  int (*s)[10] = new int[10][10];
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
        s[i][j] = adr1[i][j] + adr2[i][j];
    }
  }
return s;
}

int main(int argc, char const *argv[]) {

  int m,n,(*adr1)[10],(*adr2)[10],(*sum)[10];
  std::cout<<"lines = ";
  std::cin>>n;
  std::cout<<"cols = ";
  std::cin>>m;
  std::cout<<"First Matrix:\n";
  adr1 = (int(*)[10])read(m,n);
  std::cout<<"Second Matrix:\n";
  adr2 = (int(*)[10])read(m,n);
  display(m,n,adr1);
  display(m,n,adr2);
  sum = (int(*)[10])suma(m,n,adr1,adr2);
  std::cout<<"Sum Matrix:\n";
  display(m,n,sum);
  delete [] adr1;
  display(m,n,adr1);
return 0;
}
