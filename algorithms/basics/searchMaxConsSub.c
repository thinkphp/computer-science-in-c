#include <stdio.h>
#include <string.h>
#define FIN "search.in"
typedef char TypeS[100];

int search(TypeS str, int *lMax) {

  int i = 0, iMax = 0, iCurrent = 0, n = strlen(str);
  *lMax = 1;

  while(i < n){

    if(i - iCurrent > *lMax) {
       iMax = iCurrent;
       *lMax = i - iCurrent;
    }
    iCurrent = i;
    while(str[i] + 1 == str[i+1] && i < n) i++;
    i++;
  }
  return iMax;
}

int main(int argc, char const *argv[]) {

  TypeS s;
  freopen(FIN,"r",stdin);
  int lmax,imax;
  scanf("%s", &s);
  imax = search(s, &lmax);

  printf("lMax = %d\n", lmax);
  printf("IMax = %d\n", imax);

  for(int i = imax; i < imax+ lmax; ++i) {
    printf("%c", s[i]);
  }
  return 0;
}
