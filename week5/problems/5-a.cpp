#include<bits/stdc++.h>
using namespace std;
int n,ret,d,p,day;
vector<pair<int,int>> v;
priority_queue<int, vector<int>,greater<int>> pq;//오름차순 uppercase
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p>>d;
        v.push_back({d,p});
    }
    sort(v.begin(),v.end());
    for(auto it:v){
        pq.push(it.second);
        if(pq.size()>it.first){
            pq.pop();
        }
    }
    while(pq.size()) ret+=(pq.top()), pq.pop();
    cout<<ret<<'\n';
    return 0;
}