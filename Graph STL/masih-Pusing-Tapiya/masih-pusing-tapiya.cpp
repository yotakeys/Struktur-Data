#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue <int>sophie;
    stack <int> howl;
    unsigned long long n;
    cin>>n;
    unsigned long long temp;
    while(n--){
        cin>>temp;
        sophie.push(temp);
    }
    unsigned long long cmd,capacity;
    cin>>cmd>>capacity;
    while(cmd--){
        string cms;
        cin>>cms;
        if(cms=="beri"){
            howl.push(sophie.front());
            sophie.pop();
        }
        else{
            howl.pop();
        }
    }
     unsigned long long tut=0;
     int bnyk=0;
    while(!howl.empty()){
        tut+= howl.top();
        howl.pop();
        bnyk++;
    }
    if(capacity!=tut){
        cout<<"-1"<<endl;
    }
    else{
        cout<<capacity<<" "<<bnyk<<endl;
    }
    
}