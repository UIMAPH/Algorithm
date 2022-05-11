#include <string>
#include <vector>
#include<iostream>

using namespace std;
int cache[12][12];
vector<int> peach;

int dp(int n, int left){
    if(n>=10) return 0;
    int& ret = cache[n][left];
    if(ret != -10000000) return ret;
    if(peach[n] > 0) {ret = max(ret, dp(n+1,left) - (10 - n));}
    if(left - (peach[n]) > 0) {ret = max(ret, dp(n+1,left - (peach[n])));};
    if(left - (peach[n] + 1) >= 0) {ret = max(ret, dp(n+1,left - (peach[n]+1)) + (10-n));}
    if (left == 0 and peach[n] == 0) return 0;
    return ret;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    peach = info;
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            cache[i][j] = -10000000;
        }
    }
    dp(0,n);
    for(int i=0;i<11;i++){
        int temp = cache[i][n];
        if(temp - cache[i+1][n] == i-10){
            temp = 0;
        }
        else if(temp - cache[i+1][n-peach[i]] == 0){
            n -= peach[i];
            temp = peach[i];
        }
        else if (temp - cache[i+1][n - (peach[i]+1)] == 10 - i){
            n -= peach[i] + 1;
            temp = peach[i] + 1;
        }
        else temp = 0;
        answer.push_back(temp);
    }
    cout<<cache[3][2];
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            if(cache[i][j] != -10000000) cout<< cache[i][j]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
    return answer;
}
int main(){
    
    vector<int> cute = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    solution(5, cute);
}
