#include<bits/stdc++.h>
using namespace std;

int n,a[21][21],ret=1e9;
bool visited[21];

void go(int idx,int count){
    if(count==n/2){
        int star_team=0;
        int link_team=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i]&&visited[j]) star_team += a[i][j];
                if(!visited[i]&&!visited[j]) link_team += a[i][j];
            }
        }
        ret = min(ret,abs(star_team-link_team));
        return;
    }
    for(int i=idx;i<n;i++){
        if(visited[i]) continue;
        visited[i] = true;
        go(i+1,count+1);
        visited[i] = false;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    go(0,0);
    cout<<ret<<'\n';
    return 0;
}

//memo.
//팀 뽑기 -> 그리디로 제일 작을 경우를 구해야되늗데
//느낌상 각각의 합을 구하면서 각각의 차이가 가장 적게해야대
//일단 뽑기는 뽑아야돼 어케 최소화? 전체 경우는 20개로 만들수 있는 모든 팀 2^20이면 1초를 넘어가
//예를 들어서 1번을 뽑고 다른 사람들과의 각각의 합을 전부보고
//에초에 모든 값을 알고 있으니까 각각의 합을 만든 배열을 하나 만들고, 그중 가장 차이가 작은 숫자들을 뽑으면 되는거 아닐까?
//근데 막히는 부분은 예를 들어서 1,3을 뽑으면 1과3으로 만드는값을 이제 못쓰고 그걸 빼고 다시 차이가 작은숫자를 구해야하는점이야
//뽑은 숫자들 더하기 S[i,j] S[j,i]