#include <iostream>
/*
Algoritmul lui Euclid extins

24x + 15y = gcd(24,15) = d(ecuatie diofantica)
24x + 16y = gcd(24,16) = d

24x + 15y = gcd(24,15) / c

24x + 15y = 3/147

2x + 4y = gcd(2,4) = d (nu are solutii)
a    b   c

ax + by = gcd(a,b) = d

Identitatea lui Bezout. demonstratia o gasesti
https://ro.wikipedia.org/wiki/Identitatea_lui_B%C3%A9zout

gcd( a, b ) = gcd( b, a mod b )

gcd(10, 3) = gcd(3, 10 mod 3)

gcd(10, 3) = gcd(3, 1)

gcd(10, 3) = gcd(1, 3 mod 1)

gcd(10, 3) = gcd(1, 0)

10 = 3*3 + r => q = 3, r =1, a = 10, b = 3

notam pe
a = qb + r

q = a/b
r = restul

ax + by = d
gcd(a,b) = gcd(b, a mod b)

          r
bx0 + (a mod b)y0 = d <=> bx0 + ry0 = d

ax + by = d

bx0 + ry0 = d
(qb + r)x + by = d
       ax + by = d

reformulam in functie de b si r

b(qx + y) + xr = d
b     x0 + y0r = d

=> x = y0
si
x0 = qx + y => y = x0 - qx dar x = y0 => y = x0 - qy0

|x = y0
|
|y = x0 - qy0

//varianta recursiva
void ExtendedEuclid(int a, int b, int *d, int *x, int *y) {

   if(b == 0) {
       *d = a;
       *x = 1;
       *y = 0;
   } else {
      int x1, int y1;
      ExtendedEuclid(b, a % b, d, &x1, &y1) ;
      *x = y1;
      *y = x1 - (a/b)y1;
   }

}

//varianta iterativa
void ExtendedEuclidIterative(int a, int b, int *d, int *x, int *y) {

}

*/
//euclid clasic
int euclid(int a, int b) {
    if(b == 0) return a;
    else return euclid(b, a % b);
}

int fact(int n) {
   if(n == 1) return 1;
   else return n * fact(n - 1);
}

/*
n = 5
level 5:           1
level 4:  2 * fact(1) => 2 * 1
level 3:  3 * fact(2) => 3 * 2
level 2 : 4 * fact(3) => 4 * 6
level 1 : 5 * fact(4) => 5 * 24 = 120
*/

//                     24      16      ?        ?       ?
void ExtendedEuclid(int a, int b, int *d, int *x, int *y) {

   if(b == 0) {
       *d = a;
       *x = 1;
       *y = 0;
   } else {
      int x1,y1;
      ExtendedEuclid(b, a % b, d, &x1, &y1);
      *x = y1; //y0
      *y = x1 - (a/b)*y1;//a/b = q si y0 . x0

      std::cout<<"("<<*x<<" si "<<*y<<")\n";
   }

}

int main(int argc, char const *argv[]) {

  int a = 58;
  int b = 24;
  int c = 104;

  int d, x, y;

  ExtendedEuclid(a,b,&d,&x,&y);
  //std::cout<<"gcd(a,b)="<<d<<"\nx="<<(c/d)*x<<"\ny="<<(c/d)*y;
  std::cout<<"gcd(a,b)="<<d<<"\nx="<<x<<"\ny="<<y;
  return 0;
}

/*
a = 58
b = 24

a     b      d    x   y

58   24      2    5     -12

24   10      2    -2    5

10    4      2    1    -2

4     2      2    0    1

2     0      2    1    0

a     b      d    x    y


a = 132
b = 26

a       b       d        x         y

132    26       2        1         -5

26     2        2        0         1


2      0        2        1         0

a       b       d        x         y

(1,-5) cu gcd(132,26) = 2

ax + by = 2

132*1 + 26*(-5) = gcd(132,26) = 2
*/
