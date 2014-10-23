#include <cstdio>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int vec[MAXN], 
    n; 
  
      void _merge(int li, int m, int ls) {

           int i = li,          
               j = m + 1,
               aux[MAXN],
               k = 0;

            while(i <= m && j <= ls) {

                  if(vec[i] < vec[j]) {

                     aux[k++] = vec[i++]; 

                  } else {

                     aux[k++] = vec[j++]; 
                  }
            }

            if(i<=m) {

               for(int r=i; r<=m; r++) {

                   aux[k++] = vec[r];  
               }

            } else {

               for(int r=j; r<=ls; r++) {

                   aux[k++] = vec[r];  
               }
            }

            k = 0;

            for(int pos = li; pos <= ls; pos++) {

                vec[ pos ] = aux[k++]; 
            }
      }


      int _MergeSort(int li, int ls) {
 
           if(li==ls) return vec[ li ];

           else {

                int middle = (li+ls)>>1;

                _MergeSort(li, middle); 
                _MergeSort(middle + 1, ls);
                _merge(li, middle, ls);
           }  
      };

//prototypes
void read();
void write();

int main() {
      
    read();
 
    _MergeSort(0, n-1);

    write();
   
    return(0);
}


void read() {
  
     int i;
  
     freopen(FIN, "r", stdin);
  
     scanf("%d", &n);
  
     for(i = 0; i < n; i++) {
  
         scanf("%d", &vec[ i ]);
     }
  
     fclose( stdin );
};

void write() {
  
     int i;
  
     freopen(FOUT, "w", stdout);
  
     for(i = 0; i < n; i++) {
  
         printf("%d ", vec[ i ]);
     }
  
     fclose(stdout);
};
