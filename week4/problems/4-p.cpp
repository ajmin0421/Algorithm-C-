#include<bits/stdc++.h>
using namespace std;
const int max_n=200004;
int n,ret,check[max_n],ct;
string s;
stack<int> stk;
int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            stk.push(i);
        }else{
            if(!stk.empty()){
                check[stk.top()] = 1;
                stk.pop();
                check[i] = 1;
            }else{
                check[i] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(check[i]){
            ct++;
            ret = max(ret,ct);
        }else ct=0;
 
    }
    cout<<ret<<'\n';
    return 0;
}