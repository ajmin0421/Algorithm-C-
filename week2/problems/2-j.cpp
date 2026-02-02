#include<bits/stdc++.h>
using namespace std;
const int max_n=104;
int h,w,ct,is_cloud;
char a[max_n][max_n];
int ret[max_n][max_n];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<h;i++){
        is_cloud=0;
        for(int j=0;j<w;j++){
            if(a[i][j]=='c'){
                ct=0;
                is_cloud=1;
                ret[i][j] = ct; 
            }else{
                if(is_cloud){
                    ct++;
                    ret[i][j] =ct;
                }else ret[i][j]=-1;               
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
