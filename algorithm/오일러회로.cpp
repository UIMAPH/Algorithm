#include <iostream>
#include <stack>

using namespace std;

bool arr[1001][1001];
bool visited[1001][1001];
stack<int> s;
int n;
int stopSign = false;

void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp = 0;
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
            visited[i][j]=arr[i][j];
            if(arr[i][j]){
                temp++;
            }
        }
        if(temp%2 == 1){
            stopSign = true;
        }
    }
}
void solve(int x){
    for(int i=1;i<=n;i++){
        if(arr[x][i]==1){
          
            arr[x][i]=0;
            arr[i][x]=0;
            cout<<x<<" ";
            solve(i);
        }
    }
}
/*
 
 */



int main(){
    input();
    if(stopSign){
        cout<<-1;
        
    }else{
        solve(1);
        cout<<1;
    }
}
