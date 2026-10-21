#include <iostream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define DIM 500005

int HEAP[ DIM ], 
    sizeH;

using namespace std;

void up( int child ) {

     int parent = child / 2;

     while( parent ) {

     	   if(HEAP[parent] > HEAP[child]) {

                  int temp = HEAP[parent];

                  HEAP[parent] = HEAP[child];

                  HEAP[child] = temp;      	

                  child = parent;

                  parent = child / 2;

     	   } else break;

     }
}

void down( int parent ) {

         while(2 * parent <= sizeH) {


         	   int child = 2 * parent;

         	   if(2 * parent + 1 <= sizeH && HEAP[2 * parent + 1] < HEAP[2 * parent]) child++;

         	   if(HEAP[parent] <= HEAP[child]) break;

         	   int temp = HEAP[parent];
         	   HEAP[parent] = HEAP[child];
         	   HEAP[child] = temp;

         	   parent = child;
         }

}

void insertHeap( int val ) {

     //cout<<"Insert into HEAP: "<< val<<endl;     
         
     HEAP[ ++sizeH ] = val;

     up( sizeH );
}

int removeHeap() {

	int ret = HEAP[1];

	HEAP[1] = HEAP[sizeH--];

    down(1);  

    return ret;
}

int main(int argc, char const *argv[])
{
	//int arr[] = {15,6,7,8,1,2,3,11,33,44,19}, n = sizeof(arr)/sizeof(arr[0]);
	freopen(FIN,"r", stdin);
	freopen(FOUT,"w", stdout);
    int x, 
        n;
    cin>>n;
    for(int i = 0; i < n; ++i) {
    	//insertHeap(arr[i]);
    	cin>>x;
    	insertHeap(x);
    }   

    for(int i = 0 ; i < n; ++i) cout<<removeHeap()<<" ";
	return 0;
}