#include <iostream>
#define FIN "permutari.in"
#define FOUT "permutari.out"
#define SIZE 100

using namespace std;

int stack[ SIZE ], n;

int ok(int k) {

	for(int i = 1; i < k; ++i) {

            if(stack[i] == stack[k]) return 0;
	}
	return 1;
}

void back(int k) {

	 for(int i = 1; i <= n; ++i) {

             stack[k] = i;

             if(ok(k)) {
             	if(k == n) {
             		for(int i = 1; i <= n; ++i) cout<<stack[i]<<" ";
                    cout<<endl;
             	} else {
             		back(k+1);
             	}
             } 

	 }
}

int main(int argc, char const *argv[])
{

	freopen(FIN,"r",stdin);
	freopen(FOUT,"w",stdout);

	cin>>n;

	back(1);
	
	return 0;
}