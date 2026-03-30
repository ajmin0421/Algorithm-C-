#include<bits/stdc++.h>
using namespace std;

int a[10][10],n,m,ret;
string s;

int row(int idx){
    int sum=0;
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<m;j++){
            if(!(idx&(1<<(i*m+j)))){
                temp = temp*10 + a[i][j]; 
            }else{
                sum+=temp;
                temp=0;
            }
        }
        sum+=temp;
    }
    return sum;
}

int col(int idx){
    int sum=0;
    for(int j=0;j<m;j++){
        int temp=0;
        for(int i=0;i<n;i++){
            if((idx&(1<<(i*m+j)))){
                temp = temp*10 + a[i][j]; 
            }else{
                sum+=temp;
                temp=0;
            }
        }
        sum+=temp;
    }
    return sum;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j] = s[j]-'0';
        }
    }
    for(int i=0;i<(1<<n*m);i++){
        ret = max(ret,row(i)+col(i));
    }
    cout<<ret<<'\n';
    return 0;
}