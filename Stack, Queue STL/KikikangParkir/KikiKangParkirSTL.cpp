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

typedef pair<int,int> dt;

int main(){
    while(1){
        bool flag = true;
        stack <dt> s;
        int n,space;
        cin>>n>>space;
        if(!n && !space) break;
        int masuk;
        int keluar;
        while(n--){
            cin>>masuk>>keluar;
            while(!s.empty()){
                if(s.top().second <= masuk){
                    s.pop();
                }else break;
            }
            if(!s.empty()){
                if(s.top().second<keluar){
                    flag = false;
                }
            }
            s.push(make_pair(masuk,keluar));
            if(s.size()>space) flag= false;
        }
        if(flag)cout<<"Bisa boss"<<endl;
        else cout<<"Gimana nih boss"<<endl;
    }
}