#include<bits/stdc++.h>
using namespace std;
const int max_n=304;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,y2,x2,y3,x3,visited[max_n][max_n],y,x;
char a[max_n][max_n];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    cin>>y2>>x2>>y3>>x3; y2--; x2--; y3--; x3--;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++) a[i][j] = s[j];
    }

    queue<pair<int,int>> q;
    queue<pair<int,int>> nq;
    memset(visited,-1,sizeof(visited));
    q.push({y2,x2}); 
    visited[y2][x2] = 0; 
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0||ny>=n||nx<0||nx>=m||visited[ny][nx]!=-1) continue;
            if(a[ny][nx]=='#'){
                cout<<visited[y][x]+1<<'\n';
                return 0;
            }
            if(a[ny][nx]=='1'){
                nq.push({ny,nx});
                visited[ny][nx] = visited[y][x]+1;
            }
            if(a[ny][nx]=='0'){ 
                q.push({ny,nx});
                visited[ny][nx] = visited[y][x];
            }
        }
        if(q.size()==0&&nq.size()!=0){
            while(nq.size()){
                q.push(nq.front()); nq.pop();
            }
        }
    }

    return 0;
}