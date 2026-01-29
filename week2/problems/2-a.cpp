#include<bits/stdc++.h>
using namespace std;
const int max_n=104;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int a[max_n][max_n],visited[max_n][max_n];
int n,m,y,x;
string temp;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>temp;
        for(int j=0;j<m;j++){
            a[i][j] = temp[j]-'0';
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0]=1;
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx]==0) continue;
            visited[ny][nx] = visited[y][x]+1;
            q.push({ny,nx});
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    cout<<visited[n-1][m-1];
    return 0;
}