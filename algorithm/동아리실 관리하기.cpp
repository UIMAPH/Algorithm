
#include<iostream>
#include<string>

using namespace std;

int arr[10002];
int dp[10002][17];

void init(){
    for(int i=0;i<10002;i++){
        arr[i]=0;
    }
    for(int i=0;i<10002;i++){
        for(int j=0;j<17;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][1] = 1;
    arr[0] = 1;
}


int main(int argc, char** argv){
    int test_case;
    int T;
    
    string temp;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case){
        init();
        cin>>temp;
        for(int i=0;i<=temp.size();i++){
            arr[i+1] = (1<<(temp[i] -'A'));
        }
        for(int i=1;i<=temp.size();i++){
            for(int x=1;x<16;x++){
                if(dp[i-1][x] != 0){
                    for(int y=1;y<16;y++){
                        if((x & y) > 0 and (arr[i] & y)> 0){
                            dp[i][y] = ( dp[i][y] + dp[i-1][x] ) % 1000000007;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=1;i<16;i++){
            ans = (ans + dp[temp.size()][i]) % 1000000007;
        }
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
