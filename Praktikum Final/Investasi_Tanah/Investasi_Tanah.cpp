#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define INF (1 << 30)

int kadane(vector<int> v)
{
	int sum = 0, maxSum = -INF,
		maxNum = -INF;
	bool positive = 0;
	
	for(int i = 0; i < v.size(); ++i){
		sum += v[i];
		
		if(sum < 0)
			sum = 0;
		else if(sum > maxSum){
			maxSum = sum;
			positive = 1;
		}
		maxNum = max(v[i], maxNum);
	}
	if(positive)
		return maxSum;
	else
		return maxNum;
}

int findMaxSum(vector<vi> grid, int n)
{
	int maxSum = -INF;
	vector<int> col(n);
	
	for(int i = 0; i < n; ++i){
		fill(col.begin(), col.end(), 0);
		
		for(int j = i; j < n; ++j)
		{
			for(int k = 0; k < n; ++k){
				col[k] += grid[k][j];
			}
			maxSum = max(kadane(col), maxSum);
		}
	}
	return maxSum;
}

int main()
{
	int n;
	cin >> n;
	vector<vi> grid(n, vi(n));
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cin >> grid[i][j];
	}
	cout << findMaxSum(grid, n) << endl;
	return 0;
}