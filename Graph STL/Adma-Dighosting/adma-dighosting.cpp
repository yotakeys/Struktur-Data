#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int banyakGraf, jarakMax = 0;
vector<int> adjList[11];

void dfs(int curVertex, int jarak) {
	if(jarak > jarakMax) jarakMax = jarak;
    for (int i = 0 ; i < adjList[curVertex].size() ; i++) {
        int nextVertex = adjList[curVertex][i];
        dfs(nextVertex, jarak+1);
    }
}

int main(){
	
	int a_node, b_node;
	cin >> banyakGraf;
	int FirstNode[banyakGraf + 1]; 
	memset(FirstNode, 0, sizeof(FirstNode));

	for(int i = 0; i < banyakGraf - 1; i++){
		cin >> a_node >> b_node;
		adjList[a_node].push_back(b_node);
		if(!FirstNode[b_node]) FirstNode[b_node] = 1;
	}
	
	for(int i = 1; i < banyakGraf; i++) 
		if(!FirstNode[i]) dfs(i, 0);
		
	cout << jarakMax;
	
	return 0;
}