#include<bits/stdc++.h>
using namespace std;
const int V=10;
bool a[V][V], visited[V];
void go(int from){
    visited[from] = 1; //from의 위치에서 방문했는지 안했는지 저장
    cout<< from <<'\n';
    for(int i=0;i<V;i++){
        if(visited[i]) continue;//했다면 건너뛰고
        if(a[from][i]) go(i);//아니면 그대로 그 노드로
    }
    return;
}
int main(){
    a[1][2] = 1; a[1][3] = 1; a[3][4] = 1;
    a[2][1] = 1; a[3][1] = 1; a[4][3] = 1;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(a[i][j] && visited[i]==0){
                go(i);
            }
        }
    }
}