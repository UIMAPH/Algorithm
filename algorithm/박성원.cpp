#include<iostream>
#include<string>
#include<algorithm>

using namespace std;




string arr[16];
int num[16];
string seatNum[16];
int dp[400000][101] = {0,};

int n,k;

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}


void cal(string& temp, int i){
    int ret = 0;
    for(int j = 0;j<temp.size();j++){
        ret += temp[j] - '0';
        ret %= k;
        ret *= 10;
    }
    num[i] = ret/10;
    
}

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    for(int i=0;i<n;i++){
        cal(arr[i],i);
    }
}

int calSeatNumber(int x){
    int ans=0;
    while(x){
        x/=10;
        ans++;
    }
    return ans;
}



void sol(){
    for(int cur=0;cur<(1<<n);cur++){
        for(int i=0;i<n;i++){
            if((cur&(1<<i))==0){
                int nextProcess = cur|(1<<i);
                for(int j=0;j<n;j++){
                    int addNum = ((j%k)*(calSeatNumber(j)%k))+(num[i]%k);
                    dp[nextProcess][addNum] += dp[cur][j];
                }
            }
        }
    }
}




void init(){
    for(int i=0;i<n;i++){
        dp[1<<i][num[i]] = 1;
    }
}

long long fact(int i){
    int temp=1;
    for(int j=1;j<=i;j++) temp*=j;
    return temp;
}



int main(){
    input();
    init();
    sol();
    long long a = dp[(1<<n)-1][0];
    long long b = fact(n);
    long long gc = gcd(a,b);
    cout<<a/gc<<"/"<<b/gc;
    
    }
