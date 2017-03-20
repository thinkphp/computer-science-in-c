/*   
 *   Adrian Statescu <mergesortv@gmail.com>
 *
 *   An introduction to the Longest Increasing Subsequence Problems.
 *   
 *   The task is to find the length of the longest subsequence in a given array of integers such that all elements     
 *   of the subsequence are sorted in ascending order.
 *   For example, the length of the LIS for {15,27,14,38,26,55,46,65,85} is 6 and the longest increasing subsequence is
 *                                          {15,27,38,55,65,85}
 *
 *   Here is a great code covering the topic.
 */
#include <stdio.h>
#define FIN "lis.in"
#define FOUT "lis.out"
#define MAXSIZE 1024

int main() {

    freopen(FIN, "r", stdin); 
    freopen(FOUT, "w", stdout); 

    int i, j, n, vec[ MAXSIZE ], 
                 len[ MAXSIZE ],
        max, maxIndex;
    
    scanf("%d", &n);

    for(i = 1; i <= n; ++i) scanf("%d", &vec[i]);
  
    len[ n ] = 1;
    
    for(i = n - 1; i >= 1; --i) {

        max = 0;

        for(j = i + 1; j <= n; j++) 

                if(vec[ j ] >= vec[ i ] && len[ j ] > max) max = len[ j ]; 
        
        len[ i ] = 1 + max; 
    } 

    max = len[ 1 ];

    maxIndex = 1;

    for(i = 2; i <= n; i++) 

        if(len[ i ] > max) max = len[ i ], maxIndex = i;  

    printf("%d\n", len[ maxIndex ]);

    printf("%d ", vec[maxIndex]);

    for(j = maxIndex + 1; j <= n; j++) {

          if(vec[ j ] > vec[maxIndex] && len[ j ] == max - 1) {

             printf("%d ", vec[ j ]);

             max--;
          }
    }

    fclose( stdin );

    fclose( stdout );
    
    return(0);
}