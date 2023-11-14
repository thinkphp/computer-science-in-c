#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
#include<stdio.h>
//#include<stdlib.h>
#include<math.h>
//#include<string.h>
//#include<time.h>
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
int main() {
	int A[100] = {},n,i;
	double ave, val;
	fscanf(stdin, "%d", &n);
	for (i = ave=0; i < n; i++) 
		fscanf(stdin, "%d", &A[i]),ave+=A[i];
	ave /= n;
	for (i = val = 0; i < n; i++)
		val += (A[i] - ave)*(A[i]-ave);
	val = sqrt(val / n);
	P(.1lf, val);
	return 0;
}
