#include<bits/stdc++.h>
using namespace std;

//널빤지 길이를 입력받고
//최소갯수 구하는거니깐 시작점부터 하나씩 놓으면 될듯?
//제한 시간 2초 n의 최댓값이 10억이니 O(n) 가능 <- 1초에 1억이잖아... 20초야
//그리디 투포인터 슬라이딩 윈도우등
//슬라이딩 윈도우 활용하면 좋을듯?
//딱히 안어려워보이느,ㄴ데...
//왜 골드지?

vector<pair<int,int>> v;
int n,l,a,b,ret,next_avail,dis,sum;

int main(){
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    for(auto it:v){
        if(it.second<=next_avail) continue;
        if(it.first>next_avail) next_avail=it.first;
        dis = it.second-next_avail;
        sum = dis/l;
        if(dis%l) sum++;
        next_avail += sum*l;
        ret+=sum;
    }

    //거리/널빤지 길이=몫 + 거리%널빤지 길이 = 나머지
    //나머지 + 몫이 ret 
    //next_avail=널빤지 길이*(몫 + 나머지)
    
    cout<<ret<<'\n';
    return 0;
}