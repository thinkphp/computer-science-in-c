#include <fstream>

using namespace std;

ifstream cin("fractii.in");
ofstream cout("fractii.out");

int cmmdc(int a,int b){
    while(b){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int n,cnt;

int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            if(cmmdc(i,j)==1)
                cnt++;
    }
    cout<<cnt;
}
