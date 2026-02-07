#include<bits/stdc++.h>
using namespace std;
const int max_n=104;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int n,m,temp_map[max_n][max_n],a[max_n][max_n],visited[max_n][max_n],total_cheese,ct;
int last_cheese;


void dfs(int y,int x,vector<pair<int,int>> &v){
    visited[y][x] = 1;
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0||ny>=n||nx<0||nx>=m) continue;
        if(visited[ny][nx]) continue;
        if(temp_map[ny][nx]==1){
            visited[ny][nx] = 1;
            v.push_back({ny,nx});
            continue;
        }
        dfs(ny,nx,v);
    }
    return;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]) total_cheese++;
        }
    }


    while(total_cheese>0){
        memcpy(temp_map,a,sizeof(a));
        ct++;
        vector<pair<int,int>> v;
        
        memset(visited,0,sizeof(visited));
        dfs(0,0,v);
        
        last_cheese = v.size();
        total_cheese-=last_cheese;

        for(auto [y,x]:v) a[y][x]=0;
    }
    cout<<ct<<'\n'<<last_cheese;
    return 0;
}