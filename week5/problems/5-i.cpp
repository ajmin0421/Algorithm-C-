#include<bits/stdc++.h>
using namespace std;
int n,k,h,t,sum,ret;

int main(){
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>k;
    t = n-1;
    sort(v.begin(),v.end());
    while(h<t){
        sum = v[h]+v[t];
        if(sum==k) ret++;
        if(sum>k) t--;
        else h++;
    }
    cout<<ret<<'\n';

}