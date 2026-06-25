#include<bits/stdc++.h>
using namespace std;

int dy[]={-1,1,0,0}; 
int dx[]={0,0,1,-1};

//상어 크기랑  속도를 주고
//1초마다 상어가 움직이며
//벽에 부딛히면 속도를 유지한체
//방향이 반대로 바뀜
//낚시꾼은 1초마다 오른쪽으로 한칸씩이동
//마지막 열에 도달하면 끝이며
//가장 거리가 가까운 상어를 잡는다.
//상어가 같은칸에 2개 있으면 크기가 큰게 작은걸 먹는다
//이때 잡은 상어의 크기의 합구하기

//1phase마다 진행되는걸 구현

//1.상어 먼저 움직임 구현
//벽에 닿으면 방향 바꿔서 그대로 움직이기
//3같은칸에 있을시 없애기 ->2차원 격자에 idx만 넣고 비교 후 백터에서 idx 삭제
//4.0행부터 가장 가까운 상어 잡기

struct shark{
    int r,c,s,d,z;
    bool is_dead=false;
};

int n,a[104][104],next_a[104][104],r,c,m,ret;
vector<shark> v;
vector<int> idx;//상어 관리

void go(int shark_idx){
    //속도에 따라 이동 수식으로 하는게 빠를듯?
    int y=v[shark_idx].r,x=v[shark_idx].c,s=v[shark_idx].s,d=v[shark_idx].d-1,cycle,real_speed;
    //새로 이동 상어
    if(d==0||d==1) cycle = (r-1)*2;
    else cycle = (c-1)*2;
    real_speed = (cycle==0) ? 0 : s%cycle;
    
    for(int i=0;i<real_speed;i++){
        int ny=y+dy[d]; 
        int nx=x+dx[d];
        if(ny>r||ny<1||nx>c||nx<1){ 
            if(d==0) d=1;
            else if(d==1) d=0;
            else if(d==2) d=3;
            else if(d==3) d=2;
            ny=y+dy[d];
            nx=x+dx[d];
        }
        y = ny; x=nx;
    }
    v[shark_idx].r = y; v[shark_idx].c = x; v[shark_idx].d = d+1;
    //도착칸에 상어 있을시
    if(next_a[y][x]){
        int cmp_idx = next_a[y][x];
        if(v[cmp_idx].z<v[shark_idx].z){
            next_a[y][x]=shark_idx;
            v[cmp_idx].is_dead = true;
        }else v[shark_idx].is_dead = true;
    }else next_a[y][x]=shark_idx;


}

int main(){
    cin>>r>>c>>m;
    vector<shark> temp(m);
    v.resize(m+1);
    for(int i=1;i<=m;i++){ 
        cin>>v[i].r>>v[i].c>>v[i].s>>v[i].d>>v[i].z;
        idx.push_back(i);
        a[v[i].r][v[i].c] = i;
    }

    for(int i=1;i<=c;i++){
        //인간이 잡기
        for(int j=1;j<=r;j++){
            if(a[j][i]){
                ret+=v[a[j][i]].z;
                v[a[j][i]].is_dead = true;
                a[j][i] = 0;
                break;
            }
        }
        //상어 움직임
        memset(next_a,0,sizeof(next_a));
        
        for(auto it:idx){
            if(v[it].is_dead) continue;
            go(it);
        } 

        memcpy(a,next_a,sizeof(next_a));
    }
    cout<<ret<<'\n';
    return 0;
}