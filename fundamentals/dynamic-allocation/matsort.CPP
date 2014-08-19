#include <iostream.h>
#include <conio.h>

//prototypes functions
void* readMatrix(int n,int m);
void displayMatrix(int n,int m,int (*adr)[20]);

void sortColsMatrix(int n,int m, int (*adr)[20]);
void sortColsMatrix2(int n,int m, int (*adr)[20]);
void sortLinesMatrix(int n,int m, int (*adr)[20]);
void sortLinesMatrix2(int n,int m, int (*adr)[20]);

void sortMainDiagonal(int n,int m, int (*adr)[20]);
void sortSecondDiagonal(int n,int m, int (*adr)[20]);
int* insertionSort(int v[30], int n);
int* insertionSort2(int v[30], int n);

void main() {

     int (*adr)[20];
     int i,j,n,m;


     //clear screen
     clrscr();
     //number of lines
     cout<<"Lines=";
     //read in n the number of lines
     cin>>n;
     //number of cols
     cout<<"Cols=";
     //store in m the number of cols
     cin>>m;

     //read the input matrix
     adr=(int(*)[20])readMatrix(n,m);

     //display the matrix
     displayMatrix(n,m,adr);

     //sorted cols matrix
     //cout<<"\nSort cols matrix\n";

     //sorted lines matrix
     cout<<"\nSort lines matrix\n";
     sortLinesMatrix2(n,m,adr);

     //display the Matrix
     displayMatrix(n,m,adr);

     //sorting by insertion in action for main diagonal
     //
     //x 0 0
     //0 x 0
     //0 0 x
     //
     cout<<"\nSorting by insertion for Main Diagonal using Binary Search";
     sortMainDiagonal(n,m,adr);

     cout<<"\n";

     //display Matrix
     displayMatrix(n,m,adr);

     //sorting by insertion in action for Second Diagonal
     //
     //0 0 x
     //0 x 0
     //x 0 0
     //
     cout<<"\nSorting by insertion for Second Diagonal";
     sortSecondDiagonal(n,m,adr);

     cout<<"\n";

     //display Matrix
     displayMatrix(n,m,adr);



     //press any key for exit
     cout<<"\nPress any key for exit\nhttp://thinkphp.ro";

     //waiting for press any key to exit
     getch();

}

void* readMatrix(int n,int m) {

      int (*adr)[20];
      adr = new int[20][20];

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

		  cout<<"mat["<<i<<"]["<<j<<"]=";cin>>adr[i][j];
	  }
      }

      return adr;
}

void displayMatrix(int n,int m,int (*mat)[20]) {

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

		  cout<<mat[i][j]<<" ";
	  }
	  cout<<"\n";
      }

}

//first version with two fors
void sortColsMatrix(int n,int m,int (*adr)[20]) {

     int i,

	 j,

	 k,

	 sign;

     for(i = 0; i < m; i++) {

	 if( i&1 ) sign = -1;

	     else

		   sign = 1;


	 for(j = 0;j < n - 1; j++) {

	     for(k = j + 1; k < n; k++) {

		 if( ((adr[ j ][ i ] - adr[ k ][ i ]) * sign) < 0) {

		     int temp = adr[j][i];

			 adr[j][i] = adr[k][i];

			 adr[k][i] = temp;

		 }
	     }
	 }


     }

}

//second version with do...while and for within
void sortColsMatrix2(int n,int m,int (*adr)[20]) {

     int i,
	 j,
	 sign,
	 swapped = 1;

     for(i = 0; i < m; i++) {

	 if( i&1 ) sign = -1;

	     else
		   sign = 1;

	 do {

	  swapped = 0;

	  for(j = 0;j < n - 1; j++) {

		 if( ((adr[ j ][ i ] - adr[ j + 1 ][ i ]) * sign) < 0) {

		     int temp = adr[ j ][ i ];

			 adr[ j ][ i ] = adr[ j + 1 ][ i ];

			 adr[ j + 1 ][ i ] = temp;

			 swapped = 1;

		 }
	  }

	 }while(swapped);
     }
}

//sorting lines with bubble sort with temporary variable
void sortLinesMatrix(int n, int m, int (*adr)[20]) {

     int i,

	 j,

	 k = -1,

	 swapped,

	 sign;

     for(i = 0; i < n; i++) {

	 if( i&1 ) sign = -1;

	     else
		   sign = 1;

	 k = -1;

	 do{

	   swapped = 0;

	   k++;

	   for(j = 0; j < m - k - 1; j++) {


	     if((adr[ i ][ j ] - adr[ i ][ j + 1])*sign < 0) {


		 int temp = adr[i][j];

		     adr[i][j] = adr[i][j+1];

		     adr[i][j+1] = temp;

		     swapped = 1;
	     }

	   }

	 }while(swapped);

     }
}

// sorting lines with bubble sort without termporary variable,
// just using XOR
void sortLinesMatrix2(int n, int m, int (*adr)[20]) {

     int i,

	 j,

	 k = -1,

	 swapped,

	 sign;

     for(i = 0; i < n; i++) {

	 if( i&1 ) sign = -1;

	     else
		   sign = 1;
	 k = -1;

	 do{

	   swapped = 0;

	   k++;

	   for(j = 0; j < m - k - 1; j++) {


	     if((adr[ i ][ j ] - adr[ i ][ j + 1])*sign < 0) {


		 int xor = adr[i][j]^adr[i][j+1];

		     adr[i][j] = xor^adr[i][j];

		     adr[i][j+1] = xor^adr[i][j+1];

		     swapped = 1;
	     }

	   }

	 }while(swapped);

     }
}


void sortMainDiagonal(int n, int m, int (*adr)[20]) {

	   int i,j;

	   int *p;

	   int aux[20];

	   for(i = 0; i < n; i++) {

	       for(j = 0; j < m; j++) {

		   if(i == j) {

		      aux[i] = adr[i][j];
		   }

	       }
	   }

	   p = insertionSort(aux, n);

	   for(i = 0; i < n; i++) {

	       for(j = 0; j < m; j++) {

		   if(i == j) {

		      adr[i][j] = p[i];
		   }

	       }
	   }


}

int* insertionSort(int vec[30], int n) {


     int i,

	 j,

	 li,

	 ls,

	 aux, middle;

     for(i = 1; i < n; i++) {

	 aux = vec[i];

	 li = 0;

	 ls = i-1;

	 while(li <= ls) {

	      middle = (li+ls)/2;

	      if(aux < vec[ middle ]) {

		     ls = middle - 1;

	      } else {

		     li = middle + 1;
	      }
	 }


	 for(j=i-1;j>=li;j--) {

	     vec[j+1] = vec[j];
	 }

	 vec[ li ] = aux;
     }

   return vec;
}

void sortSecondDiagonal(int n, int m, int (*adr)[20]) {

	   int i,j;

	   int *p;

	   int aux[20];

	   for(i = 0; i < n; i++) {

	       for(j = 0; j < m; j++) {

		   if(i == n - j - 1) {

		      aux[i] = adr[i][j];
		   }

	       }
	   }

	   p = insertionSort2(aux, n);

	   for(i = 0; i < n; i++) {

	       for(j = 0; j < m; j++) {

		   if(i == n - j - 1) {

		      adr[i][j] = p[i];
		   }

	       }
	   }


}


int* insertionSort2(int vec[30], int n) {


     int i,

	 j,

	 aux;

     for(i = 1; i < n; i++) {

	 aux = vec[i];

	 j = i - 1;

	 while(j>=0 && aux < vec[j]) {

	       vec[j+1] = vec[j--];
	 }

         vec[j+1] = aux;
     }

   return vec;
}