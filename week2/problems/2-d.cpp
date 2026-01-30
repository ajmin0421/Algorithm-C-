    #include<bits/stdc++.h>
    using namespace std;
    const int max_n=104;
    int dy[]={-1,0,1,0};
    int dx[]={0,1,0,-1};
    int n,m,k,ret,comp,a[max_n][max_n],visited[max_n][max_n];
    int sx,sy,ex,ey,temp=1;
    vector<int> areaSize;

    void dfs(int y,int x){
        visited[y][x]=1;
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||ny>=n||nx<0||nx>=m) continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx]<0) continue;
            temp++;
            dfs(ny,nx);
        }
        return;
    }

    int main(){
        cin>>n>>m>>k;
        for(int i=0;i<k;i++){
            cin>>sx>>sy;
            cin>>ex>>ey;
            for(int t=sy;t<ey;t++){
                for(int q=sx;q<ex;q++){
                    a[t][q]--;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]) continue;
                if(a[i][j]<0) continue;
                comp++;
                visited[i][j]++;
                dfs(i,j);
                areaSize.push_back(temp);
                temp=1;
            }
        }

        cout<<comp<<'\n';
        sort(areaSize.begin(),areaSize.end());
        for(auto it:areaSize){
            cout<<it<<" ";
        }
    }