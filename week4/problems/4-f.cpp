#include<bits/stdc++.h>
using namespace std;
const int max_n = 54;
int n,k,ret,word_mask[max_n],w;
string s;

void go(int idx,int depth,int mask){
    if(depth>=k){
        int ct=0;
        for(int i=0;i<n;i++){
            if((mask & word_mask[i])==word_mask[i]) ct++;
        }
        ret = max(ret,ct);
        return;
    }
    for(int i=idx;i<26;i++){
        if((1<<i) & mask) continue;
        go(i+1,depth+1,mask|(1<<i));
    }
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s;
        int l = s.size();
        for(int j=0;j<l;j++) word_mask[i] |= (1<<(s[j]-'a'));
    } 
        
    if(k<5){
        cout<<0<<'\n';
        return 0;
    }
    

    w |= (1<<0); w |= (1<<('n'-'a')); w |= (1<<('t'-'a')); w |= (1<<('i'-'a')); w |= (1<<('c'-'a'));

    go(0,5,w);

    cout<<ret<<'\n';
    return 0;
}