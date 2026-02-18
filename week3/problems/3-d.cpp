#include<bits/stdc++.h> 
using namespace std;
const int max_n=54;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,l,r,a[max_n][max_n],visited[max_n][max_n],day;
bool is_moved=false;
vector<pair<int,int>> union_list;
void go(int ty,int tx){
    union_list.clear();
    queue<pair<int,int>> q;
    visited[ty][tx] = 1; q.push({ty,tx});
    union_list.push_back({ty,tx});
    while(q.size()){
        auto [y,x] = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||ny>=n||nx<0||nx>=n) continue;
            if(visited[ny][nx]) continue;
            if(abs(a[y][x]-a[ny][nx])>r||abs(a[y][x]-a[ny][nx])<l) continue;
            union_list.push_back({ny,nx});
            q.push({ny,nx}); 
            visited[ny][nx] = 1;
        }
    }
    if(union_list.size()<2) return;
    else is_moved=true;
    int temp=0;
    for(auto [y,x]:union_list){
        temp += a[y][x];
    }
    temp/=(int)union_list.size();
    for(auto [y,x]:union_list){
        a[y][x] = temp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    while(true){
        is_moved=false;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]) go(i,j);
            }
        }
        if(!is_moved) break;
        day++;
    }
    cout<<day<<'\n';
    return 0;
}