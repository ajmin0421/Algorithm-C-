#include<bits/stdc++.h>
using namespace std;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int a[52][52],visited[52][52];
int t,m,n,k,ty,tx,ret;
void dfs(int y,int x){
    visited[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||ny>=n||nx<0||nx>=m) continue;
        if(a[ny][nx]==0) continue;
        if(visited[ny][nx]) continue;
        dfs(ny,nx);
    }
    return;
}

int main(){
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>m>>n>>k;
        for(int l=0;l<k;l++){
            cin>>tx>>ty;
            a[ty][tx]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]&&!visited[i][j]){ 
                    dfs(i,j);
                    ret++;
                }
            }
        }
        cout<<ret<<'\n';
        memset(visited,0,sizeof(visited));
        memset(a,0,sizeof(a));
        ret=0;
    }
    return 0;
}