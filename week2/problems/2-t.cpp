#include<bits/stdc++.h>
using namespace std;
int n,temp;
vector<int> v,ret;
stack<int> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    ret.resize(n);
    for(int i=0;i<n;i++){
        cin>>temp;
        while(!s.empty()&&v[s.top()]<temp){
            ret[s.top()] = temp;
            s.pop();
        }
        s.push(i);
        v.push_back(temp);
    }
    while(!s.empty()){
        ret[s.top()] = -1;
        s.pop();
    }
    for(auto it:ret){
        cout<<it<<" ";
    }
    return 0;
}