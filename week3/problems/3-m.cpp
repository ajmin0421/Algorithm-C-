#include<bits/stdc++.h>
using namespace std;

int n,ret,visited[10];
string mn="9876543210",mx="0",s;
char t[11];
vector<char> v;

int check(void){
    int is_ok=1;
    for(int i=0;i<(int)v.size()-1;i++){
        if(t[i]=='<') if(v[i]>=v[i+1]) is_ok=0;
        if(t[i]=='>') if(v[i]<=v[i+1]) is_ok=0;
    }
    return is_ok;
}

void go(int depth){
    if(!check()) return;
    if(depth==n+1){
        //sol
        string s;
        for(int i=0;i<n+1;i++){
            s+=v[i];
        }
        if(mx<s) mx = s;
        if(mn>s) mn = s;
    }
    for(int i=0;i<10;i++){
        if(visited[i]) continue;
        v.push_back((char)(i+'0'));
        visited[i] = 1;
        go(depth+1);
        v.pop_back();
        visited[i] = 0;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>t[i];
    go(0);
    cout<<mx<<'\n'<<mn<<'\n';
    return 0;
}