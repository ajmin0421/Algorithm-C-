#include<bits/stdc++.h>
using namespace std;
//일단 가장 작은 값 넣고 거기서 부터 길이 확인하면 될거 같고
//근데 하나 하나 확인하려면 -10억~10억이니 시간 복잡도 초과
//선분의 길이이니 그거 감안해서 배열 만들기
//슬라이딩 윈도우 사용해서 하거나 투포인터 써야할거 같은데 시간복잡도가...?
//하나하나 계산x -> 선분자체로 계산
int n,a,b,h,t,ret=0;
vector<pair<int,int>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    h = v[0].first;
    t = v[0].second;
    
    for(int i=1;i<v.size();i++){
        if(v[i].first<=t&&v[i].second<=t) continue;
        else if(v[i].first<=t&&v[i].second>=t){
            t = v[i].second;
        }else{
            ret += t-h;
            h = v[i].first;
            t = v[i].second;
        }
    }
    ret += t-h;
    
    cout<<ret<<'\n';
    return 0;
}