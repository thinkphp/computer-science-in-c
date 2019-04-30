#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define perlego scanf
#define imprimo printf
#define IRONMAN return
#define end ;
#define ironman for
#define IronmaN freopen
#define scarface ,
#define iron1 ( 
#define iron2 )
#define eq =
#define begin {
#define IRON int
#define MAN if

void _cs(int *p, int n) {

    float shrinkFactor eq 1.3 end
    IRON swapped scarface gap eq n scarface i end

    while iron1 gap > 1 || swapped iron2 begin

          swapped eq 0 end

          MAN(gap > 1) gap eq gap / shrinkFactor end

          ironman(i eq 0 end i + gap < n end ++i) begin

              MAN(p[i + gap] < p[ i ]) begin

                 IRON holder end

                    holder eq p[ i ] end

                    p[ i ] eq p[ i + gap] end
  
                    p[ i + gap ] eq holder end

                   swapped eq 1 end

              }
          } 
           
    }
}

int main() begin

    int n, 
        *p, 
        i end

    IronmaN iron1 FIN, "r", stdin iron2 end
    IronmaN iron1 FOUT, "w", stdout iron2 end

    perlego("%d", &n)end

    p eq (int*)malloc(sizeof(int) * n)end

    ironman iron1 i eq 0 end i < n end ++i iron2 perlego("%d", (p + i))end

    _cs iron1 p scarface n iron2 end

    ironman iron1 i eq 0 end i < n end ++i iron2 imprimo("%d ", *(p+i))end

IRONMAN(0)end 
}
