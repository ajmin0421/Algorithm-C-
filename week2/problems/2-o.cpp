    #include<bits/stdc++.h>
    using namespace std;

    int n,is_no;
    string st;
    
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        while(getline(cin,st)&&st!="."){
        
            stack<char> s;
            const int len = st.size();
            is_no=0;
            for(int j=0;j<len;j++){
                if(st[j]=='(') s.push('(');
                else if(st[j]=='[') s.push('[');
                else if(st[j]==')'){
                    if(s.empty()||s.top()!='('){
                        is_no=1; break;
                    }
                    s.pop();
                }else if(st[j]==']'){
                    if(s.empty()||s.top()!='['){
                        is_no=1; break;
                    }
                    s.pop();
                }
            }
            if(is_no||!s.empty()){
                cout<<"no"<<'\n';
            }else cout<<"yes"<<'\n';
        }
        return 0;
    }