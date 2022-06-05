#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<int> par;
vector<int> sz;

void make_set()
{
	for(int i = 0; i < par.size(); ++i)
		par[i] = i;
}

int find_set(int u)
{
	if(par[u] == u)
		return u;
	return par[u] = find_set(par[u]);
}

void union_set(int u, int v)
{
	u = find_set(u);
	v = find_set(v);
	
	if(u != v){
		if(sz[u] < sz[v])
			swap(u, v);
		par[v] = u;
		sz[u] += sz[v];
	}
}

int main()
{
	IOS
	int n, m, k;
	cin >> n >> m;
	
	par.assign(n, 0);
	sz.assign(n, 1);
	make_set();
	
	while(m--)
	{
		int source, input;
		cin >> k;
		if(!k) continue;
		
		cin >> source;
		while(--k){
			cin >> input;
			union_set(source, input);
		}
	}
	for(int i = 0; i < n; ++i)
	{
		if(i) cout << " ";
		cout << sz[find_set(i)];
	}
	cout << endl;
	return 0;
}