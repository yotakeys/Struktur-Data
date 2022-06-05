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
    int n;
    cin>>n;
    int rev=0;
    while(n--){
        string cmd;
        cin>>cmd;
        if(cmd=="TaruhDepan"){
            int x;
            cin>>x;
            if(!rev)d.push_front(x);
            else d.push_back(x);
        }else if(cmd=="KeBelakang"){
            int x;
            cin>>x;
            if(!rev)d.push_back(x);
            else d.push_front(x);
        }else if(cmd=="Urgent"){
            if(d.empty())
                cout<<"Yah gabut..."<<endl;
            else {
                if(!rev){
                    cout<<d.front()<<endl;
                    d.pop_front();
                }else{
                    cout<<d.back()<<endl;
                    d.pop_back();
                }
            }
        }else if(cmd=="GakPenting"){
            if(d.empty())
                cout<<"Yah gabut..."<<endl;
            else {
                if(!rev){
                    cout<<d.back()<<endl;
                    d.pop_back();
                }else{
                    cout<<d.front()<<endl;
                    d.pop_front();
                }
            }
        }else{
            if(rev)rev=0;
            else rev=1;
        }

    }
}