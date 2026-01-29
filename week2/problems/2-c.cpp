#include<bits/stdc++.h>
using namespace std;
const int max_n=104;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int n,temp,ret=1,rain,highest,a[max_n][max_n],visited[max_n][max_n];

void dfs(int y,int x){
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||ny>=n||nx<0||nx>=n) continue;
        if(a[ny][nx]<=rain) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] =1;
        dfs(ny,nx);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            highest=max(highest,a[i][j]);
        }
    }
    for(int k=1;k<highest;k++){
        temp=0;
        rain = k;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&a[i][j]>rain){
                    dfs(i,j);
                    temp++;
                }
            }
        }
        ret = max(ret,temp);
        memset(visited,0,sizeof(visited));
    }
    cout<<ret;
    return 0;
}