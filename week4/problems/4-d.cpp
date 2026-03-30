#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int r,c,ret=-1;
char a[24][24];
string s;

void go(int y,int x,int mask,int ct){
    mask |= (1<<(a[y][x]-'A'));
    ret = max(ret,ct);
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0||ny>=r||nx<0||nx>=c||mask&(1<<(a[ny][nx]-'A'))) continue;
        go(ny,nx,mask,ct+1);
    }
    return;
}

int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        cin>>s;
        for(int j=0;j<c;j++){
            a[i][j] = s[j];
        }
    }
    go(0,0,0,1);
    cout<<ret<<'\n';
    return 0;
}