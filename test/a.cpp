#include<bits/stdc++.h>
using namespace std;

int n,flag,t=20;
double d,ret,sum_,mult;
string s,grade;
int main(){
    while(t--){
        cin>>s>>d>>grade;
        if(grade=="P") continue;
        else if(grade=="F") mult=0;
        else if(grade=="A+") mult = 4.5;
        else if(grade=="A0") mult = 4;
        else if(grade=="B+") mult = 3.5;
        else if(grade=="B0") mult = 3;
        else if(grade=="C+") mult = 2.5;
        else if(grade=="C0") mult = 2;
        else if(grade=="D+") mult = 1.5;
        else if(grade=="D0") mult = 1;
        ret += mult*d;
        sum_ += d;
    }
    ret /= sum_;
    cout<<fixed;
    cout.precision(6);
    cout<<ret<<'\n';
    return 0;
}