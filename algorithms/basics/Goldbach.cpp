/*
/Christian Goldbach a fost un matematician celebru. S-a nascut
la 18 martie 1690 la Konigsberg, Prusia (astazi Kalinsgrad, Rusia) si a murit
la 20 noiembrie 1764 in Moscova. El a studiat dreptul si l-a preocupat, de asemenea,
de matematicam in special de teoria numerelor. Marginal, s-a mai interesat de domenii
ca sumele infinite, teoria curbelor, teoria ecuatiilor. El a calatorit mult in Europa si a avut
discutii fructuoase cu matematicieni celebri, precum Leibniz, Bernoulli, de Moivre, Hermann. O martie parte
din munca sa se reflecta in corespondenta cu Euler. Aceasta corespondenta a durat
aproape 20 de ani si reprezinta unul dintre cele mai importante documente stiintifice din secolul
al XVIII - lea. A lucrat ca profesor de matematica si istoric la noua
infiinta academie din St. Petersburg si a predat printului Petru (viitorul tar Petru al doilea). De la el
provine o celebra conjectura in teoria numerelor. Aceasta este mentionata pentru prima oara
intr-o scrisoare adresata lui Euloer la 7 iulie 1742 in care afirma ca: "se pare ca orice numar mai mare decat 2
se poate scrie ca suma de trei numere prime". Euler a reexprimat aceasta conjectura in forma:
"orice numar intreg pozitiv >=4 poate fi scris ca suma de doua numere prime" denumita si conjectura lui Goldbach.

Se considera un tablou bidimensional NxM cu elemente numere naturale in intervalul [4,1000]. Sa se indice pozitiile
elementelor pare ale matricei si toate descompunerile acestora a suma de numere prime, ca in exemplul urmator:
Input:
Dimensiunea matricei:
2 3
12 346 789
44 7 82

Output:
Matrix:
  12  346  789
  44    7   82

mat[0][0] = 12
12 = 5 + 7
mat[0][1] = 346
346 = 29 + 317
346 = 53 + 293
346 = 83 + 263
346 = 89 + 257
346 = 107 + 239
346 = 113 + 233
346 = 149 + 197
346 = 167 + 179
346 = 173 + 173

mat[1][0] = 44
44 = 3 + 41
44 = 7 + 37
44 = 13 + 31
mat[1][2] = 82
82 = 3 + 79
82 = 11 + 71
82 = 23 + 59
82 = 29 + 53
82 = 41 + 41
*/
#include <stdio.h>

int isPrime(int n) {
    int prime = 1,
        i;
    i = 2;
    if(n<=1) return 0;
    if(n == 2 || n == 3) return 1;
    while(i*i<=n && prime) {
      prime = (n%i)!=0;
      i++;
    }
    return prime;
};
int main(int argc, char const *argv[]) {
  /*
  int n = 346;

  for(int i = 4; i <= n/2; ++i) {

      if(isPrime(i) && isPrime(n-i)) {

         printf("%d = %d + %d\n", n, i, n - i);
      }
  }
  */

  int n, //number of the rows
      m, //number of the cols
      matrix[100][100];
      scanf("%d %d",&n,&m);
      for (size_t i = 0; i < n ; i++) {
       for (size_t j = 0; j < m; j++) {
            scanf("%d",&matrix[i][j]);
        }
      }

      printf("%s\n", "Matrix:");
      for (size_t i = 0; i < n ; i++) {
       for (size_t j = 0; j < m; j++) {
            printf("%4d ", matrix[i][j]);
        }
         printf("\n");
      }

      printf("\n");

      for (size_t i = 0; i < n ; i++) {

       for (size_t j = 0; j < m; j++) {

            if(!(matrix[i][j]&1)) {

              printf("mat[%ld][%ld] = %d\n", i, j, matrix[i][j]);

              for (size_t k = 2; k <= matrix[i][j]/2; k++) {

                  if(isPrime(k) && isPrime(matrix[i][j]-k)) {

                     printf("%d = %ld + %ld\n", matrix[i][j], k,  matrix[i][j] - k);

                  }
              }
            }
        }
         printf("\n");
      }
  return 0;
}
