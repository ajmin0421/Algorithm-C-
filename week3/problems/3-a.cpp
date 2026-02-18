#include<bits/stdc++.h>
using namespace std;
const int max_n=54;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,a[max_n][max_n],c_visited[max_n],ret=1e9;
vector<pair<int,int>> chicken,house;
vector<int> v;
int sol(void){//distance cal
    vector<int> dis;
    int distance=0;
    for(int i=0;i<(int)v.size();i++){
        auto [y,x] = chicken[v[i]];
        for(int j=0;j<(int)house.size();j++){
            int temp = abs(y-house[j].first)+abs(x-house[j].second);
            if(i==0) dis.push_back(temp);
            else dis[j] = min(dis[j],temp);
        }
    }
    for(auto it:dis){
        distance+=it;
    }
    return distance;
}
void go(int idx,int count){
    if(count==m){
        ret = min(ret,sol());
        return;
    }
    for(int i=idx;i<(int)chicken.size();i++){//치킨집 combi
        if(c_visited[i]) continue;
        v.push_back(i);
        c_visited[i] = 1;
        go(i+1,count+1);
        v.pop_back();
        c_visited[i] = 0;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]==1) house.push_back({i,j});
            if(a[i][j]==2) chicken.push_back({i,j});
        }
    }
    go(0,0);
    cout<<ret<<'\n';
    return 0;
}