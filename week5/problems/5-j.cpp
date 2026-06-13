#include<bits/stdc++.h>
using namespace std;

vector<int> multi,v;
int n,k,temp,ret;

int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>temp;
        v.push_back(temp);
    }
    for(int i=0;i<k;i++){
        bool is_pluged = false;
        //멀티탭에 있는지 확인
        for(auto it:multi){
            if(it==v[i]){ is_pluged = true; break;}
        }
        if(is_pluged) continue;
        //남은 공간이 있으면 넣어주고
        if(multi.size()<n){
            multi.push_back(v[i]);
            continue;
        } 
        //없다면 가장 먼 거리에 있는거나 영영 나타나지 않는 것을 뽑음
        int target_idx = -1;
        int last_pos = -1;

        for(int idx=0;idx<multi.size();idx++){
            int next_appearance = 1e9;
            for(int j=i+1;j<k;j++){
                if(v[j]==multi[idx]){
                    next_appearance = j;
                    break;
                }
            }
            if(last_pos<next_appearance){
                last_pos = next_appearance;
                target_idx = idx;
            }
        }

        multi[target_idx] = v[i];
        ret++;
    }
    cout<<ret<<'\n';
    return 0;
}