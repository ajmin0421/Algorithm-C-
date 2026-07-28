#include<bits/stdc++.h>
using namespace std;
int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};

//선분을 배열 한칸이라고 생각하고 있으면 1 아니면 0으로 구현 -> 결국 선분은 점의 연속이니 점을 기록 **
//일단 세대 별로 나누어서 만들어지는걸로 보면
//dfs나 bfs로 구현하면 좋을거 같다고 생각하고
//벡터에 하나하나 세대별로 쌓으며 90도 회전된 값만큼 다시 벡터에 추가
//입력받은거 다끝나면 사각형이 완성된것 찾아서 출력

int n,y,x,d,g,a[104][104],ret;


int main(){
    cin>>n;
    while(n--){
        cin>>x>>y>>d>>g;
        vector<int> dirs;
        dirs.push_back(d);

        for(int i=0;i<g;i++){
            int sz = dirs.size();
            for(int j=sz-1;j>=0;j--){
                dirs.push_back((dirs[j]+1)%4);
            }
        }

        a[y][x] = 1;
        for(int i=0;i<dirs.size();i++){
            y+=dy[dirs[i]];
            x+=dx[dirs[i]];
            a[y][x] = 1;
        }
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]) ret++;
        }
    }
    cout<<ret<<'\n';
    return 0;
}