#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 30)

int main()
{
	int n, k;
	cin >> n;
	vector<int> koin(n);
	
	for(int i = 0; i < n; ++i){
		cin >> koin[i];
	}
	sort(koin.begin(), koin.end());
	cin >> k;
	
	vector<int> dp(k + 1, -1);
	dp[0] = 0;
	
	for(int sum = 1; sum <= k; ++sum){
		int best = INF;
		
		for(int i = 0; i < n; ++i)
		{
			if(koin[i] > sum)
				break;
			if(dp[sum - koin[i]] != -1)
				best = min(dp[sum - koin[i]], best);
		}
		if(best != INF)
			dp[sum] = best + 1;
	}
	cout << dp[k] << endl;
	return 0;
}