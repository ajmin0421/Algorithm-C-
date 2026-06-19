#include<bits/stdc++.h>
using namespace std;

//회전 최소 한번씩 사용 -> 순서 조합으로 만들어서 최솟값 찾기
//최솟값 bfs?
//각 행의 값의 합 구하는 함수
//배열을 돌리는 함수
//s의 값에 따라 회전하는 횟수 결정 s->1 가운데 값 가만히 나머지 한번 회전 -> 그럼 점점 커지게 하면 되겠다
//기본 배열 나두고 임의의 배열 만들어서 한바퀴돌리며 다시 원래 자리로 돌아오면 시작과 끝지점 옳기기
struct Operation{
    int r,c,s;
};

vector<int> idx;
vector<Operation> v(6);
int n,m,k,r,c,s,a[51][51],b[51][51],ret=1e9,backup[51][51];;

void cal(void){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=b[i][j];
        }
        ret = min(ret,sum);
    }
}

void rotate_layer(int R,int C,int S){
    int sy = R-S-1;
    int sx = C-S-1;
    int ey = R+S-1;
    int ex = C+S-1;

    if(S==0) return;

    for(int i=sx;i<ex;i++) b[sy][i+1] = a[sy][i];//right
    for(int i=sy;i<ey;i++) b[i+1][ex] = a[i][ex];//down
    for(int i=ex;i>sx;i--) b[ey][i-1] = a[ey][i];//left
    for(int i=ey;i>sy;i--) b[i-1][sx] = a[i][sx];//up\

    //회전 종료 -> a배열 초기화
    memcpy(a,b,sizeof(b));

    rotate_layer(R,C,S-1);
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<k;i++){
        cin>>v[i].r>>v[i].c>>v[i].s;
    }

    for(int i=0;i<k;i++) idx.push_back(i);

    memcpy(backup,a,sizeof(a));
    do{
        memcpy(a,backup,sizeof(backup));
        for(auto it:idx){
            memcpy(b,a,sizeof(a));
            rotate_layer(v[it].r,v[it].c,v[it].s);
        }
        cal();
    }while(next_permutation(idx.begin(),idx.end()));

    cout<<ret<<'\n';
    return 0;
}