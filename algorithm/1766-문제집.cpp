#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> arr[32001];
priority_queue<int> pq;
int reArr[32001];
vector<int> temp;
int n,t;


int main(){
    cin>>n>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        arr[a].push(b);
        reArr[b] = a;
    }
    for(int i=0;i<n;i++){
        if(reArr[i] == 0){
            temp.push_back(i);
        }
    }
    for(int i=0;temp.size();i++){
        cout<<temp[i]<< " ";
        while(!arr[temp[i]].empty()){
            if(arr[temp[i]].top() < i){
                cout<<arr[temp[i]].top()<<" ";
                arr[temp[i]].pop();
            } else break;
        }
    }
}

