#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double mean(int *a, int n) {
    int i;
    int sum = 0;
    
    for(i = 0; i < n; i++)
        sum += a[i];
    
    return (double)sum / (double)n;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

double median(int *a, int n) {
    int i;
    qsort(a, n, sizeof(int), cmp);

    if(n % 2 != 0) {
        return (double)a[n/2];
    }else {
        return mean(&a[n/2-1], 2);
    }
}

int mode(int *a, int n) {
    int i;
    int max = 0;
    int count = 1;
    int mode;
    
    qsort(a, n, sizeof(int), cmp);

    for(i = 0; i < n; i++) {
        if(a[i] == a[i+1]) {
            count++;
        }else {
            if(count > max) {
                mode = a[i];
                max = count;        
            }
            count = 1;
        }
    }
    
    return mode;
}

int main() {
    int i;
    int n;
    int *x;
    
    scanf("%d", &n);
    x = (int *)malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++)
        scanf("%d", &x[i]);
    
    printf("%.1f\n", mean(x, n));
    printf("%.1f\n", median(x, n));
    printf("%d\n", mode(x, n));
    
    free(x);
    return 0;
}
