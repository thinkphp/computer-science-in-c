#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

struct Arr {
     
           int size;
           int *data;
};

typedef struct Arr Arr;

Arr* Array(int size) {

     Arr* v = (Arr*)malloc(sizeof(Arr) * size);      

          v->data = (int*)malloc(sizeof(int) * size); 

          v->size = size;

          for (int i = 0; i < size; ++i)
	      {
	 	       v->data[i] = 0;
	      }

          return v;
}

void run_combo(Arr *v) {

	 float shrinkFactor = 1.3;
	 int gap = v->size, 
	     count = v->size,
	     swapped = 0, 
	     i;

	     while(gap > 1 || swapped) {

	     	   swapped = 0;

	     	   if(gap > 1) gap = gap/shrinkFactor;

	     	   for (int i = 0; (i + gap) < count; ++i)
	     	   {
	     	   	    if(v->data[i] > v->data[i+gap]) {

	                    int holder = v->data[i];
	                    v->data[i] = v->data[i+gap];
	                    v->data[i+gap] = holder;
	                    swapped = 1;
	                }    
	     	   }
         }

}

void display(Arr* arr) {

     freopen(FOUT, "w", stdout);

     int count = arr->size;

	 for (int i = 0; i < count; ++i)
	 {
	 	 printf("%d ", arr->data[ i ]);
	 }
}


int main(int argc, char const *argv[])
{
	int n;

	freopen(FIN, "r", stdin);

	scanf("%d", &n);

	Arr* v = Array( n );

	     for (int i = 0; i < n; ++i)
	     {
	     	scanf("%d", &v->data[i]);
	     }

         run_combo(v);

	     display(v);

	return 0;
}
