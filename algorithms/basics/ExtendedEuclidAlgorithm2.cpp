#include <cstdio>

long euclid(long a, long b, long &x, long &y) {
	if ( b==0 ) {
		x = 1,  y = 0;
		return a;
	}

	long xp, yp;
	long d = euclid(b, a%b, xp, yp);
	x = yp;
	y = xp - yp*(a/b);
	return d;
}

long T;

int main() {
	freopen("euclid3.in", "r", stdin);
	freopen("euclid3.out", "w", stdout);
	scanf("%ld", &T);
	while ( T-- ) {
		long a,b,c,d,x,y;
		scanf("%ld %ld %ld", &a, &b, &c);
		
		d = euclid(a, b, x, y);
		if ( c%d ) 
			printf("0 0\n");
		else
			printf("%ld %ld\n", x*(c/d), y*(c/d));
	}
	return 0;
}
