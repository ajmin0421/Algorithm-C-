#include<bits/stdc++.h>
using namespace std;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int visited[7][7],ret,r,c,k;
char a[7][7];

void go(int idx,int depth){
    if(depth>k) return;
    int y = idx/c;//well-known
    int x = idx%c;
    if(y==0&&x==c-1){
        if(depth==k) ret++;
        return;
    }
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||ny>=r||nx<0||nx>=c||visited[ny][nx]) continue;
        if(a[ny][nx]=='T') continue;
        visited[ny][nx] = visited[y][x]+1;
        go(ny*c+nx,depth+1);
        visited[ny][nx] = 0;
    }
}

int main(){
    cin>>r>>c>>k;
    for(int i=0;i<r;i++){
        string s;
        cin>>s;
        for(int j=0;j<(int)s.length();j++){
            a[i][j] = s[j];
        }
    }
    visited[r-1][0]=1;
    go((r-1)*c,1);
    cout<<ret<<'\n';
    return 0;
}