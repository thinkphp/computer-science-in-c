    #include <iostream>
     
    //Se considera o multime de n numere reale. Se cere o submultime a sa, cu un numar maxim de elemente, astfel incat suma elementelor sale sa fie maxima.
     
    float A[100],
          B[100];
    int   n, m=0, i;
     
    void greedy() {
      for(int i = 1; i <= n; ++i) {
          if(A[i]>=0) { m++; B[m] = A[i]; }
      }
    }
     
    int main(int argc, char const *argv[]) {
     
      std::cout<<"n=";
      std::cin>>n;
      for(int i = 1; i <= n; ++i) std::cin>>A[i];
      greedy();
      for(int i = 1; i <= m; ++i) std::cout<<B[i]<<" ";
      return 0;
    }
