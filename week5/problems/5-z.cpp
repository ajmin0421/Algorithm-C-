#include<bits/stdc++.h>
using namespace std;

//문제에서 주어진 원을 이차원 배열로 해석
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int a[54][54],flag[54][54],n,m,t,x,d,k,ret;

void rot(int idx,int d,int k){
    int temp[m];
    for(int j=0;j<m;j++){
        if(d==0) temp[(j+k)%m] = a[idx][j];
        else temp[(j-k%m+m)%m] = a[idx][j];
        
    }
    memcpy(a[idx],temp,sizeof(temp));
}
       
void dfs(int y,int x){
    //dfs 너낌 확인순서 up,right,down,left
    flag[y][x] = 1;

    for(int i=0;i<4;i++){
        int ny = dy[i] + y;
        int nx = (dx[i] + x + m)%m;
        
        if(ny<0||ny>=n) continue;
        if(flag[ny][nx]==1||a[ny][nx]==0) continue;
        
        if(a[ny][nx]==a[y][x]){
            dfs(ny,nx);    
        }
    }
}

void go(int x,int d,int k){
    for(int i=0;i<n;i++){
        if((i+1)%x==0){
            //해당 배열 회전
            rot(i,d,k);       
        }
    }
    
    bool erased =false;
    memset(flag,0,sizeof(flag));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0) continue;

            bool has_adj = false;
            
            for(int idx=0;idx<4;idx++){
                int ny = dy[idx] + i;
                int nx = (dx[idx] + j + m)%m;
                
                if(ny<0||ny>=n) continue;
                
                if(a[ny][nx]==a[i][j]){
                    has_adj = true;
                    break;
                }
            }

            if(has_adj&&!flag[i][j]){
                dfs(i,j);
                erased = true;
            }
        }
    }

    if(erased){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(flag[i][j]==1) a[i][j]=0;
            }
        }
    }else{ //평균지우기
        double sum=0,ct=0,avg;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0) continue;
                sum+=a[i][j]; ct++;
            }
        }

        if(ct==0) return;
        avg = sum/ct;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0) continue;
                if(a[i][j]>avg) a[i][j]--;
                else if(a[i][j]<avg)a[i][j]++;
            }
        }
    }
}

int main(){
    cin>>n>>m>>t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<t;i++){
        cin>>x>>d>>k;
        go(x,d,k);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ret+=a[i][j];
        }
    }
    cout<<ret<<'\n';
    return 0;
}