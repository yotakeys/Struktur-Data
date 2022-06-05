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

typedef pair<int,int> pr;

int main(){
    priority_queue <pr,vector<pr>, greater<pr> > urut;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        urut.push(make_pair(y,x));
    }
    int find;
    cin>>find;
    int count=0;
    while(!urut.empty()){
        if(urut.top().second==find)
            break;
        urut.pop();
        count++;
    }
    if(count==n)cout<<"Barangnya gak ada beb";
    else cout<<count;
}