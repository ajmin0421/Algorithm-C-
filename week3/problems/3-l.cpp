#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,r,c,visited[30],ret;

char a[24][24];
string s;

void go(int y,int x,int ct){
    ret = max(ret,ct);
    for(int i=0;i<4;i++){
        int ny = y +dy[i];
        int nx = x +dx[i];
        if(ny<0||ny>=r||nx<0||nx>=c) continue;
        int next = (int)a[ny][nx]-'A';

        if(visited[next]==0){
            visited[next] = 1;
            go(ny,nx,ct+1);
            visited[next] = 0;
        }
    }
}

int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        cin>>s;
        for(int j=0;j<c;j++) a[i][j] = s[j];
    }
    visited[(int)a[0][0]-'A'] = 1;
    go(0,0,1);
    cout<<ret<<'\n';
    return 0;
}