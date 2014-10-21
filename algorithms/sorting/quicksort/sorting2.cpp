#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

FILE *fin,
     *fout;

vector<unsigned int> v;
int n;

void read() {

     unsigned int elem;

     fin = fopen(FIN, "r");

     fscanf(fin, "%d", &n);

     for(int i = 1; i <= n; i++) {

         fscanf(fin, "%d", &elem);

         v.pb( elem );
     }
     
     fclose( fin );  
};

void write() {

     fout = fopen(FOUT, "w");

     for(int i = 0; i < n; i++) 

         fprintf(fout, "%d ", v.at( i ) ); 

     fclose( fout );
};

bool cmp(unsigned int a, unsigned int b) {

     return (a<b);
}

int main() {

    read();

    sort(v.begin(), v.end(), cmp);    

    write(); 

    return(0);
}