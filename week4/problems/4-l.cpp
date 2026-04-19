#include<bits/stdc++.h>
using namespace std;

int t,n;
string str_arr,p;

int main(){
    cin>>t;
    while(t--){
        deque<int> d;
        cin>>p>>n>>str_arr;
        string temp="";
        for(char c:str_arr){
            if(isdigit(c)){
                temp+=c;
            }else{
                if(!temp.empty()){
                    d.push_back(stoi(temp));
                    temp="";
                }
            }
        }

        int state=0,flag=0;
        for(int i=0;i<(int)p.size();i++){
            if(p[i]=='D'){
                if(d.empty()){ 
                    cout<<"error"<<'\n';
                    flag=1;
                    break;
                }
                else{
                    if(state==1) d.pop_back();
                    else d.pop_front();
                }
            }else state^=1;
        }
        if(!flag){
            if(state==0){
                cout<<'[';
                for(auto it=d.begin();it!=d.end();++it){
                    cout<<*it;
                    if(next(it)!=d.end()) cout<<',';
                }
                cout<<']'<<'\n';
            }else{
                cout<<'[';
                for(auto it=d.rbegin();it!=d.rend();++it){
                    cout<<*it;
                    if(next(it)!=d.rend()) cout<<',';
                }
                cout<<']'<<'\n';
            }
        } 
    }
    return 0;
}