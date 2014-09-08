#include <iostream.h>
#include <conio.h>

void* readMatrix(int n,int m) {

      int (*adr)[10];

      adr = new int[10][10];

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

	      cout<<"mat["<<i<<"]["<<j<<"]=";cin>>adr[i][j];
	  }
      }

   return adr;
}

void* sumMatrix(int n,int m, int (*adr1)[10],int (*adr2)[10]) {

      int (*adr)[10];

      adr = new int[10][10];

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

	      adr[i][j] = adr1[i][j] + adr2[i][j];

	  }
      }

      return adr;
}

void displayMatrix(int n,int m, int (*adr)[10]) {

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

	      cout<<adr[i][j]<<" ";
	  }

	  cout<<"\n";
      }
}

void displayMainDiagonal(int n,int m, int (*mat)[10]) {

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

	    if(i == j) {

	       cout<<mat[i][j]<<" ";
	    }
	  }
      }
}


void displaySecondaryDiagonal(int n,int m, int (*mat)[10]) {

      for(int i=0;i<n;i++) {

	  for(int j=0;j<m;j++) {

	    if(j == m - i - 1) {

	       cout<<mat[i][j]<<" ";
	    }
	  }
      }
}

void displayElementsAboveSecondaryDiagonal(int n,int m, int (*mat)[10]) {

      for(int i = 0; i < n; i++) {

	  for(int j = 0; j < m; j++) {

	    if(j < m - i - 1) {

	       cout<<mat[ i ][ j ]<<" ";
	    }
	  }
      }
}


void displayElementsBellowSecondaryDiagonal(int n,int m, int (*mat)[10]) {

      for(int i = 0; i < n; i++) {

	  for(int j = 0; j < m; j++) {

	    if(j > m - i - 1) {

	       cout<<mat[i][j]<<" ";
	    }
	  }
      }
}

void displayElementsAboveMainDiagonal(int n,int m, int (*mat)[10]) {

      for(int i = 0; i < n; i++) {

	  for(int j = 0; j < m; j++) {

	    if(j > i) {

	       cout<<mat[i][j]<<" ";
	    }
	  }
      }
}

void displayElementsBellowMainDiagonal(int n,int m, int (*mat)[10]) {

      for(int i = 0; i < n; i++) {

	  for(int j = 0; j < m; j++) {

	    if(j < i) {

	       cout<<mat[i][j]<<" ";
	    }
	  }
      }
}


void main() {

     int n, m;

     int (*adr1)[10];

     int (*adr2)[10];

     int (*adr)[10];

     adr = new int[10][10];

     clrscr();

     cout<<"n=";cin>>n;

     cout<<"m=";cin>>m;

     adr1 = (int(*)[10])readMatrix(n,m);

     adr2 = (int(*)[10])readMatrix(n,m);

     adr = (int(*)[10])sumMatrix(n, m, adr1, adr2);

     cout<<"Display first matrix"<<"\n";
     displayMatrix(n,m,adr1);

     cout<<"Display second matrix"<<"\n";
     displayMatrix(n,m,adr2);

     cout<<"Sum:"<<"\n";
     displayMatrix(n,m,adr);

     cout<<"\n"<<"Main Diagonal:"<<"\n\n";
     displayMainDiagonal(n,m,adr);

     cout<<"\n"<<"Secondary Diagonal:"<<"\n\n";
     displaySecondaryDiagonal(n,m,adr);


     cout<<"\n"<<"Elements above Secondary Diagonal"<<"\n\n";
     displayElementsAboveSecondaryDiagonal(n,m,adr);

     cout<<"\n"<<"Elements bellow Secondary Diagonal"<<"\n\n";
     displayElementsBellowSecondaryDiagonal(n,m,adr);


     cout<<"\n"<<"Elements above Main Diagonal"<<"\n\n";
     displayElementsAboveMainDiagonal(n,m,adr);

     cout<<"\n"<<"Elements bellow Main Diagonal"<<"\n\n";
     displayElementsBellowMainDiagonal(n,m,adr);

     cout<<"\n"<<"Press any key for exit";
     getch();
}