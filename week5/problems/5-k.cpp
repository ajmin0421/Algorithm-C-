#include<bits/stdc++.h>
using namespace std;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<pair<int,int>> v,air;
int r,c,t,m[51][51],ret,add_m[51][51] = {0,};

void go(int y,int x){
    int val = m[y][x]/5;
    if(val==0) return;
    int ct=0;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny>=0&&ny<r&&nx>=0&&nx<c&&m[ny][nx]!=-1){
            add_m[ny][nx]+=val; ct++;
        }
    }
    m[y][x] -= val*ct;
}

int check(int R,int C){
    int temp=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(m[i][j]!=-1&&m[i][j]!=0){ 
                v.push_back({i,j});
                temp+=m[i][j];
            }
        }
    }
    return temp;
}

void airfilter(void){
    //가습기 위에꺼
    int up_y = air[0].first;
    for(int i=up_y-1;i>0;i--) m[i][0] = m[i-1][0]; //up
    for(int i=0;i<c-1;i++) m[0][i] = m[0][i+1]; //right
    for(int i=0;i<up_y;i++) m[i][c-1] = m[i+1][c-1]; //down
    for(int i=c-1;i>1;i--) m[up_y][i] = m[up_y][i-1]; //left
    m[up_y][1] = 0;
    
    int dw_y = air[1].first;
    for(int i=dw_y+1;i<r-1;i++) m[i][0] = m[i+1][0]; 
    for(int i=0;i<c-1;i++) m[r-1][i] = m[r-1][i+1]; 
    for(int i=r-1;i>dw_y;i--) m[i][c-1] = m[i-1][c-1]; 
    for(int i=c-1;i>1;i--) m[dw_y][i] = m[dw_y][i-1]; 
    m[dw_y][1] = 0;
    
}

int main(){
    cin>>r>>c>>t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
            if(m[i][j]==-1) air.push_back({i,j});
        }
    }
    for(int k=0;k<t;k++){
        //1.확산
        v.clear();
        check(r,c);//v에 미세먼지위치 벡터저장
        for(int i=0;i<v.size();i++){
            go(v[i].first,v[i].second);
        }
        for(int i=0;i<r;i++){for(int j=0;j<c;j++) m[i][j] += add_m[i][j];}// 합
        memset(add_m,0,sizeof(add_m));
         //2.공기청정기 가동
        airfilter();
        //3.반복
    }
    //4.총합 계산
    ret  = check(r,c);
    cout<<ret<<'\n';
    return 0;
}