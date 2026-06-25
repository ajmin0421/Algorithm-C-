#include<bits/stdc++.h>
using namespace std;

//일단 숫자들을 다 알고 있으니 각각의 말위치에서
//현재 숫자칸 만큼이동하여 가장 큰 값이 나오게 하는것 -> 그리디
//각칸에서 이동한칸에 말이 있으면 x
//백터하나 만들어서 각각의 말의 위치를 적고
//각턴마다 확인하며 최선의 수를 선택 -> 이때 항상 파란칸이 이득은 아닌듯 ex) 30에서 가면 손해
//이때 도착 할 수 있는 경우의 수를 잘 계산해야할듯
//만약 다른걸 도착으로 보내고 말을 움직여서 더 큰 점수를 얻을 수
//있다면 그렇게 하는게 이득이니깐..

//판하나 만들어야겠네
//화살표 구현은 idx에 따라서 10이 적혀 있는칸이면 +3 아니면 +2
//파란칸만 구현하면 될듯
//판을 구현할때 각각의 idx에 왔을때 처리하는 식으로 할지 아니면 ->이러면 최선의 수 계산할때 복잡하고
//따로 배열을 하나 만들어서 구현할지 고민이네.. -> 이거는 각각 하나씩 만들어야되는 부담인데 
//배열 만드는게 안정성은 좋을듯?

int nxt[34];
int blue[34];
int score[34] = {
    0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0, // 0~21
    13, 16, 19, // 22~24
    22, 24,     // 25~26
    28, 27, 26, // 27~29
    25, 30, 35  // 30~32
};
int ret=-1e9;
vector<int> v(10);
vector<int> horse_loc(4, 0);


void go(int sc,int ct){
    if(ct==10){
        ret = max(ret,sc);
        return;
    }
    for(int i=0;i<4;i++){
        int move=horse_loc[i],flag=0,backup=horse_loc[i];
        if(move==21) continue;
        
        for(int j=0;j<v[ct];j++){
            if(j==0&&(move==5||move==10||move==15)) move = blue[move];
            else move = nxt[move];
            if(move==21) break;
        } 
        if(move!=21){
            for(auto it:horse_loc){
                if(move==it){
                    flag=1; break;
                } 
            }
        }
        if(flag) continue;
        
        horse_loc[i]=move;
        go(sc+score[move],ct+1);
        horse_loc[i]=backup;
    }
}

int main(){
    for(int i=0;i<=19;i++){
        nxt[i] = i+1;
    }
    nxt[20]=21;
    nxt[21]=21;
    //10시작
    nxt[22]=23; nxt[23]=24;
    nxt[24]=30;
    //20
    nxt[25]=26; nxt[26]=30;
    //30
    nxt[27]=28; nxt[28]=29; nxt[29]=30;
    //25
    nxt[30]=31; nxt[31]=32; nxt[32]=20;
    blue[5]=22; blue[10]=25; blue[15]=27;
    
    for(int i=0;i<10;i++){
        cin>>v[i];
    }

    go(0,0);

    cout<<ret<<'\n';
    return 0;
}

