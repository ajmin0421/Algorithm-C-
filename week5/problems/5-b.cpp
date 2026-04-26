#include<bits/stdc++.h>
using namespace std;

string s,bomb,temp;
char end;
int flag;

int main(){
    cin>>temp;
    cin>>bomb;
    for(int i=0;i<temp.size();i++){
        s.push_back(temp[i]);
        if(s.back()==bomb.back()&&s.size()>=bomb.size()){
            flag=0;
            for(int j=1;j<=bomb.size();j++){
                if(bomb[bomb.size()-j]!=s[s.size()-j]){
                    flag=1; break;
                }
            }

            if(!flag) s.erase(s.size()-bomb.size(),s.size());
            //for(int j=0;j<bomb.size();j++) s.pop_back();
        }
    }
    if(!s.size()) cout<<"FRULA"<<'\n';
    else cout<<s<<'\n';
    return 0;
}