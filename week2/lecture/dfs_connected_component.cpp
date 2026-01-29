#include<bits/stdc++.h>
using namespace std;
const int n=100;
int a[n][n], visited[n][n];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int ct=0,N,M;

void go(int y,int x){
    visited[y][x] = 1;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||ny>=N||nx<0||nx>=M) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx]==0) continue;
        go(ny,nx);
    }
    return;
}


int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(a[i][j]==0||visited[i][j]) continue;
            go(i,j); ct++;
        }
    }
    cout<<ct;
    return 0;   
}


