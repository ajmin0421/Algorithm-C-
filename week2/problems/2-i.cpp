    #include<bits/stdc++.h>
    using namespace std;
    int n,is_num,loc,ct;
    string s;
    vector<string> v;

    void go(string temp,vector<string>& v){
        while(temp.size()>1&&temp[0]=='0'){
            temp.erase(0,1);
        }
        v.push_back(temp);
    }

    bool cmp(const string& a,const string& b){
        if(a.size()!=b.size()){
            return a.size()<b.size();
        }
        return a<b;
    }

    int main(){ 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s; 
            is_num=0; ct=0;
            const int len = s.size();
            for(int j=0;j<len;j++){
                if('0'<=s[j]&&s[j]<='9'){
                    if(!is_num) loc=j;
                    is_num=1; 
                    ct++;
                    if(j==len-1){
                        string temp = s.substr(loc,ct);
                        go(temp,v);
                    }
                }else if(is_num){
                    string temp = s.substr(loc,ct);
                    go(temp,v);
                    is_num=0;
                    ct=0;
                }
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(auto it:v){
            cout<<it<<'\n';
        }

        return 0;
    }