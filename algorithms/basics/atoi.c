#include <stdio.h>
#include <ctype.h>

int correct(char str[50]) {

    if(!isdigit(str[0]) && str[0] != '-' && str[0] != '+') {
      return 0;
    }
    int ok = 1;
    for(int i = 1; ok == 1 && str[i] != '\0'; i++)  {
        if(!isdigit(str[i])) ok = 0;
    }
    return ok;
}

int atoi2(char str[50]) {

  int result = 0, i, sign = 1;
  i = 0;
  if(str[0] == '+') i++;
  else if(str[0] == '-') {
    sign = -1;
    i++;
  }
  while(str[i]!='\0') {
      result = result * 10 + str[i] - '0';
      i++;
  }
  return result*sign;
}

int main(int argc, char const *argv[]) {

  char str[50];

  printf("string = ");

  scanf("%s", str);

  if(!correct(str)) {

      printf("%s\n", "Number is not integer!");

  } else {

      printf("%s = %d\n", str, atoi2(str));
  }

  return 0;
}
