#include<bits/stdc++.h>
using namespace std;
int main(){
    int S=18;//10010
    int idx = (S&-S); 
    //10010
    //01110 & operate
    //00010 -> idx=2
    cout<<idx<<'\n';
    return 0;
}