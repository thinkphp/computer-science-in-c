#include<stdio.h>
#include<vector>
using namespace std;
#define ll long long
const ll MAX=1LL<<60;
int n;
ll a[505][505];
vector <int> b;
int main()
{
	freopen("podm.in","r",stdin);
	
	freopen("podm.out","w",stdout);
	
	scanf("%d",&n);
	
	for(int i=0;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		b.push_back(x);
	}
	
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i+l<=n;i++)
		{
			int j=i+l;
			a[i][j]=MAX;
			for(int k=i;k<j;k++)
			{
				a[i][j]=min(a[i][k]+a[k+1][j]+(ll)b[i-1]*b[k]*b[j],a[i][j]);
			}
		}
	}
	printf("%Ld\n",a[1][n]);
	return 0;
}
