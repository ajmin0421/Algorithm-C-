#include<bits/stdc++.h>
using namespace std;
const int max_n=14;
vector<int> v[11];
int n,population[max_n],temp,ret=1e9,visited[max_n],total_population;

void go(int mask,int from,int team){
    visited[from] = 1;
    for(int next:v[from]){
        int next_team = mask>>next&1; 
        if(next_team==team&&!visited[next]) go(mask,next,team);
    }
}

bool isConnected(void){
    for(int i=0;i<n;i++) if(!visited[i]) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>population[i];
        total_population += population[i];
    }
    for(int i=0;i<n;i++){
        cin>>temp;
        for(int j=0;j<temp;j++){
            int t; cin>>t;
            v[i].push_back(t-1);
        }
    }
    for(int i=1;i<(1<<n)-1;i++){
        int sum=0;
        //적어도 하나의 구역 -> for문 조건으로 해결! o
        //모든 선거구 연결 조건 확인 ->dfs로 구현?
        memset(visited,0,sizeof(visited));
        go(i,__builtin_ctz(i&-i),1);
        go(i,__builtin_ctz(~i&((1<<n)-1)),0);
        if(!isConnected()) continue;//연결성 확인
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum+=population[j]; // 맞다면 인구의 수
            }
        } 
        ret = min(ret,abs(total_population-sum*2));//최솟값 갱신
    }
    if(ret==1e9) cout<<-1<<'\n';
    else cout<<ret<<'\n';
    return 0;
}