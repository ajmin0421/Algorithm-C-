#include<bits/stdc++.h>
using namespace std;
const int n = 4;
int main(){
    string  a[n] = {"사과","딸기","포도","배"};
    for(int i=0;i<(1<<n);i++){
        string ret = "";
        for(int j=0;j<n;j++){//check each bit 0001 0010
            if(i & (1<<j)){
                ret += (a[j] + " ");
            }
        }
        cout<<ret<<'\n';
    }
    return 0;
}