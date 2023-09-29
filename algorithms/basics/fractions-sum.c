/*
Scrieti un program care calculeaza suma a doua fractii. Cele doua fractii de insumat se introduc de la tastatura si rezultatul se
va scrie ca o operatie de fractii ireductibile ca in exemplele de mai jos. Daca se introduce o valoare zero pentru numitor, atunc
se va cere o alta valoare pana cand aceasta va fi nenula. Se va lucra cu numere naturale pozitive pentru numaratori si numitori din
intervalul [1,80000];
 
Input:
Introduceti cele doua fractii:
 
Fractie#1:
Numaratorul = 2
Numitorul = 3
Fractie#2:
Numaratorul = 9
Numitorul = 19
Fractie#suma:
2/3+1/2=7/6
 
*/
#include <stdio.h>
 
typedef struct Fraction {
  int nr,
      num;
} TFraction;
 
int euclid(int a, int b) {
  int r;
  while(b){
    r = a%b;
    a = b;
    b = r;
  }
  return a;
}
 
void display(TFraction f){
  printf("%d/%d\n",f.nr,f.num);
}
 
void simplify(TFraction *p) {
    int gcd = euclid(p->nr, p->num);
    p->nr = p->nr/gcd;
    p->num = p->num/gcd;
}
 
void read(TFraction*p){
  printf("Nr=");
  scanf("%d",&p->nr);
  printf("Num=");
  while(scanf("%d",&p->num) && !p->num )
        printf("The denominator must be !=0. Again!");
  simplify(p);
}
 
void sum(TFraction f1, TFraction f2, TFraction *p) {
  p->nr = f1.nr * f2.num + f2.nr * f1.num;
  p->num = f1.num * f2.num;
  simplify(p);
}
 
int main(int argc, char const *argv[]) {
  TFraction F1,F2,FSum;
  printf("Fraction#1:\n");
  read(&F1);
  display(F1);
  printf("Fraction#2:\n");
  read(&F2);
  display(F2);
  sum(F1,F2,&FSum);
  printf("%s","Fraction#Sum = ");
  display(FSum);
  printf("%d/%d+%d/%d=%d/%d\n",F1.nr, F1.num, F2.nr, F2.num,FSum.nr, FSum.num);
  return 0;
}
 
