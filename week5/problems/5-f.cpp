#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ret,high,low,sum;

vector<int> sieve(int n){
    vector<bool> is_prime(n+1,true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2;i*i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j += i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(is_prime[i]) primes.push_back(i);
    }
    return primes;
}

int main(){
    cin>>n;
    if(n==1){
        cout<<0<<'\n'; return 0;
    }
    vector<int> primes = sieve(n);
    sum+=primes[0];
    while(high<primes.size()||low<primes.size()){
        if(high==primes.size()) break;
        else if(sum<n) sum+=primes[++high];
        else if(sum>n) sum-=primes[low++];
        else{
            ret++; sum-=primes[low++];
        }
    }
    cout<<ret<<'\n';
    return 0;
}