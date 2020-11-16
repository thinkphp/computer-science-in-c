#include <iostream>
#include <stack>
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define maxsize 1024
#define max(a,b) ( (a > b) ? a : b)

using namespace std;

typedef unsigned int uint;

int main(int argc, char const *argv[])
{
	stack<int> stack;
	uint X[maxsize+1], Y[maxsize+1];
	uint matLCS[maxsize+1][maxsize+1];
    uint n, m;

    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    cin>>n>>m;

    for (uint i = 1; i <= n; ++i)
    {
    	cin>>X[i];
    }
   
    for (uint j = 1; j <= m; ++j)
    {
    	cin>>Y[j];
    }

    for (uint i = 1; i <= n; ++i)
    {
       for (uint j = 1; j <= m; ++j) {

           if(X[i] == Y[j]) {

           	  matLCS[ i ][ j ] = 1 + matLCS[i - 1][j - 1];           	  

           } else {

              matLCS[ i ][ j ] = max(matLCS[i][j-1], matLCS[i-1][j]);
           }

       }
    } 
    
    cout<<matLCS[n][m]<<endl;
   
    uint i, j;

    i = n;
    j = m;

    while( i != 0 && j != 0) {

         if(X[i] == Y[j]) {

         	stack.push(X[i]);

         	i--; j--;

         } else {

         	if(matLCS[i][j-1] < matLCS[i-1][j]) {

         		i--;

         	} else {
         		
         	    j--;
         	}
         }
    }
   
    while(!stack.empty()) {

    	  cout<<stack.top()<<" ";
    	  stack.pop(); 
    }

	return 0;
}
