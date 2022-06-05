#include <bits/stdc++.h>
using namespace std;
#define pdd pair<double,double>
#define mp make_pair
#define pb push_back

vector<int> par, level;

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
		if(level[u] < level[v])
			swap(u, v);
		if(level[u] == level[v])
			level[u]++;
		par[v] = u;
	}
}

typedef struct edge_t
{
	int u, v;
	double w;
}
edge;

vector<pdd> vertex;
vector<edge> edges;

void init(int n)
{
	par.assign(n, 0);
	level.assign(n, 1);
	vertex.assign(n, mp(0, 0));
	
	for(int i = 0; i < n; ++i)
		par[i] = i;
}

void reset()
{
	par.clear();
	level.clear();
	vertex.clear();
	edges.clear();
}

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

double getDist(pdd u, pdd v)
{
	double x = (u.first - v.first) * (u.first - v.first),
		   y = (u.second - v.second) * (u.second - v.second);
	return sqrt(x + y);	  
}

int main()
{
	int t, n;
	cin >> t;
	
	while(t--){
		cin >> n;
		init(n);
		
		for(int i = 0; i < n; ++i){
			cin >> vertex[i].first >> vertex[i].second;
		}
		for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; ++j)
			{
				edge temp;
				temp.u = i;
				temp.v = j;
				temp.w = getDist(vertex[i], vertex[j]);
				edges.pb(temp);
			}
		}
		sort(edges.begin(), edges.end(), cmp);
		double cost = 0;
		
		for(int i = 0; i < edges.size(); ++i)
		{
			int U = edges[i].u,
				V = edges[i].v;
			
			if(find_set(U) != find_set(V)){
				cost += edges[i].w;
				union_set(U, V);
			}
		}
		cout << fixed << setprecision(2) << cost << endl;
		reset();
	}
	return 0;
}