//require -std=c++11
#include <bits/stdc++.h>
using namespace std;
vector < pair<double, int> > ans, finalans; //ans sbg pencarian ans yang optimal; final ans sbg wadah print hasil2 akhir
vector <bool> visited; //untuk permutasi menghindari angka berulang
vector <double> memo; //catatan simpanan untuk permutasi
vector <double> a; //vektor inputan
int t, p;
double mySaham; //saham milik Bdiqz
void permutasi(int kedalaman, int n)
{
	if (kedalaman >= n)
	{
		double total = 0;
		
		for (int i = 0; i < kedalaman; i++)
		{
			total += memo[i];
			//printf("%.2lf\n", memo[i]);
		}
		//printf("%.2lf\n", total);
		double hasil = mySaham/(total+mySaham) * 100;
		
		if (total+mySaham > 50.00)
		{
			//printf("%.2lf %d\n", hasil, n+1);
			ans.push_back(make_pair(hasil, -(n+1))); 
			//ada - di n agar saat diurutkan gampang dari terkecil
			//printf("%.2lf %d\n", ans[1].first, ans[1].second);
		}
	}
	else
	{
		for (int i = 1; i<t; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				memo[kedalaman]=a[i]; //dicatat
				permutasi(kedalaman+1, n); //panggil
				visited[i] = false; //reset
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); //mempercepat cin cout
	while(true)
	{
		cin >> t >> p; //input
		visited.clear(); //inisialisasi
		visited = {false};
		a.clear();
		a = {0};
		if (t == 0 && p == 0) //break saat 0 0
		{
			break;
		}
		
		for (int i = 1; i<=t; i++)
		{
			double x;
			cin >> x;
			if (i == p)
			{
				//letakan pada mySaham tapi tidak ditambahkan ke vektor
				mySaham = x; 
				continue;
			}
			//tambahkan ke vektor untuk saham dan visited
			a.push_back(x);
			visited.push_back(false);
		}

		if (mySaham < 50.00)
		{
			ans.clear(); //bersihkan ans
			for (int i = 1; i <= t-1; i++)
			{
				for (int j = 0; j<=i; j++)
				{
					//puts("gas");
					memo.push_back(0); //inisialisasi memo
				}
				permutasi(0, i); //pemanggilan fungsi permutasi
			}
			sort(ans.rbegin(), ans.rend());
			finalans.push_back(make_pair(ans.front().first, -ans.front().second));
		//	printf("%.2lf %d\n", ans[1].first, ans[1].second);
		}
		else
		{
			finalans.push_back(make_pair(100.00, 1));
			continue;
		}
	}
	for (int i = 0; i < finalans.size(); i++)
	{
		printf("%.2lf %d\n", finalans[i].first, finalans[i].second);
	}
}