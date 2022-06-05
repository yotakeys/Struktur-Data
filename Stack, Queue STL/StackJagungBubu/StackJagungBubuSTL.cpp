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
     int tc;
    cin>>tc;
    while(tc--){
        queue <int> as;
        queue <int> bs;
        int p,a,b;
        cin>>p>>a>>b;
        int sa[a+2]={1000000},sb[b+2]={1000000};
        sa[0]=0;
        sb[0]=0;
        for(int i=1;i<=a;i++){
            int temp;
            cin>>temp;
            if(temp%2==0)as.push(temp);
            temp = temp+sa[i-1];
                sa[i]=temp;
        }
        for(int i=1;i<=b;i++){
            int temp;
            cin>>temp;
            if(temp%2==1)bs.push(temp);
            temp = temp+sb[i-1];
                sb[i]=temp;
        }
        int max = 0;
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                int temp = sa[i]+sb[j];
                if(temp>p)break;
                if(i+j>max){
                    max=i+j;
                }
            }
        }
        cout<<max<<" jahong"<<endl;
        if(max==0){
            cout<<"Keciaaan :<"<<endl;
        }
        else if(max%2==0){
            if(as.empty()){
                cout<<"Gak ada nih!"<<endl;
            }
            else{
                cout<<"NUM =>";
                while(!as.empty()){
                    cout<<as.front()<<" ";
                    as.pop();
                }
                cout<<endl;
            }
        }
        else{
            if(bs.empty()){
                cout<<"Gak ada nih!"<<endl;
            }
            else{
                cout<<"NUM =>";
                while(!bs.empty()){
                    cout<<bs.front()<<" ";
                    bs.pop();
                }
                cout<<endl;
            }
        }
    }

    return 0;
}