#include <iostream>
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define DIM 1024
#define max(a,b) ((a > b) ? a : b)
#define FOR(i,a,b) for(i=a;i<=b;++i)

typedef unsigned int u;

u X[DIM], Y[DIM], Answer[DIM], LCS[DIM][DIM], n, m, i, j, k;

int main(int argc, char const *argv[])
{
	freopen(FIN, "r", stdin);
		freopen(FOUT, "w", stdout);

	std::cin>>n>>m;
	
    FOR(i, 1, n) std::cin>>X[i];
        FOR(j, 1, m) std::cin>>Y[j];

        	FOR(i,1,n)
        		FOR(j,1,m)
        			if(X[i] == Y[j]) LCS[i][j] = 1 + LCS[i-1][j-1];
        		                else 
        		                	 LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
    std::cout<<LCS[n][m]<<"\n";

	i = n; j = m;

    while(i!=0 && j!=0) {
    	 if(X[i] == Y[j]) {
    	 	Answer[++k] = X[i];
    	 	i--;j--;
    	 } else {
    	 	if(LCS[i][j-1] < LCS[i-1][j]) i--;
    	 	                  else j--;
    	 }
    }

    for(i = k; i != 0; i--) std::cout<<Answer[i]<<" ";
    
	return 0;
}
