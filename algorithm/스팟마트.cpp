#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int dp[3010][2];
int n,m;
vector<int> narr;
vector<int> marr;
int backAns;
int ans;
int start=0;
bool visited[3010] = {0,};


void input(){
    cin>>n;
    narr.push_back(0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        narr.push_back(temp);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        marr.push_back(temp);
    }
}

//6see 1more
void makenarr(){
    sort(marr.begin(),marr.end(),greater<>());
    for(int i=0;i<n;i++){
        dp[i+1][0] = max(dp[i][0],dp[i][1]);
        dp[i+1][1] = dp[i][0]+narr[i+1];
        //cout<<i+1<<" yes"<<dp[i+1][1]<<" no"<<dp[i+1][0]<<"\n";
    }
    backAns = max(dp[n][0],dp[n][1]);
    ans = backAns;
    for(int i=n;i>0;i--){
        if(backAns - narr[i] == max(dp[i-2][0],dp[i-2][1]) and i != 1){
            visited[i] = true;
            backAns -= narr[i];
            i--;
        } if(i == 1 and backAns == narr[i]){
            visited[i]=true;
        }
        if(!visited[i] and !visited[i+1]){
            ans += marr[start];
            start++;
        }
    }
    
}

void makemarr(){
    if(visited[1] == false and start <= marr.size()-1){
        ans += marr[start];
        start++;
    }
    if(visited[n] == false and start <= marr.size()-1 ){
        ans += marr[start];
        start++;
    }
    
    
    
    
    
    
    
    
}





// 10 x1 12 x2 14 x6  7 x1
// 8
// 6 1

void init(){
    for(int i=0;i<3010;i++){
        visited[i]=0;
        leftright[i]=0;
        for(int j=0;j<2;j++){
            dp[i][j]=0;
        }
    }
    n=0;
    m=0;
    narr.clear();
    marr.clear();
    backAns=0;
    nam.clear();
    ans=0;
    twice=0;
    twicev.clear();
}

int main(int argc, char** argv){
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        init();
        input();
        makenarr();
        makemarr();
        cout<<"#"<<test_case<<" "<< ans<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
