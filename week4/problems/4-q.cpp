#include<bits/stdc++.h>
using namespace std;

int n;
long long ret;
stack<pair<int,int>> stk;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        int h; cin>>h;
        int same_count = 1;

        while(!stk.empty()&&stk.top().first<h){
            ret += stk.top().second;
            stk.pop();
        }
        if(!stk.empty()){
            if(stk.top().first==h){
                ret += stk.top().second;
                same_count = stk.top().second + 1;
                
                if(stk.size()>1) ++ret;
                stk.pop();
                
            }else ++ret;
        }
        stk.push({h,same_count});
    }
    cout<<ret<<'\n';
    return 0;
}
