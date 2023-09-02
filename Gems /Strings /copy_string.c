/*
1. Copierea unui sir constant (sir de caractere, pointer).
Scrieti un program simplu, in care sa se evidentieze cele doua modalitati
de a trata un sir: la nivel de caracter si la nivel de pointer.
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
  char text1[100], text2[100];
  char mess[] = "Hello, I am working with C programming language!";
  char *p1,*p2;

  int i = 0;
  while(mess[i]!='\0') {
    text1[i] = mess[i];
    i++;
  }

  p1 = mess;
  p2 = text2;

  while(*p1!='\0'){
    *p2 = *p1;
    p1++;
    p2++;
  }
  *p2='\0';

  printf("text1 = %s\n", text1);

  printf("text2 = %s", text2);

  return 0;
}
