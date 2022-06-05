#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
 
typedef struct data_t
{
	string nama;
	int datang, lama;
}
Data;
 
int countWaktu(deque <Data> dq, int t)
{
	int total = 0;
 
	if(!dq.empty()){	
		for(int i = 0; i < dq.size(); ++i)
			total += dq[i].lama;
		total -= t;
	}
	return total;
}
 
void printData(deque <Data> &dq, int t)
{
	bool melayani = 0,
		 selesai = 0;
	Data temp = dq.front();
 
	if(temp.datang <= t and t < temp.datang + temp.lama)
	{
		cout << "Tidak ada yang selesai dilayani\n";
		cout << temp.nama << " sedang dilayani\n";
		melayani = 1;
	}
	while(!dq.empty())
	{
		temp = dq.front();
		if(t < temp.datang + temp.lama) break;
 
		cout << temp.nama << " selesai dilayani\n";
		t -= (temp.datang + temp.lama);
		dq.pop_front();
 
		selesai = 1;
	}
	if(selesai and dq.size()){
		cout << temp.nama << " sedang dilayani\n";
		melayani = 1;
	}
	if(!melayani)
		cout << "Tidak ada yang sedang dilayani\n";
}
 
int main()
{
	deque <Data> udin, petot;
	Data input;
	string cmd;
	bool isUdin = 1;
 
	while(cin >> input.datang >> cmd)
	{
		if(cmd == "ANTRI"){
			cin >> input.nama >> input.lama;
 
			if(isUdin){
				if(countWaktu(udin, input.datang) >= 60)
				{
					cout << input.nama << " tidak jadi mengantri\n";
					continue;
				}
				udin.push_back(input);
			}
			else {
				if(countWaktu(petot, input.datang) >= 60)
				{
					cout << input.nama << " tidak jadi mengantri\n";
					continue;
				}
				petot.push_back(input);
			}
			isUdin ^= 1;
		}
		else if(cmd == "CHECK")
		{
			cout << "UDIN\n";
			printData(udin, input.datang);
			cout << "PETOT\n";
			printData(petot, input.datang);
		}
		else {
			cout << "UDIN\n";
 
			if(udin.empty())
				cout << "Kosong\n";
			while(!udin.empty()){
				cout << udin.front().nama << endl;
				udin.pop_front();
			}
			cout << "PETOT\n";
 
			if(petot.empty())
				cout << "Kosong\n";
			while(!petot.empty()){
				cout << petot.front().nama << endl;
				petot.pop_front();
			}
			break;
		}
	}
	return 0;
}