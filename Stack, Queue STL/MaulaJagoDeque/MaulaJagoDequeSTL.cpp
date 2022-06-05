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

int main(){
    deque <int> d;
    int maxi=0;
    int n,k;
    int saved=1;
    int stored[100000][2];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        maxi=max(maxi,temp);
        d.push_back(temp);
    }
    stored[saved][0]=d.front();
    d.pop_front();
    stored[saved][1]=d.front();
    d.push_front(stored[saved][0]);
    int solved=0;
    while(k--){
        int it;
        cin>>it;
        if(!solved){
        if(it>saved){
        int tem=saved;
        for(int i=0;i<it-tem;i++){
            int st,da;
            st=d.front();
            d.pop_front();
            da=d.front();
            d.pop_front();
            d.push_back(min(st,da));
            d.push_front(max(st,da));
            saved++;
            stored[saved][0]=d.front();
            d.pop_front();
            stored[saved][1]=d.front();
            d.push_front(stored[saved][0]);
            if(st==maxi){
                solved=1;
                break;
            }
        }
        if(solved){
            if(!d.empty()){
            d.pop_front();
            saved--;
            int temp=saved;
            for(int i=0;i<n-1;i++){
                temp++;
                stored[temp][0]=maxi;
                stored[temp][1]=d.front();
                d.pop_front();
            }
        }}
        }
        }
        if(it>saved){
            it = (it-saved)%(n-1)+saved;
        }
        cout<<stored[it][0]<<" "<<stored[it][1]<<endl;
    }
    return 0;
}