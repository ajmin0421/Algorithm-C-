#include<bits/stdc++.h>
using namespace std;

//톱니바퀴 회전
//각각의 옆의 극에 따라 
//극이 같으면 x
//다르면 반대방향으로 회전
//순서가 좀 중요할듯
//bfs가 괜찮아 보이는데 방식이 유사해보임
//시간제한 2초
//문자열로 톱니바퀴 입력 받으면 구현이 쉬워보임
//3번과 7번째의 극만 비교하면 됨


int n,k,is_rotate[1004],idx,ret;
vector<pair<int,int>> r;
vector<string> v(1001);

void rotate_gear(void){
    string s;
    for(int i=0;i<n;i++){
        if(is_rotate[i]==0) continue;
        if(is_rotate[i]==1) v[i] = v[i].back() + v[i].substr(0,7);
        else if(is_rotate[i]==-1) v[i] = v[i].substr(1) + v[i].front();
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        r.push_back({a,b});
    }
    for(int i=0;i<k;i++){
        memset(is_rotate,0,sizeof(is_rotate));
        idx = r[i].first; is_rotate[idx-1] = r[i].second;
        //각각의 원쪽 오른쪽 끝까지 극을 비교
        //left
        for(int j=idx-1;j>0;j--){
            if(is_rotate[j]==0) break;
            if(v[j][6]!=v[j-1][2]) is_rotate[j-1] = is_rotate[j]*-1;
            else break;
        }
        //right
        for(int j=idx-1;j<n-1;j++){
            if(is_rotate[j]==0) break;
            if(v[j][2]!=v[j+1][6]) is_rotate[j+1] = is_rotate[j]*-1;
            else break;
        }
        rotate_gear();
    }
    for(int i=0;i<n;i++){
        if(v[i][0]=='1') ret++;
    }
    cout<<ret<<'\n';
    return 0;
}