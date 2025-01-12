#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  char *str;
  const int bufferSIZE = 100;
  str = (char*)malloc(bufferSIZE * sizeof(char));
  scanf("%s",str);
  printf("%s",str);
  int n = strlen(str);
  int isPal = 1;
  for(int i = 0; i < n; i++) {
     if(str[i] != str[n-i-1]) isPal = 0;
  }
  if(isPal)printf("\nPalindrom\n");else printf("\nNot Palindrom!\n");
  free(str);
  return 0;
}
