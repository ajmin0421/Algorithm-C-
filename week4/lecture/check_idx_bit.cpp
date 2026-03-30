#include<bits/stdc++.h>
using namespace std;
int main(){
    int S=18;//10010
    int idx = 0;
    cin>>idx;
    if(S&(1<<idx)){ //10010 & 00010 if it is on it will have num or return zero
        cout<<"해당 idx : "<<idx<<"가 켜져있습니다.\n";
    }else cout<<"해당 idx : "<<idx<<"가 꺼져있습니다.\n";
    return 0;
}