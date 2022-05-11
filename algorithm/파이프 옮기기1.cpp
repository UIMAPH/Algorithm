#include<iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);

    int N, dp[20][20][3] = {0,}, r[20][20];

    cin >> N;

    for(int i=1 ; i<=N ; i++)
        for(int j=1 ; j<=N ; j++)
            cin >> r[i][j];

    dp[1][2][0] = 1;

    for(int i = 1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            int right = r[i][j+1] , down = r[i+1][j], dia = right + down + r[i+1][j+1];
            if(!right) dp[i][j+1][0] += (dp[i][j][0] + dp[i][j][2]);
            if(!down) dp[i+1][j][1] += (dp[i][j][1] + dp[i][j][2]);
            if(!dia) dp[i+1][j+1][2] += (dp[i][j][0] + dp[i][j][1] + dp[i][j][2]);
        }
    }
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    return 0;
}
