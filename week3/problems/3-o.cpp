#include<bits/stdc++.h>
using namespace std;
const int max_n=34;
int n,m,h,visited[max_n][max_n],ret;

vector<pair<int,int>> v;

int check(){
    for(int x=1;x<=n;x++){
        int y=1;
        int _x = x;
        while(true){
            if(y==h+1){
                if(x!=_x) return 0;
                break;
            }
            if(visited[y][_x]){
                _x=visited[y][_x]; y++; 
            }
            else y++;
        }
    }
    ret = 1;
    return 1;
}

void go(int idx,int depth,int limit){
    if(depth==limit){
        if(check()){
            cout<<depth<<'\n';
            exit(0);
        }
        return;
    }
    //permutation
    for(int i=idx;i<(int)v.size();i++){
        auto [y,x] = v[i]; 
        if(visited[y][x]||visited[y][x+1]) continue;
        visited[y][x] = x+1;
        visited[y][x+1] = x;
        go(i+1,depth+1,limit);
        visited[y][x] = 0;
        visited[y][x+1] = 0;
    }
}

int main(){
    memset(visited,0,sizeof(visited));
    cin>>n>>m>>h;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        visited[a][b] = b+1;
        visited[a][b+1] = b;
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<n;j++){
            if(visited[i][j]||visited[i][j+1]) continue;
            v.push_back({i,j}); //valid ledder
        }
    }

    for(int limit=0;limit<=3;limit++){
        go(0,0,limit);
    }
    if(!ret) cout<<-1<<'\n';
    return 0;
}