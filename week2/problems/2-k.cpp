#include<bits/stdc++.h>
using namespace std;
int t,n;

int go(int n){
    int temp=0;
    while(n>=5){
        temp += n/5;
        n/=5;
    }
    return temp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<go(n)<<'\n';
    }
    return 0;
}