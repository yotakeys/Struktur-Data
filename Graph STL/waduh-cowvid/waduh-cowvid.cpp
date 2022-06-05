#include <bits/stdc++.h>

using namespace std;

int total=0;

int BFS(vector<vector<int> > G, int root)
{
    queue<int> Q;
    int x = G.size();
    int visited[x+1] = {0};
    visited[root] = 1;
    Q.push(root);
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        int count=0;
        for(int i=0;i<G[v].size();i++)
        {
            int w = G[v][i];
            if(!visited[w])
            {
                visited[w] = 1;
                Q.push(w);
                count++;
            }
        }
        int now=1;
        cout<<count;
        while(now<count+1){
            total++;
            now*=2;
        }
        total+=count;
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector <vector<int> > g(n + 1, vector<int>());

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    BFS(g,1);
    cout<<total;

}