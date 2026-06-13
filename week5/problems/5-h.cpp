#include<bits/stdc++.h>
using namespace std;

vector<int> cnt(100001,0);
vector<int> v;
int n,temp,h,t;
long long ret;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    for(h=0;h<n;h++){
        while(t<n&&cnt[v[t]]==0){
            cnt[v[t++]]++;
        }
        ret+=t-h;
        cnt[v[h]]--;
    }
    cout<<ret<<'\n';
}