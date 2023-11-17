#include <fstream>
#include <ext/hash_set>

using namespace std;
using namespace __gnu_cxx;

ifstream fin ("hashuri.in");
ofstream fout ("hashuri.out");

int T;
hash_set <int> H;

int main()
{
	for(fin >> T; T; --T)
	{
		int op, nr;
		fin >> op >> nr;

		if(op == 1) H.insert(nr);
		if(op == 2) H.erase(nr);
		if(op == 3) fout << (H.find(nr) != H.end()) << "\n";
	}
}
