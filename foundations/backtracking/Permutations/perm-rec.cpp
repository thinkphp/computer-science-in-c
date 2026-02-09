#include <iostream>
#define SIZE 100

using namespace std;

int n, sol[SIZE],
       used[SIZE];

void perm(int k) {

     if(k == n + 1)  {

     	for(int i = 1; i <= n; ++i) cout<<sol[i]<<" ";

     		cout<<endl;

     } else {

     	for(int i = 1; i <= n; ++i) {

     		if(!used[i]) {
     			used[i] = 1;
     			sol[k] = i;
     			perm(k+1);
     			used[i] = 0;
     		}
     	}
     }    
}       

int main(int argc, char const *argv[])
{

	freopen("permutari.in","r",stdin);
	freopen("permutari.out","w",stdout);

	cin>>n;

	perm(1);
	
	return 0;
}