#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
typedef unsigned int uint;

int n, m;
vector<vector<int> > a, ta;
vector<vector<int> > comp;
vector<char> result, viz;
vector<int> w;
stack<int> s;

int node(int x)
{
	if (x < 0)
		return n - x;
	return x;
}

void DF1(int v)
{
	viz[v] = 1;
	for(vector<int>::iterator it = a[v].begin(); it != a[v].end(); ++ it)
		if(!viz[*it])
			DF1(*it);
	s.push(v);
}

void DF2(int v, int c)
{
	viz[v] = 1;
	w[v] = c;
	comp[c].push_back(v);

	for(vector<int>::iterator it = ta[v].begin(); it != ta[v].end(); ++ it)
		if(!viz[*it])
			DF2(*it, c);
}

void tareConex()
{
	int sz = 2 * n;
	for(int i=1;i<=sz;++i)
		if(!viz[i])
			DF1(i);

	memset(&viz[0], 0, viz.size());

	for(;!s.empty();s.pop())
		if(!viz[s.top()])
		{
			comp.push_back(vector<int>());
			DF2(s.top(), comp.size() - 1);
		}

}

inline int val(int i)
{
	if (i > n)
		return i - n;
	return i;
}

inline bool hasValue(int c)
{
	for(vector<int>::iterator it = comp[c].begin(); it != comp[c].end(); ++ it)
		if (result[val(*it)] == -1)
			return false;
	return true;
}

inline void set(int x, char v)
{
	if(x <= n)
		result[x] = v;
	else
		result[x-n] = !v;
}

inline void setValue(int c, char v)
{
	for(vector<int>::iterator it = comp[c].begin(); it != comp[c].end(); ++ it)
		set(*it, v);
}

void solve()
{	
	for (int i=0;i<comp.size();++i)
		if(!hasValue(i))
			setValue(i, false);
}

bool hasSolution()
{
	for(int i=1;i<=n;++i)
		if (w[i] == w[i+n])
			return false;
	return true;
}

int main()
{
	ifstream cin("2sat.in");
	ofstream cout("2sat.out");

	int x, y;
	cin >> n >> m;
	a.resize(2 * n + 1); ta.resize(2 * n + 1);
	result.resize(n + 1, -1); viz.resize(2 * n +  1);
	w.resize(2 * n + 1);
	while (m --)
	{
		cin >> x >> y;
		a[node(-x)].push_back(node(y));
		a[node(-y)].push_back(node(x));
		ta[node(x)].push_back(node(-y));
		ta[node(y)].push_back(node(-x));
	}

	tareConex();

	
	if(!hasSolution())
		cout << -1;
	else
	{
		solve();

		for(int i=1;i<=n;++i)
			cout << (result[i] ? '1' : '0') << " ";
	}

	return 0;
}
