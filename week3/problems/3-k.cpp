#include<bits/stdc++.h>
using namespace std;

const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
const int max_n=1504;

char a[max_n][max_n];
int n,r,c,y,x,visited[max_n][max_n],wvisited[max_n][max_n],ret;
queue<pair<int,int>> swan_q,nswan_q,w,nw;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>r>>c;
    string s;
    for(int i=0;i<r;i++){
        cin>>s;
        for(int j=0;j<c;j++){
            a[i][j] = s[j];
            if(a[i][j]!='X'){
                w.push({i,j});
                wvisited[i][j] = 1;
            }
            if(a[i][j]=='L') v.push_back({i,j});
        }
    }
    tie(y,x) = v[0];
    visited[y][x] = 1;
    swan_q.push({y,x});
    while(true){
        while(swan_q.size()){
            tie(y,x) = swan_q.front(); swan_q.pop();
            for(int i=0;i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0||ny>=r||nx<0||nx>=c||visited[ny][nx]) continue;
                visited[ny][nx]=1;
                if(a[ny][nx]=='L'){
                    cout<<ret<<'\n';
                    return 0;
                }
                else if(a[ny][nx]=='X') nswan_q.push({ny,nx});
                else swan_q.push({ny,nx});
            }
        }
        
        while(w.size()){
            tie(y,x) = w.front(); w.pop();
            for(int i=0;i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0||ny>=r||nx<0||nx>=c||wvisited[ny][nx]) continue;
                wvisited[ny][nx]=1;
                if(a[ny][nx]=='X'){
                    nw.push({ny,nx});
                    a[ny][nx] = '.';
                }
                else w.push({ny,nx});
            }
        }

        swap(swan_q,nswan_q);
        swap(w,nw);

        ret++;

    }
    return 0;
}