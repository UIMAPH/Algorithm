#include <iostream>
#include <utility>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>>arr;

int main(){
    int a,b;
    cin>>a>>b;
    for(int i= 0;i<a;i++){
        int c,d;
        cin>>c>>d;
        pair<int,int> temp=make_pair(c, d);
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    long long int k=0;
    long long int sol=0;
    for(int i=0;i<a;i++){
        if(k<arr[i].second){
            sol+=(long long)arr[i].second-k;
        }
        k=arr[i].second;
    }
    cout<<sol;
}
