#include <iostream.h>
#include <conio.h>

//prototypes functions
void* readMatrix(int n,int m);
void displayMatrix(int n,int m,int (*adr)[20]);
void sortColsMatrix(int n,int m, int (*adr)[20]);
void sortColsMatrix2(int n,int m, int (*adr)[20]);

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

     //sort cols matrix
     cout<<"\nSort col matrix\n";

     sortColsMatrix2(n,m,adr);

     //dislpay sorted cols matrix
     displayMatrix(n,m,adr);


     //press any key for exit
     cout<<"\nPress any key for exit\n";

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

//cols are sorted with bubble sort method
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

			 adr[ j + 1][ i ] = temp;

			 swapped = 1;

		 }
	  }

         }while(swapped);
     }


}



