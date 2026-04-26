#include<bits/stdc++.h>
using namespace std;

string S,T,ret;
stack<char> stk;
int main(){
    cin>>S>>T;
    for(auto a:S){
        stk.push(a);
        if(stk.size()>=T.size()&&stk.top()==T.back()){
            ret="";
            for(int i=0;i<T.size();i++){
                ret+=stk.top(); stk.pop();
            }
            reverse(ret.begin(),ret.end());
            if(ret!=T) for(auto r:ret) stk.push(r);
        }
    }
    if(stk.empty()) cout<<"FRULA"<<'\n';
    else{
        ret="";
        while(!stk.empty()){
            ret+=stk.top(); stk.pop();
        }
        reverse(ret.begin(),ret.end());
        cout<<ret<<'\n';
    }
    return 0;
}