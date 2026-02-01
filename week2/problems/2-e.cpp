#include<bits/stdc++.h>
using namespace std;
const int max_n=65;
int n,a[max_n][max_n];

void go(int y,int x,int size){
    if(size==1){
        cout<<a[y][x];
    }else{
        int k=a[y][x],ret=0;
        for(int i=y;i<y+size;i++){
            if(ret) break;
            for(int j=x;j<x+size;j++){
                if(k!=a[i][j]){
                    ret=1; break;
                }
            }
        }
        if(!ret) cout<<k;
        else{
            cout<<'(';
            go(y,x,size/2);
            go(y,x+size/2,size/2);
            go(y+size/2,x,size/2);
            go(y+size/2,x+size/2,size/2);
            cout<<')';
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            a[i][j] = s[j]-'0';
        }
    }
    go(0,0,n);

    return 0;
}