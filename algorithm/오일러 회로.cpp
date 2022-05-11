#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int n;
stack<int> s;
int arr[1002][1002];
int nxt[1002];
int check[1002];

void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            if(arr[i][j] > 0){
                check[i] += arr[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        nxt[i]=1;
    }
}

bool checkEvenNumber(){
    int zero;
    for(int i=1;i<=n;i++){
        if(check[i] % 2 == 1) return false;
        else if(check[i]==0) zero++;
    }
    if(zero==n) return false;
    return true;
}

void dfs(int x){
    if(check[x] > 0){
        for(int& i=nxt[x];i<=n;i++){
            if(arr[i][x] > 0){
                check[i]--;
                check[x]--;
                arr[i][x]--;
                arr[x][i]--;
                dfs(i);
            }
            //nxt[x]++;
        }
    }
    cout<<x<<" ";
}

int main(){
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    input();
    if(checkEvenNumber()){
        dfs(1);
    }else{
        cout<<"-1";
    }
}
