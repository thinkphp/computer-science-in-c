#include <bits/stdc++.h>
using namespace std;
const string FILE_NAME = "drum_hamiltonian";
ifstream fin (FILE_NAME + ".in");
ofstream fout (FILE_NAME + ".out");

const int nMAX = 10;

int n;
bool gf[nMAX + 1][nMAX + 1];
bool viz[nMAX + 1];

bool dfs(int nod, vector<int> &stiv)
{
   viz[nod] = 1;
   stiv.push_back(nod);

   if (stiv.size() == n)
      return true;

   for (int nex = 1; nex <= n; ++nex)
      if (gf[nod][nex] && !viz[nex])
         if (dfs(nex, stiv))
            return true;
   
   viz[nod] = 0;
   stiv.pop_back();
   return false;
}


int main()
{
   fin >> n;
   for (int a, b; fin >> a >> b; )
      gf[a][b] = 1;
   
   vector<int> stiv;
   for (int i = 1; i <= n; ++i)
      if (dfs(i, stiv))
      {
         fout << "1\n";
         for (int x : stiv)
            fout << x << ' ';
         exit(0);
      }
   
   fout << '0';
}
