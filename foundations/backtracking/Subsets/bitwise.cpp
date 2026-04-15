#include <iostream>

using namespace std;

//E eficient: O(n · 2ⁿ)
void gen(int n) {

    //cout<<"{ }\n";

	for(int mask = 1; mask <= ((1<<n));++mask) {

		  cout<<"{ "; 

          for(int i = 0; i < n; ++i) {

                 if(mask & (1<<i)) {

                 	cout<<i+1<<" ";
                 }
          }

          cout<<"}"; 

          cout<<endl;
	}

}

int main(int argc, char const *argv[])
{
	
	int n;
	n = 3;
	gen(n);
	return 0;
}
