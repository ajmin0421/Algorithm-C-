#include<bits/stdc++.h>
using namespace std;
int team,n,a_total,a_score,b_total,b_score;
int current_time,prev_time;
string s;
int make_t(int m,int s){
    return m*60+s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>team>>s;
        current_time = make_t(stoi(s.substr(0,2)),stoi(s.substr(3,2)));
        if(a_score>b_score) a_total += current_time-prev_time;
        else if(a_score<b_score) b_total += current_time-prev_time;
        prev_time=current_time;
        if(team==1) a_score++;
        else b_score++;
    }
    if(a_score>b_score) a_total +=48*60-prev_time;
    else if(a_score<b_score) b_total += 48*60-prev_time;
    cout<<setfill('0')<<setw(2)<<a_total/60<<":"<<setfill('0')<<setw(2)<<a_total%60<<'\n';
    cout<<setfill('0')<<setw(2)<<b_total/60<<":"<<setfill('0')<<setw(2)<<b_total%60;
    return 0;
}