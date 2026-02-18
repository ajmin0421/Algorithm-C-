#include<bits/stdc++.h>
using namespace std;
const int max_n=54;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
char a[max_n][max_n];
int visited[max_n][max_n],n,m,ret;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j] = s[j];
            if(a[i][j]=='L') v.push_back({i,j});
        }
    }
    const int len = v.size();
    for(int i=0;i<len;i++){
        memset(visited,0,sizeof(visited));
        queue<pair<int,int>> q;
        q.push(v[i]);
        visited[v[i].first][v[i].second] = 1;
        while(q.size()){
            auto [y,x] = q.front(); q.pop();
            for(int j=0;j<4;j++){
                int ny = y+dy[j];
                int nx = x+dx[j];
                if(ny<0||ny>=n||nx<0||nx>=m) continue;
                if(visited[ny][nx]) continue;
                if(a[ny][nx]=='W') continue;
                visited[ny][nx] = visited[y][x] +1;
                q.push({ny,nx}); 
                ret = max(ret,visited[ny][nx]);
            }
        }
    }
    cout<<ret-1<<'\n';
    return 0;
}
