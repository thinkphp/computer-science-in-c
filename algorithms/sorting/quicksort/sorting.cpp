#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back
#define FIN "sorting.in"
#define FOUT "sorting.out"

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

     for(vector<unsigned int>::iterator it = v.begin(); it != v.end(); ++it) 

         fprintf(fout, "%d ", *it); 

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