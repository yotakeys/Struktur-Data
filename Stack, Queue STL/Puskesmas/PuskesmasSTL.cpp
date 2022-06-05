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

string penyakits[4]={"flu","maag","diare","pusingkebanyakantugas"};
int bnykttl[4]={0};
int caripenyakit(string x){
    for(int i=0;i<4;i++){
        if(x == penyakits[i])return i;
    }
}

typedef struct bla{
    string first;
    int second;
}pr;

struct myComp
{
	bool operator()(pr a, pr b)
	{
		if(a.second == b.second)
			return a.first > b.first;
		else
			return a.second < b.second;
	}
};


int main(){
    queue <pr> s;
    priority_queue <pr, vector<pr>, myComp>  p;
    int ruang;
    cin>>ruang;
    int cmd;
    pr psn;
    while(cin>>cmd){
        if(cmd==1){
            string nama,pn;
            cin>>nama>>pn;
            int penyakit = caripenyakit(pn);
            bnykttl[penyakit]++;
            cout<<"Pasien atas nama "<<nama<<" terdaftar ke database"<<endl;
            psn.first=nama;
            psn.second = penyakit;
            if(s.size()<ruang){
                cout<<"Pasien atas nama "<<nama<<" langsung masuk"<<endl;
                s.push(psn);
            }else{
                cout<<"Pasien atas nama "<<nama<<" mengantri"<<endl;      
                p.push(psn);
            }
        }else if(cmd==2){
            cout<<"Pasien atas nama "<<s.front().first<<" sudah selesai konsultasi mengenai "<<penyakits[s.front().second]<<endl;
            s.pop();
            if(!p.empty()){
                cout<<"Pasien atas nama "<<p.top().first<<" masuk dari antrian"<<endl;
                psn.first = p.top().first;
                psn.second = p.top().second;
                s.push(psn);
                p.pop();
            }
        }
    }
    for(int i=0;i<4;i++){
        if(bnykttl[i]!=0){
            cout<<penyakits[i]<<":"<<bnykttl[i]<<endl;
        }
    }
}