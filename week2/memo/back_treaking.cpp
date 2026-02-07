#include<bits/stdc++.h>
using namespace std;
int k,n;

void combi(int start,vector<int> &b){
    if(b.size()==k){
        //solve
    }
    for(int i=start+1;i<n;i++){
        b.push_back(i);
        combi(i,b);
        b.pop_back();
    }
    return;
}