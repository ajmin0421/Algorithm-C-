#include<bits/stdc++.h>
using namespace std;
int n,a,e,pre=-1,ret;
vector<pair<int,int>> v;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>e;
        v.push_back({e,a});
    }
    sort(v.begin(),v.end());
    for(auto it:v){
        if(it.second>=pre){
            pre=it.first;
            ret++;
        }
    }
    cout<<ret<<'\n';
    return 0;
}