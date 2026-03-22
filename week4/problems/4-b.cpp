#include<bits/stdc++.h>
using namespace std;
const int max_n = 24;
int n,coin_state[max_n],ret=1e9;
char temp,a[max_n][max_n];
string s;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='T'){
                coin_state[j] |= (1<<i);
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            int ct = __builtin_popcount(i^coin_state[j]);
            sum += min(ct,n-ct);
        }
        ret = min(ret,sum);
    }
    cout<<ret<<'\n';
    return 0;
}