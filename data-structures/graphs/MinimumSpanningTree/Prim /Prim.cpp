
#include <vector>
#include <cstdlib>
#include <fstream>
#define Nmax 200111
#define oo 9999999

/*
 *
 */
using namespace std;
typedef pair< int, int > pr;
int N;
int d[Nmax], H[Nmax], P[Nmax], apm[Nmax];
vector< pr > G[ Nmax ];
vector< pr >::const_iterator it, iend;
inline void DownHeap( int k )
{
    for( int son=2*k; son <= N; k=son, son*=2 )
    {
        if( son < N && d[H[son+1]] < d[H[son]] )
            ++son;
        if( d[H[k]] <= d[H[son]] )
            return;
        swap( H[k], H[son] );
        P[H[k]]=k;
        P[H[son]]=son;
    }
}
inline void UpHeap( int k )
{
    for( int key=d[H[k]], f=k/2; k > 1 && key < d[H[f]]; k=f, f/=2 )
    {
        swap( H[k], H[f] );
        P[H[k]]=k;
        P[H[f]]=f;
    }
}
inline int pop( void )
{
    int r=H[1];
    P[H[N]]=1;
    P[H[1]]=-1;
    H[1]=H[N--];
    DownHeap( 1 );
    return r;
}
inline void push( int k )
{
    H[++N]=k;
    P[k]=N;
    UpHeap( N );
}
int main( void )
{
    int n, m, x, y, c, s=0;
    ifstream in( "apm.in" );
    for( in>>n>>m; m; --m )
    {
        in>>x>>y>>c;
        G[x].push_back( pr( y, c ) );
        G[y].push_back( pr( x, c ) );
    }
    push( 1 );
    while( N )
    {
        x=pop();
        s+=d[x];
        for( it=G[x].begin(), iend=G[x].end(); it < iend; ++it )
        {
            y=it->first, c=it->second;
            if( 0 == P[y] )
            {
                d[y]=c;
                apm[y]=x;
                push( y );
            }
            else if( P[y] > 0 && d[y] > c )
                 {
                     d[y]=c;
                     apm[y]=x;
                     UpHeap( P[y] );
                 }
        }
    }
    ofstream out( "apm.out" );
    out<<s<<'\n'<<(n-1)<<'\n';
    for( x=2; x <= n; ++x )
        out<<x<<' '<<apm[x]<<'\n';
    return EXIT_SUCCESS;
}
