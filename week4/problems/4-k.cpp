#include<bits/stdc++.h>
using namespace std;

int n,m,t,visited[1004],a,b,cnt;
vector<int> v[1004];

void go(int idx){
    visited[idx] = 1;
    for(auto it:v[idx]){
        if(!visited[it]) go(it);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        for(int i=0;i<1004;i++) v[i].clear();
            fill(visited,visited+1004,0);
            cin>>n>>m;
            for(int i=0;i<m;i++){
                cin>>a>>b;
                v[a].push_back(b);    
                v[b].push_back(a);    
            }
            cnt=0;              
            for(int i=1;i<=n;i++){
                if(!visited[i]){
                    go(i); 
                    cnt++;
                }
            }
            if(m==n-1&&cnt==1) cout<<"tree"<<'\n';
            else cout<<"graph"<<'\n';
    }
    return 0;
}