#include<bits/stdc++.h>
using namespace std;

int flag;
string s;
int main(){
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(i <s.size()-1&&"pi"==s.substr(i,2)||"ka"==s.substr(i,2)) i++;
        else if(i<s.size()-2&&"chu"==s.substr(i,3)) i+=2;
        else flag=1;
    }
    if(flag) cout<<"NO"<<'\n';
    else cout<<"YES"<<'\n';
    return 0;
}