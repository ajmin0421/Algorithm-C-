#include<bits/stdc++.h>
using namespace std;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
//완탐 백트래킹으로 풀꺼고
//주의점 한번의 이도에서 이미 합쳐진 블록은 다른 블록과 합쳐지지 않는다는것
//그리고 합쳐질때 이동방향의 있는 블록이 먼저 합쳐진다는것 위로하면 위블럭부터
//분기마다 새로운 배열 ㄱㄱ
int n,a[21][21],ret=-1e9;

void rotate(void){
    int r[21][21];
    memcpy(r,a,sizeof(a));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = r[n-j-1][i];
        }
    }
}

void move_board(){
    int check[21][21]={0};
    for(int i=0;i<n;i++){
        vector<int> q;
        for(int j=0;j<n;j++){
            if(a[i][j]!=0){
                q.push_back(a[i][j]);
                a[i][j]=0;
            }
        }
        int idx=0;
        for(int j=0;j<q.size();j++){
            if(idx > 0 && a[i][idx-1] == q[j] && !check[i][idx-1]){
                a[i][idx-1]*=2;
                check[i][idx-1] = 1;
            }else{
                a[i][idx++] = q[j];
            }
        }
    }
}

void go(int count){
    if(count==5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ret = max(ret,a[i][j]);
            }
        }
        return;
    }

    for(int i=0;i<4;i++){
        int backup[21][21];
        memcpy(backup,a,sizeof(a));

        //옳기고
        move_board();
        go(count + 1);
        //원복
        memcpy(a,backup,sizeof(backup));
        rotate();
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    go(0);
    cout<<ret<<'\n';
    return 0;
}