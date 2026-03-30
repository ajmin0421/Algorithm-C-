#include<bits/stdc++.h>
using namespace std;
int n,mask,t;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s; 
        if(s=="all") mask = (1<<21)-1; 
        else if(s[0]=='e') mask = 0;
        else{
            cin>>t;
            if(s[0]=='a') mask |= (1<<t); 
            else if(s[0]=='t') mask ^= (1<<t);
            else if(s[0]=='c') if((1<<t)&mask) cout<<1<<'\n'; else cout<<0<<'\n';
            else if(s[0]=='r') mask &= ~(1<<t);
        }
    }
    return 0;
}