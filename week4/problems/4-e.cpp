#include<bits/stdc++.h>
using namespace std;
const int max_n=104;
int n,L,a[max_n][max_n],ret;

bool check(vector<int>& line){
    int visited[max_n]; memset(visited,0,sizeof(visited));
    for(int i=1;i<n;i++){
        int prev = line[i-1],cur = line[i];
        if(prev!=cur){
            int sum = prev-cur;
            if(abs(sum)!=1) return false;
            if(sum<0){
                if(i-L<0) return false; //범위를 안벗어나는지 체크
                for(int j=i-1;j>=i-L;j--){// L개의 연속된 길이 같은 높이인지 체크
                    if(line[j]!=line[i-1]||visited[j]) return false; //visited 체크
                    visited[j] = 1;
                }
                
            }else{
                if(i+L>n) return false;
                for(int j=i;j<i+L;j++){
                    if(line[j]!=line[i]||visited[j]) return false;
                    visited[j] = 1;
                }
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>L;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<n;j++) row.push_back(a[i][j]);
        if(check(row)) ret++;
        vector<int> col;
        for(int j=0;j<n;j++) col.push_back(a[j][i]);
        if(check(col)) ret++;
    }
    cout<<ret<<'\n';
    return 0;
}