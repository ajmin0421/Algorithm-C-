#include<bits/stdc++.h>
using namespace std;
vector<char> ops;
vector<int> nums;
int n,mx=-1e9;
string temp;

int cal(int a,int b,char s){
    if(s=='*') return a*b;
    if(s=='-') return a-b;
    if(s=='+') return a+b;
}

void go(int ops_idx,int cur_val){
    if(ops_idx==(int)ops.size()){
        //sol
        mx = max(mx,cur_val);
        return;
    }
        
    go(ops_idx+1,cal(cur_val,nums[ops_idx+1],ops[ops_idx]));//괄호x
    if(ops_idx+2>(int)ops.size()) return;
    go(ops_idx+2,cal(cur_val,cal(nums[ops_idx+1],nums[ops_idx+2],ops[ops_idx+1]),ops[ops_idx]));//괄호o
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    cin>>temp;
    for(int i=1;i<=n;i++){
        if(i%2==0) ops.push_back(temp[i-1]);
        else nums.push_back(temp[i-1]-'0');
    }
    go(0,nums[0]);
    cout<<mx<<'\n';
    return 0;
}