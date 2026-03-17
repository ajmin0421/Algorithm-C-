#include<bits/stdc++.h>
using namespace std;
const int max_n = 14;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
int ret=1e9 ,visited[max_n][max_n],a[max_n][max_n],n;

int can_flower(int y,int x){
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0||ny>=n||nx<0||nx>=n||visited[ny][nx]) return 0; 
    }
    return 1;
}

int set_flower(int val,int y,int x){
    int sum=a[y][x];
    visited[y][x] = val;
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        visited[ny][nx] = val;
        sum+=a[ny][nx];
    }
    return sum;
}

//put seed permutation 원복
//flower make -> visited
//cheapest    

void go(int idx,int depth,int current_sum){
    if(depth==3){
        //sol
        ret = min(ret,current_sum);
        return;
    }
    for(int i=idx;i<n*n;i++){
        int y = i/n; //well-known!!
        int x = i%n;
        if(y<1||y>=n-1||x<1||x>=n-1||visited[y][x]) continue;
        if(can_flower(y,x)){
            int flower_cost = set_flower(1,y,x);
            go(i+1,depth+1,current_sum+flower_cost);
            set_flower(0,y,x);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    go(0,0,0);
    cout<<ret<<'\n';
    return 0;
}