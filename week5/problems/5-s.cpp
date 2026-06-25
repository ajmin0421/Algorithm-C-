#include<bits/stdc++.h>
using namespace std;
//숫자 순서는 똑같으니
//next permutation 이용 조합 만들고
//최대 최소 뽑아내기
//10!이면 완탐 가능
//연산자 우선순위 무시하고 순서대로
int n,temp,operators[]={1,2,3,4};
long long MIN=1e9,MAX=-1e9;
vector<int> v,op;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp; v.push_back(temp);
    }
    for(int i=0;i<4;i++){
        cin>>temp;
        for(int j=0;j<temp;j++) op.push_back(operators[i]);
    }
    sort(op.begin(),op.end());
    do{
        long long sum=v[0],idx=1;
        for(auto it:op){
            if(it==1) sum+=v[idx++];
            else if(it==2) sum-=v[idx++];
            else if(it==3) sum*=v[idx++];
            else if(it==4) sum/=v[idx++];
        }
        MAX = max(MAX,sum);
        MIN = min(MIN,sum);
    }while(next_permutation(op.begin(),op.end()));
    
    cout<<MAX<<'\n'<<MIN<<'\n';
    return 0;
}