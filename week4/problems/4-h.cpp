#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
const int max_n = 54;
int n,m,ret,a[max_n][max_n],visited[max_n][max_n],ct,room_id=1,room[254],MAX;


void go(int y,int x){
    ct++;
    visited[y][x] = room_id;
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(i==3&&a[y][x]&1) continue;
        if(i==0&&a[y][x]&2) continue;
        if(i==1&&a[y][x]&4) continue;
        if(i==2&&a[y][x]&8) continue;
        if(ny<0||ny>=n||nx<0||nx>=m||visited[ny][nx]) continue;
        go(ny,nx);
    }
    return;
}
void check(int y,int x){
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0||ny>=n||nx<0||nx>=m) continue;
        if(i==3&&a[y][x]&1&&visited[y][x]!=visited[ny][nx]) ret = max(ret,room[visited[y][x]]+room[visited[ny][nx]]);
        if(i==0&&a[y][x]&2&&visited[y][x]!=visited[ny][nx]) ret = max(ret,room[visited[y][x]]+room[visited[ny][nx]]);
        if(i==1&&a[y][x]&4&&visited[y][x]!=visited[ny][nx]) ret = max(ret,room[visited[y][x]]+room[visited[ny][nx]]);
        if(i==2&&a[y][x]&8&&visited[y][x]!=visited[ny][nx]) ret = max(ret,room[visited[y][x]]+room[visited[ny][nx]]);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]) continue;
            ct=0; go(i,j);
            room[room_id] = ct;
            room_id++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check(i,j);
            MAX = max(MAX,room[visited[i][j]]);
        }
    }



    cout<<room_id-1<<'\n';
    cout<<MAX<<'\n';
    cout<<ret<<'\n';
    return 0;
}