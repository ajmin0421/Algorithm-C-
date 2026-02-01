#include<bits/stdc++.h>
using namespace std;
string s,vol="aeiou";
int flag,is_vowel,ct;

int main(){
    while(cin>>s&&s!="end"){
        flag=0,is_vowel=-1,ct=0;
        const int len = s.size();
        for(int i=0;i<len;i++){
            if(vol.find(s[i])!=string::npos){
                if(!is_vowel) ct=1;
                else ct++;
                is_vowel=1;
                flag=1;
            }else{
                if(is_vowel) ct=1;
                else ct++;
                is_vowel=0;
            }
            if(ct>=3){
                flag=0; break;
            }else if(i&&s[i]!='e'&&s[i]!='o'&&s[i]==s[i-1]){
                flag=0; break;
            }
        }
        if(!flag) cout<<'<'<<s<<"> is not acceptable.\n";
        else cout<<'<'<<s<<"> is acceptable.\n";
    }
    return 0;
}   