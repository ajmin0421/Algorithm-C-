#include<bits/stdc++.h>
using namespace std;
int main(){
    int S=18;//10010
    int idx; 
    cin>>idx;
    S&=~(1<<idx);
    cout<<S<<'\n';//16
    return 0;
}