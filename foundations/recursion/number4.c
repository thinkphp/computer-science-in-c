#include <stdio.h>

void numberFour(int n) {

     if(n - 4)  {

        switch(n % 10) {

             case 0:  numberFour(n / 10);break;

             case 4: numberFour(n / 10);break;

             default: numberFour(n * 2);  
        }

        printf(" -> %d",n);
     }

}

int main() {

    printf("%d",4);

    numberFour( 70 );

  return(0);
}