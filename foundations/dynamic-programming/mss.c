#include <stdio.h>
#include <malloc.h>
#define FIN "ssm.in"
#define FOUT "ssm.out"
 
struct Arr {
       int size;
       int *data;
};
 
typedef struct Arr Arr;
 
Arr* Array(int size) {
 
     Arr *vec = (Arr*)malloc(sizeof(Arr) * size);
 
          vec->data = (int*)malloc(sizeof(int) * size);
 
          vec->size = size;
 
          for(int i = 0; i < size; ++i) {
 
               vec->data[ i ] = 0;  
          }
           	  
     return vec;      	
}
 
void display(Arr *v) {
 
     int count = v->size;
     
     for (int i = 0; i < count; ++i)
     {
     	 printf("%d ", v->data[i]);
     }
}
 
int max(int a, int b) {
 
	if(a > b) return a;
	     else return b;
}
 
void dynamic_programming(Arr *p, int *maxsum, int *start, int *end) {
 
     *maxsum = p->data[ 0 ];
     *start = 0;
     *end = -1; 
     int count = p->size,
         possibleStart = 0,
         currentSum = 0;     
 
     for (int i = 0; i < count; ++i)
      {
      	 if (currentSum < 0)      	 	
      	  {
      	  	 possibleStart = i; 
      	  } 
 
      	 currentSum = max(currentSum + p->data[i], p->data[i]);
 
      	 if(currentSum > *maxsum) {
      	 	*maxsum = currentSum;
      	    *start = possibleStart;
      	    *end = i;
      	 }   
      } 
};
 
int main(int argc, char const *argv[])
{
	int n; 
	int maxsum, 
	    start, 
	    end;
	
	freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
 
    scanf("%d", &n);
 
    Arr* vec = Array( n );
 
    for(int i = 0; i < n; ++i) {
 
    	scanf("%d", &vec->data[ i ]);
    }  
 
    dynamic_programming(vec, &maxsum, &start, &end);
 
    printf("%d %d %d\n", maxsum, start + 1, end + 1);
 
	return 0;
}
