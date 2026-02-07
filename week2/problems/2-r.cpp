#include<bits/stdc++.h>
using namespace std;
vector<int> v[10004];
int n,k,root,del,ct;
void dfs(int node){
    int child=0;
    for(auto it:v[node]){
        if(it==del) continue;
        child++;
        dfs(it);
    }
    if(child==0) ct++;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==-1) root = i;
        else v[k].push_back(i);
    }
    cin>>del;
    if(del!=root) dfs(root);
    cout<<ct<<'\n';
    return 0;
}