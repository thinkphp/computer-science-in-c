#include <iostream>

using namespace std;

void swap2(int *a, int *b) {
     int aux;
     aux = *a;
     *a = *b;
     *b = aux;
}

void swap(void*x,void*y,size_t dim) {
     char*a=(char*)x;
     char*b=(char*)y;
     char aux;
     for(int i = 0; i < dim; ++i) {
       aux = *(a+i);
       *(a+i) = *(b+i);
       *(b+i) = aux;
     }
}

int main(int argc, char const *argv[]) {
  int a,b;
  cout<<"a=";
  cin>>a;
  cout<<"b=";
  cin>>b;
  swap(&a,&b,sizeof(int));
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b<<endl;
  swap2(&a,&b);
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b;
  return 0;
}
