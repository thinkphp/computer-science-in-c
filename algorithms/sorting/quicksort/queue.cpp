#include <cstdio>
#include <queue>
#define FIN "queue.in"
#define FOUT "queue.out"

using namespace std;

FILE *fin,
     *fout;

struct cmp {
 
       bool operator()(const int &a, const int &b) {

            return (a>b);
       }
};

priority_queue<int, vector<int>, cmp> q;

int n;

void read() {

     unsigned int elem;

     fin = fopen(FIN, "r");

     fscanf(fin, "%d", &n);

     for(int i = 1; i <= n; i++) {

         fscanf(fin, "%d", &elem);

         q.push( elem );
     }
     
     fclose( fin );  
};

void write() {

     fout = fopen(FOUT, "w");

     while( !q.empty() ) {

             fprintf(fout, "%d ", q.top());

             q.pop(); 
     }

     fclose( fout );
};

int main() {

    read();
    write();

   return(0);
}