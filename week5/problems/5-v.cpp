#include<bits/stdc++.h>
using namespace std;

//연속한 -> 투포인터,슬라이딩 윈도우
// A,B를 각각 나누어서 투포인터 사용해서 합을 구함
//1.정렬 -> 이러면 연속이깨짐 xx
// a,b에서 나올 누적합을 미리 다 구해서 pre_sum 배열에 저장

vector<int> A,B,subA,subB;
int p,m,n,h,t,sum,ret,total_sum;

int main(){
    cin>>p>>m>>n;
    A.resize(m+1); B.resize(n+1);
    for(int i=0;i<m;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];

    subA.push_back(0);
    subB.push_back(0);
    for(int i=0;i<m;i++) A.push_back(A[i]); //원형이니 2배로 만들어주기
    for(int i=0;i<n;i++) B.push_back(B[i]); //원형이니 2배로 만들어주기
    
    for(int i=0;i<m;i++){//부분합
        int cur_sum=0;
        for(int j=0;j<m-1;j++){
            cur_sum += A[i+j];
            subA.push_back(cur_sum);
        }
    }
    for(int i=0;i<n;i++){//부분합B
        int cur_sum=0;
        for(int j=0;j<n-1;j++){
            cur_sum += B[i+j];
            subB.push_back(cur_sum);
        }
    }
    
    for(int i=0;i<m;i++) total_sum+=A[i]; //전체합
    subA.push_back(total_sum);
    total_sum=0;
    for(int i=0;i<n;i++) total_sum+=B[i]; //전체합
    subB.push_back(total_sum);

    sort(subA.begin(),subA.end());
    sort(subB.begin(),subB.end());

    int tb=0,hb=0;
    while(1){
        if(h==t) break;
        if(sum>p) sum-=subA[h++];
        else if(sum==p) ret++,sum-=subA[h++];
        else if(sum<p) sum+=subA[t++]; 

        while(1){
            if(hb==tb) break;
            if(sum>p) sum-=subB[hb++];
            else if(sum==p) ret++,sum-=subB[hb++];
            else if(sum<p) sum+=subB[tb++]; 
        }
    }

    cout<<ret<<'\n';
    return 0;
}