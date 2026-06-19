#include<bits/stdc++.h>
using namespace std;
//격자판 구현
//뱀 이동 구현
//0. 뱀 몸을 queue나 백터에 저장
//1. 이동은 하나만 만들어서 격자판 돌리면서 하는게 편할듯
//2. 사과의 유무에따라 꼬리 없애기
//3. 꼬리나 벽에 부딛히면 끝내기
//4. 뱀이 몸이 따라오는거 구현
//5. 꺽기는 구간이 어떻게 구현할지
//6. 오고 가는 방향말고 뱀의 몸이 꺽이는 부분에 있다면 그쪽을 따라가게?
//7. 한칸 움직일때마다 구현해야함...
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
queue<pair<int,int>> q;
vector<pair<int,char>> turns;
int n,L,K,X,m[101][101],a,b,x,y,ret,flag,s_size=1,t,dir=1;
char C;


int main(){
    cin>>n>>K;
    for(int i=0;i<K;i++){
        cin>>a>>b;
        m[b-1][a-1] = 1;
    }
    cin>>L;
    for(int i=0;i<L;i++){
        cin>>X>>C;
        turns.push_back({X,C});
    }
    
    int turn_idx=0,ny=0,nx=0;
    q.push({0,0}); m[0][0] = 2;
    while(true){
        t++;

        ny += dy[dir];
        nx += dx[dir];

        if(ny<0||ny>=n||nx<0||nx>=n||m[ny][nx]==2) break;    
        
        if(m[ny][nx]!=1){
            m[q.front().first][q.front().second]=0;
            q.pop();
        }

        m[ny][nx] = 2;
        q.push({ny,nx});

        //현재시간에 회전하는지
        if(turn_idx<turns.size()&&t==turns[turn_idx].first){
            if(turns[turn_idx].second=='D') dir = (dir + 1)%4;
            else dir = (dir + 3)%4;
            turn_idx++;
        }

    }
    cout<<t<<'\n';
}