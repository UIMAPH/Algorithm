#include<iostream>
#include<utility>
using namespace std;

int arr[10][100000];
bool vitied[100000];
int testCase;
int dp[100000];
int n, people;
int dir1[3]={n-1,0,1};
int dir2[3]={n-1,0,1};


void init(){
    for(int i=0;i<100000;i++){
        dp[i]=20000000;
    }
}

pair<int,int> cal(int x){
    return make_pair(x/n, x%n);
}

int DP(int num){
    if(dp[num]) return dp[num];
    int& ret = dp[num];
    if(num>=n) return 0;
    //이미 묶여있는 구역이면
    if(vitied[num]){
        ret = min(ret, DP(num+1));
        return ret;
    }
    //이구역은 묶지 않을 거면
    ret = min(ret, DP(num)+1);
    int y = num/people;
    int x = num%people;
    //오른쪽을 묶을거면
    if((num+1)%n != 0 and !vitied[num+1] and arr[y][x]+arr[y][x+1]<=people){
        vitied[num+1] = true;
        vitied[num] = true;
        ret = min(ret, DP(num+1));
        vitied[num+1] = false;
    }
    //아래로 묶을 거면
    if(num/n>1 and !vitied[num+n] and arr[y][x]+arr[y+1][x]<=people){
        vitied[num+n] = true;
        ret = min(ret, DP(num+1));
        vitied[num+n] = false;
    }
    return ret;
}

void solve(){
    cin>>testCase;
    while(testCase--){
        cin>>n>>people;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                arr[dir1[i]][dir2[j]]+arr[0][[0]
            }
        }
        
        
        
        
        
        
        
        
        
    }
}




int main(){
    
}


