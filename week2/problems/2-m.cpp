#include<bits/stdc++.h>
using namespace std;

string s;
int n,i,ct;

int main(){
    cin>>n;
    while(ct!=n){
        i++;
        if(to_string(i).find("666")!=string::npos) ct++;
    }
    cout<<i<<'\n';
    return 0;
}