#include<bits/stdc++.h>
using namespace std;
int n,m,j,loc,h,t,ret;

int main(){
    cin>>n>>m;
    cin>>j;
    h = 1;
    t = m;
    for(int i=0;i<j;i++){
        cin>>loc;
        if(h<=loc&&loc<=t) continue;
        else if(loc<h){
            ret+=h-loc;
            t-=h-loc;
            h=loc; 
        }else if(loc>t){
            ret+=loc-t;
            h+=loc-t;
            t=loc; 
        }
    }
    cout<<ret;
    return 0;
}