#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int n;
priority_queue<int> small;
priority_queue<int, vector<int>, greater<int>> big;
 

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(small.size()==0){
            small.push(temp);
        }else{
            if(small.size() > big.size()){
                big.push(temp);
            }else{
                small.push(temp);
            }
            if(small.top()>(big.top())){
                int temp1 = small.top();
                int temp2 = big.top();
                small.pop();
                big.pop();
                small.push(temp2);
                big.push(temp1);
            }
        }
        cout<<small.top()<<"\n";
    }
}

int main(){
    solve();
}
