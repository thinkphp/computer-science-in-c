#include <iostream>

using namespace std;

int stack[100], n;

//n = 3
// ( 2, 5.5)
//  (3, 6)
// (6.7, 10)

struct interval {

       float li,
             ls;

} vec[ 100 ];

//n = 3
//  2, 5.5
//  3, 6
//  6.7, 10

void sortare() {

    int i, j, size = n;
    interval aux;
    int swapped = 1, finished = 0;

    while(!finished) {

        swapped = 0;

        for(int i = 1; i <= size - 1; i++) {

          if(vec[ i ].li > vec[i+1].li) {

             aux = vec[i];

             vec[i] = vec[i + 1];

             vec[i + 1] = aux;

             swapped = 1;
          }
        }

        if(swapped) size--;

        else finished = 1;
    }
}

void write(int k) {

     int i;

     if(k <= 2) {

     for(int i = 1; i <= k; ++i)

          printf("(%.2f, %.2f)", vec[ stack[i] ].li,  vec[ stack[i] ].ls);
     }

     printf("\n");
}


void display(int k) {

     int i;

     for(int i = 1; i <= k; ++i)

          printf( "(%.2f, %.2f)\n", vec[ i ].li,  vec[ i ].ls );

     printf("\n");
}

void back(int k) {

     int i;

     while( k <= n ) {

          //i = 1 pana 3
          for(i = stack[ k - 1 ] + 1; i <= n; ++i)

             //i = 1 vec[1].li > vec[ 0 ].ls
             if(vec[ i ].li > vec[ stack[ k - 1 ] ].ls) {

                   stack[ k ] = i;

                   write( k );

                   back( k + 1 );
             }

             return;
     }
}

int main(int argc, char const *argv[]) {

   int i;

   //citim numarul de intervale
   scanf("%d", &n);

   //citim intervalele
   for( i = 1; i <= n; ++i) scanf("%f %f", &vec[i].li, &vec[i].ls);

   //afisare doar intervale
   //display( n );
   sortare();

   stack[ 0 ] = 0;

   back( 1 );

  return 0;
}

//3
//submultimile unei multimi cu 3 elemente
 //1
 //2
 //3
// 1 2
// 1 3
// 1 2 3
// 2 3

//  intervalul 1: [2, 5.5]
//  intervalul 2: [3, 6]
//  intervalul 3: [6.7, 10]
