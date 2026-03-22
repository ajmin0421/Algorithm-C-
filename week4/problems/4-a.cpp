#include<bits/stdc++.h>
using namespace std;
const int max_n = 17;
vector<int> best_v;
int n,mp,mf,ms,mu,p[max_n],f[max_n],s[max_n],u[max_n],c[max_n],ret=-1,cost=1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>mp>>mf>>ms>>mu;
    for(int i=0;i<n;i++){
        cin>>p[i]>>f[i]>>s[i]>>u[i]>>c[i];
    }
    for(int i=0;i<(1<<n);i++){//bitmasking
        vector<int> current_v;
        int tp=0,tf=0,ts=0,tu=0,tc=0;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                tp+=p[j]; tf+=f[j]; ts+=s[j]; tu+=u[j]; tc+=c[j]; 
                current_v.push_back(j);
            }
        }
        if(tp>=mp&&tf>=mf&&ts>=ms&&tu>=mu){
            if(cost>tc){
                if(ret==-1) best_v = current_v;
                ret = tc;
                cost = tc;
                best_v = current_v;
            }else if(cost==tc){
                if(best_v>current_v){
                    best_v = current_v;
                }
            }
        }
    }
    if(ret!=-1){
        cout<<cost<<'\n';
        for(auto it:best_v) cout<<it+1<<" ";
    }else cout<<-1<<'\n';
    return 0;
}