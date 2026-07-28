#include<bits/stdc++.h>
using namespace std;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

//dfs를 이용해서 조합을 뽑고
//vector에 cctv 위치 저장해서 돌리기
//돌리는거 구현이 젤 중요한듯?
//그리고 마지막에 사각지대 갯수 세기
//검사시 복제본만드는것도 중요

int n,m,temp,ret=1e9;
int a[10][10];
vector<int> v;
vector<pair<int,int>> loc;

void draw(int y,int x,int dir){
    while(1){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny<0||ny>=n||nx<0||nx>=m||a[ny][nx]==6) break;
        if(a[ny][nx]==0) a[ny][nx] = '#';
        y = ny; x = nx;
    }
}

void opr(int d,int ct){
    int y,x;
    int num = v[ct];
    tie(y,x) = loc[ct];
    draw(y,x,d);
    if(num==1) return;
    else if(num==2) draw(y,x,(d+2)%4);
    else if(num==3) draw(y,x,(d+1)%4);
    else if(num==4){
        draw(y,x,(d+1)%4);
        draw(y,x,(d+2)%4);
    }else{
        draw(y,x,(d+1)%4);
        draw(y,x,(d+2)%4);
        draw(y,x,(d+3)%4);
    }
}

void go(int ct){
    if(ct==v.size()){
        //sol 사각지대 갯수 체크
        temp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0) temp++;
            }
        }
        ret = min(ret,temp);
        return;
    }
    //방향이 4개
    int dir_cnt=4;
    if(v[ct]==5) dir_cnt=1;
    else if(v[ct]==2) dir_cnt=2;
    
    for(int i=0;i<dir_cnt;i++){
        int b[10][10];
        memcpy(b,a,sizeof(a));
        opr(i,ct);
        go(ct+1);
        memcpy(a,b,sizeof(b));
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]!=0&&a[i][j]!=6){
                v.push_back(a[i][j]);
                loc.push_back({i,j});
            }
        }
    }

    go(0);
    cout<<ret<<'\n';
    return 0;
}