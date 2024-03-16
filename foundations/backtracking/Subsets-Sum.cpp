#include <iostream>
#include <cstring>

int use[10], sol[11],
N, s = 0, Sum;

void display_solution(int k) {

     for(int i = 1; i <= k ; ++i) printf("%d ", sol[ i ] );

     printf("\n");
}

void bkt(int k) {

     int i;

     if( k <= 10 ) {
                      //-1+1 = 0=>i merge de la 0 la 9
          for(i = sol[ k - 1 ] + 1; i <= 9; ++i) {

              if(use[ i ] == 1) {
                    if( (i + s) <= Sum) {
                        sol[ k ] = i;
                        use[ i ] = 0;
                        s = s + i;
                        if(s == Sum) display_solution( k );
                        bkt( k + 1 );
                        use[ i ] = 1;
                        s -= i;
                    }
              }
          }
     }
}

int main() {

    printf("N = ? Sum = ?");
    scanf("%d %d", &N, &Sum);

    memset(use, 0, 10);
    
    while( N != 0 ) {
        use[ N%10 ] = 1;
        N /= 10;
    }


    //for(int i = 0; i < 10; ++i) printf("%d ", use[i]);


    sol[ 0 ] = -1;

    bkt(1);
}
