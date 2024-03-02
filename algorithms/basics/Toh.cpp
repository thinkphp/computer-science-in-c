#include <bits/stdc++.h>
 
using namespace std;
 
int fastexp(int b, int e){
	if(e == 0)return 1;
	int sqrt = fastexp(b,e/2);
	sqrt *= sqrt;
	if(e & 1)sqrt *= b;
	return sqrt;
}
 
void hanoi(int num, int so, int au, int des){
	if(num == 1){
		cout << so << " " << des << '\n';
		return;
	}
	hanoi(num-1, so, des, au);
	cout << so << " " << des << '\n';
	hanoi(num-1, au, so, des);
}
 
int main(){
	int n;
	cin >> n;
	cout << fastexp(2,n)-1 << '\n';
	hanoi(n, 1, 2, 3);
}
