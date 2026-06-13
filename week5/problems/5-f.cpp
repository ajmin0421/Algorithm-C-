#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a,b,ret,flag;

int main(){
    //가방에는 어짜피 하나에 하나밖에 안들어가니 그 가방 최대 무게 전까지의 무게를 정렬하여서 pq에 넣으면 될듯?
    cin>>n>>k;
    vector<pair<int,int>> v(n);
    vector<int> vv(k);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i=0;i<k;i++) cin>>vv[i];

    sort(v.begin(),v.end());
    sort(vv.begin(),vv.end());
    
    priority_queue<ll> pq;
    int j=0;
    for(int i=0;i<k;i++){
        while(j<n&&v[j].first<=vv[i]) pq.push(v[j++].second);
        if(pq.size()){
            ret+=pq.top(); pq.pop();
        }
    }
    cout<<ret<<'\n';
}
