#include <stdio.h>
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define max(a,b) ((a > b) ? a : b)
#define MAXSIZE 1024

int main(int argc, char const *argv[])
{
	int matLCS[ MAXSIZE + 1 ][ MAXSIZE + 1],

	    vec1[ MAXSIZE + 1], 

	    vec2[ MAXSIZE + 1 ],

	    i , j, k, n, m;

	    freopen(FIN, "r", stdin);

        freopen(FOUT, "w", stdout);

        scanf("%d %d", &n, &m);

        for(i = 1; i <= n; ++i) scanf("%d", &vec1[i]);

        	for(j = 1; j <= m; ++j) scanf("%d", &vec2[j]);

        for(i = 1; i <= n; ++i) {

        	for(j = 1; j <= m; ++j) {

                if(vec1[ i ] == vec2[ j ]) {

                	    matLCS[ i ][ j ] = 1 + matLCS[i-1][j-1]; 

                } else {
                	
                	    matLCS[ i ][ j ] = max(matLCS[ i ][ j - 1 ], matLCS[ i - 1 ][ j ]);
                }
        	}
        }

 
        i = n;
        j = m;        
        k = matLCS[n][m];

        printf("%d\n", k);

        int sol[k + 1];
        k--;

        while( i != 0 && j != 0) {

        	   if(vec1[i] == vec2[j]) {

        	   	  sol[k--] = vec1[i];

        	   	  i--;

        	   	  j--;

        	   } else {

        	   	if(matLCS[i][j-1] < matLCS[i-1][j]) {

        	   	   i--;

        	   	} else {

        	   	   j--; 	
        	   	}

        	   }
        }

        for(i = 0; i < matLCS[n][m]; ++i) printf("%d ", sol[i]);

	return 0;
}
