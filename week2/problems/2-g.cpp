#include<bits/stdc++.h>
using namespace std;

map<int,int> freq;
map<int,int> order;
vector<pair<int,int>> v;
int n,c,temp;

bool cmp(const pair<int,int>& a,const pair<int,int>& b){
    if(b.second!=a.second){
        return a.second>b.second;
    }
    return order[a.first]<order[b.first];
}

int main(){
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(freq[temp]==0) order[temp]=i;
        freq[temp]++;
    }
    for(auto const& [number,count]:freq){
        v.push_back({number,count});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto [number,count]:v){
        for(int i=0;i<count;i++){
            cout<<number<<" ";
        }
    }
    return 0;
}