#include<bits/stdc++.h>
using namespace std;
const int max_n = 10;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int a[max_n][max_n],visited[max_n][max_n],temp_map[max_n][max_n];
int n,m,ct,MAX;
vector<pair<int,int>> v;
void dfs(int y,int x){//spread viruse
    visited[y][x] = 1; 
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||ny>=n||nx<0||nx>=m) continue;
        if(visited[ny][nx]) continue;
        if(temp_map[ny][nx]!=0) continue;
        dfs(ny,nx);
    }
    return;
}

int count(int map[max_n][max_n]){
    int ct=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0&&!visited[i][j]) ct++;
        }
    }
    return ct;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]==0) v.push_back({i,j});
        }
    }
    const int vs=v.size();
    for(int i=0;i<vs;i++){
        for(int j=i+1;j<vs;j++){
            for(int k=j+1;k<vs;k++){               
                memcpy(temp_map,a,sizeof(a));

                temp_map[v[i].first][v[i].second] = 1;
                temp_map[v[j].first][v[j].second] = 1;
                temp_map[v[k].first][v[k].second] = 1;

                for(int q=0;q<n;q++){
                    for(int w=0;w<m;w++){
                        if(temp_map[q][w]==2) dfs(q,w);
                    }
                }
                MAX = max(count(temp_map),MAX);

                memset(visited,0,sizeof(visited));
            }
        }
    }
    cout<<MAX<<'\n';
    return 0;
}