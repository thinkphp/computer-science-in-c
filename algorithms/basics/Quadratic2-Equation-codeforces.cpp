#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,c;
	cin>>a>>b>>c;
	if(a==0&&b==0&&c==0){
		cout<<"-1"<<endl;
		return 0;
	}else if(a==0&&b==0&&c!=0){
		cout<<"0"<<endl;
		return 0;
	}else if(a==0&&b!=0){
		cout<<"1"<<endl;
		cout<<fixed<<setprecision(10)<<-c/b<<endl;
		return 0;
	}
	if(b*b-4*a*c>0){
		cout<<"2"<<endl;
		double x1=(-b-sqrt(b*b-4*a*c))/2/a;
		double x2=(-b+sqrt(b*b-4*a*c))/2/a;
		cout<<fixed<<setprecision(10)<<min(x1,x2)<<endl;
		cout<<fixed<<setprecision(10)<<max(x1,x2)<<endl;
	}else if(b*b-4*a*c==0){
		cout<<"1"<<endl;
		double x1=(-b-sqrt(b*b-4*a*c))/2/a;
		cout<<fixed<<setprecision(10)<<x1<<endl;
	}else{
		cout<<"0";
	}
	return 0;
}	
