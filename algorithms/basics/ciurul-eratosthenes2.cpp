#include <stdio.h>   
  
int N, cnt;   
char prim[2000005];   
  
int main(void)   
{   

    int i, j;

    freopen("ciur.in", "r", stdin);
    freopen("ciur.out", "w", stdout);

    scanf("%d", &N);

    //for (i = 2; i <= N; ++i)
      //	prim[i] = 1;

    for (i = 2; i <= N; ++i)
	if (!prim[i])
	{
	    ++cnt;
	    for (j = i+i; j <= N; j += i)
		prim[j] = 1;
	}
  
    printf("%d\n", cnt);   
  
    return 0;   
}  
