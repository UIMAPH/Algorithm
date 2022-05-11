#include<iostream>
#include<algorithm>
using namespace std;

int n,k;
int weight[101];
int value[101];
int dp[101][100001] = {0,};



void input(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
}


int solve(int x,int w){
    if(dp[x][w]!=0) {return dp[x][w];}
    if(x>=n){return 0;}
    int& ret = dp[x][w];
    if(w+weight[x]<=k){
        ret = max(ret, solve(x+1,w+weight[x])+value[x]);
    }
    ret = max(ret, solve(x+1,w));
    
    return ret;
}


int main(){
    input();
    solve(0,0);
    cout<<dp[0][0];
}


