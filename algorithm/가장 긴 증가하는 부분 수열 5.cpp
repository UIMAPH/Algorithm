#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100002];
int n,m;
vector<int> tree[1000];


void makeTree(int start, int end, int index){
    if(start == end ) return;
    for(int i=0;i<end-start+1; i++){
        tree[index].push_back(arr[start+i]);
    }
    sort(tree[index].begin(),tree[index].end());
    makeTree(start, (start+end)/2, index*2);
    makeTree((start+end)/2+1, end, index*2+1);
}

int solve(int start,int end, int nowStart, int nowEnd, int number){
    int tmp = tree[]
    
    
}


int search(int start,int end, int nowStart, int nowEnd, int number, int k){
    if(start<=nowStart and end>=nowEnd){
        
    }
    else if(nowStart>end or nowEnd<start){
        
    }
    else {
        
    }
}


void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
    }
    
    while(--m){
        int tmpStart, tmpEnd, tmpK;
        cin>>tmpStart>>tmpEnd>>tmpK;
        cout<<solve(tmpStart,tmpEnd,tmpK);
    }
}




int main(){
    input();
    
}
