#include <stdio.h>

int getMax(int *p, int lo, int hi) {
	
    if(lo == hi) {

       return p[lo];

    } else {

      int middle = (lo + hi)>>1;

      int a = getMax(p, lo, middle);

      int b = getMax(p, middle + 1, hi);                        

      if(a > b) return a;

           else return b;
    }           

}

int main(int argc, char const *argv[])
{
	
	int v[8] = {11,33,1818,34,21,90,191,77};

	int max;

	max = getMax(v, 0, sizeof(v)/sizeof(v[0]) - 1);

	printf("MAX = %d\n", max);

	return 0;
}
