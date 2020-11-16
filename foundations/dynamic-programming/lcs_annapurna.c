#include <stdio.h>
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define maxsize 1024

typedef unsigned int u;

u max(u a, u b) {
      if(a > b) return a;
           else return b;
}

//global
u X[maxsize], 
  Y[maxsize], 
  ans[maxsize], 
  matLCS[maxsize][maxsize], 
  n, m;

u createMatrix() {
  
  for(u i = 1; i <= n; ++i) {

  	for(u j = 1; j <= m; ++j) {

  		if(X[i] == Y[j]) {

  		   matLCS[i][j] = 1 + matLCS[i-1][j-1];

  		} else {

  		   matLCS[i][j] = max(matLCS[i][j-1], matLCS[i-1][j]);
  		}
    }		

  }  

  return matLCS[n][m];
}  

void createSubseq(u i, u j) {

     if(i == 0 || j == 0) return;

     if(X[i] == Y[j]) {
 
        createSubseq(i - 1, j - 1);          

     	printf("%d ", X[i]);

     } else {

     	if(matLCS[i][j-1] < matLCS[i-1][j]) {
     
     	   createSubseq(i - 1, j);

        } else {

           createSubseq(i, j - 1);         

        } 
     }   

}

int main(int argc, char const *argv[])
{
	freopen(FIN, "r", stdin); 
	freopen(FOUT, "w", stdout); 

	scanf("%d %d", &n, &m);
	
	for(u i = 1; i <= n; ++i) {
		scanf("%d", &X[i]);
	}
	for(u j = 1; j <= m; ++j) {
		scanf("%d", &Y[j]);
	}	
	
	printf("%d\n", createMatrix());

	createSubseq(n, m);
	return 0;
}
