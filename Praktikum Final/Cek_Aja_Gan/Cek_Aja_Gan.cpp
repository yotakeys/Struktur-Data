#include <bits/stdc++.h>
using namespace std;

set<long long int> cek;
bool G;

int main()
{
	long long int n, x;
	cin >> n;
	while(n--){
		cin >> x;
		if(cek.count(x))
			G = 1;
		cek.insert(x);
	}
	if(G)cout<<"G";
    else cout<<"Y";
	return 0;
}