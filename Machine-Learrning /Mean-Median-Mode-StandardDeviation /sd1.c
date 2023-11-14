#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i;
    scanf("%d",&n);
    int x[n],sum=0;
    float mean,distance=0;
    for (i=0;i<n;i++) {
        scanf("%d",&x[i]); 
        sum=sum+x[i];}
    mean = sum/n;
    for (i=0;i<n;i++) {
        distance = distance + pow((x[i]-mean), 2);
        // printf("%f..",distance);
        }
    printf("%.1f",round((sqrt(distance/n))*10)/10);
    return 0;
}
