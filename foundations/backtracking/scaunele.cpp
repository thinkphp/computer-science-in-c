/*
Rearanjari (Scaunele):
Sa consideram ca n persoane n <= 10 asezate pe un rand
de n scaune doresc sa-si schimbe locurile, astfel incat
nicio persoana sa nu mai stea pe scaunul pe care era
asezata initial. Scrieti un program care sa genereze toate
rearanjarile posibile.
*/

#include <iostream>

using namespace std;

int n, sol[100], used[100];

void display() {
  for(int i = 1; i <= n; ++i) printf("%d ", sol[i]);
  printf("\n");
}


void bkt(int k) {
        if(k > n) display();

        for(int i = 1; i <= n; i++)
          if(!used[i] && i!=k) {
            used[i] = 1; sol[k] = i; bkt(k+1);used[i] =0;
          }

}

int main(int argc, char const *argv[]) {
  n = 4;
  bkt(1);
  return 0;
}
