#include <iostream>

template <class T>void sort(T *p, int n) {
     register int i, j;
     T t;
     for(i = 1; i < n; ++i)
         for (j = n - 1; j >= i; j--) {
              if(p[j-1]>p[j]) {
                t = p[j-1];
                p[j-1] = p[j];
                p[j] = t;
              }
         }
}
int main(int argc, char const *argv[]) {

  char *s_arr[10] = {"an","cc","bc","gc","xc","acc","aac","eec","rrp","yxz"};
  char c_arr[10] = {'a','c','b','g','x','a','c','c','p','y'};
  int i_arr[10] = {1,2,3,4,5,6,7,8,0,9};
  double d_arr[10] = {2,3,-4.44,4,51.2,6,7,8.3,0,9.2};
  float f_arr[10] = {-2,3,-4.44,4.78,-51.2,6,7,8.3,0,9.2};
  int count = sizeof(i_arr)/sizeof(i_arr[0]);
  for (size_t i = 0; i < count; i++) {
       //printf("%.3lf ",i_arr[i]);
       //printf("%d ",i_arr[i]);
       //printf("%c ",c_arr[i]);
       printf("%.2f ",f_arr[i]);
       //printf("%s ",s_arr[i]);
  }
  
  sort(f_arr, count);
  
  printf("%s\n","");
  for (size_t i = 0; i < count; i++) {
       //printf("%.3lf ",i_arr[i]);
       //printf("%d ",i_arr[i]);
       //printf("%c ",c_arr[i]);
       printf("%.2f ",f_arr[i]);
       //printf("%s ",s_arr[i]);
  }
  return 0;
}
