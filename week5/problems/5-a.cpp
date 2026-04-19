#include<bits/stdc++.h>
using namespace std;
int n,ret,d,p,day;
vector<pair<int,int>> v;
priority_queue<int> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p>>d;
        v.push_back({d,p*-1});
    }
    sort(v.begin(),v.end());
    for(auto it:v){
        if(pq.size()>=it.first){
            pq.push(it.second);
            pq.pop();
        }else pq.push(it.second);
    }
    while(pq.size()) ret+=(pq.top()*-1), pq.pop();
    cout<<ret<<'\n';
    return 0;
}