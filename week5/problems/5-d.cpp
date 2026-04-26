#include<bits/stdc++.h>
using namespace std;
int n,a,t,to;
vector<pair<int,int>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>t;
        v.push_back({a,t});
    }
    sort(v.begin(),v.end());
    to = v[0].first+v[0].second;
    for(int i=1;i<v.size();i++){
        if(v[i].first>to){
            to = v[i].first+v[i].second;
        }else to = to + v[i].second;
    }
    cout<<to<<'\n';
    return 0;
}