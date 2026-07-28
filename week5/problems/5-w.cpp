#include<bits/stdc++.h>
using namespace std;

int n,MAX=-1e9,cur=0;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    for(int i=0;i<n;i++){
        if(cur<0) cur = v[i];
        else cur+=v[i];
        MAX = max(MAX,cur);
    }
    
    cout<<MAX<<'\n';
    return 0;
}