#include<bits/stdc++.h>
using namespace std;

string a,b,n;
int len,A,B,sum,carry;
int main(){
    cin>>a>>b;
    A = a.size(); B = b.size();
    len = A > B ? B : A;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int i=0;
    while(i<B||i<A||carry){
        sum=carry;
        if(i<len) sum = a[i]-'0'+b[i]-'0'+carry;
        else if(i<A) sum += a[i]-'0';
        else if(i<B) sum += b[i]-'0';
        
        n+=sum%10+'0';
        carry = sum/10;
        ++i;
    }
    reverse(n.begin(),n.end());
    cout<<n<<'\n';
    return 0;
}