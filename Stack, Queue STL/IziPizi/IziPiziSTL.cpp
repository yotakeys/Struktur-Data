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
    priority_queue <int> s;
    int n;
    cin>>n;
    if(!n){
        cout<<"Oiya lupa gapunya kambing, hehe";
        return 0;
    }
    while(n--){
        int x;
        cin>>x;
        s.push(x);
    }
    int max=0;
    while(!s.empty()){
        if(s.top()>=max)
            max=s.top();
        s.pop();
    }
    cout<<max;
    return 0;
}