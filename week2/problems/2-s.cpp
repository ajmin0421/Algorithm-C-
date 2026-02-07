#include<bits/stdc++.h>
using namespace std;
vector<int> v[10004];
vector<int> ret;

int n,m,a,b,ct,visited[10004],max_val;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[b].push_back(a);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        visited[i] = 1;
        int child=1;
        q.push(i);
        while(!q.empty()){
            int node = q.front(); q.pop(); 
            for(auto it:v[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it); 
                    child++;
                }
            }
        }   
        if(max_val<child){
            max_val = child;
            ret.clear(); ret.push_back(i);
        }else if(max_val==child) ret.push_back(i);
    }
    for(auto it:ret){
        cout<<it<<" ";
    }
    return 0;
}