#include <vector>
#include <fstream>

using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

const int HS =  10000, ok_dupl = 0;
typedef vector<int>::iterator iter;
vector<int> H[HS];

iter NIL = H[0].end();

inline int h(int x)
{
 return (int) (  ( (x * 0.618033) - (int)(x * 0.618033) )  * HS );
}

iter find(int x)
{
 int hh = h(x);
 for(iter it = H[hh].begin(); it != H[hh].end(); ++it)
  if(*it == x) return it;

 return NIL;
}

void insert(int x)
{
        int hh = h(x);
        if( !ok_dupl &&  find(x) != NIL ) return;
        H[hh].push_back(x);
}

void erase(int x)
{
        int hh = h(x);
        for(iter it = H[hh].begin(); it != H[hh].end();)
         if(*it == x)
         {
           H[hh].erase(it);
           if(!ok_dupl) return;
         }
          else ++it;
}

int main()
{
        int N,op,x;
        fin>>N;

        while(N--)
        {
         fin>>op>>x;
         switch(op)
         {
          case 1: insert(x); break;
          case 2: erase(x); break;
          case 3: fout<< (find(x) != NIL ? 1 : 0) <<'\n'; break;
         }
        }

        return 0;
}
