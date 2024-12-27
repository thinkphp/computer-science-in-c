# include <stdio.h>
# include <math.h>

const int MAX=1000000;

int main()
{
long int n,i,j,ok;
long int aux,ciur[MAX]={0};
long long phi[MAX]={0};
FILE *f=fopen("fractii.in","r");
fscanf(f,"%ld",&n);
fclose(f);
long long nr=1,nrp;
i=2;
while (i<=MAX)
	{
	if (ciur[i]==0)
	for (j=2*i;j<=MAX;j+=i)
		if (ciur[j]==0) ciur[j]=i;
	i++;
	}
for (i=2;i<=n;i++)
	if (ciur[i]==0)
		{nr+=(i-1)*2;phi[i]=i-1;}
	else
		{
		if ((i/ciur[i])%ciur[i]==0) nrp=phi[i/ciur[i]]*ciur[i];
		else nrp=phi[i/ciur[i]]*(ciur[i]-1);
		nr+=2*nrp;
		phi[i]=nrp;
		}
FILE *g=fopen("fractii.out","w");
fprintf(g,"%lld\n",nr);
fcloseall();
return 0;
}
