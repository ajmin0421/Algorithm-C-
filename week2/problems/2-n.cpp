#include<bits/stdc++.h>
using namespace std;

string st;
int n,is_no;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        stack<char> s;
        cin>>st;
        const int len = st.size();
        is_no=0;
        for(int j=0;j<len;j++){
            if(st[j]=='(') s.push('(');
            else if(st[j]==')'){
                if(s.empty()){
                    is_no=1; break;
                }
                s.pop();
            }
        }
        if(is_no||!s.empty()){
            cout<<"NO"<<'\n';
        }else cout<<"YES"<<'\n';

    }
}