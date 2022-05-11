#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000];
int temp[1000];

int find(int x,int t){
    for(int i=0;i<t;i++){
        arr[i]=x;
        return i;
    }
    return 0;
}



int main(){
    int time;
    cin>>time;
    for(int i=0;i<time;i++){
        cin>>arr[i];
        temp[i]=arr[i];
    }
    sort(temp,temp+time);
    int ans=0;
    for(int k=0;k<time;k++){
        int sol=999999999;
        int x=0;
        int al=0;
        for(int i=0;i<time;i++){
            if(temp[i]==arr[i]){
                continue;
            }
            if(temp[i]+arr[i]<sol){
                sol=temp[i]+arr[i];
                x=i;
                al=sol;
            }
        }
        int cute=0;
        for(int i=0;i<time;i++){
            if(temp[x]==arr[i]){
                cute=i;
            }
        }
        if(al==time-1){break;}
        ans+=al;
        int ttemp=arr[cute];
        arr[cute]=arr[x];
        arr[x]=ttemp;
    }

    cout<<ans;
    
}
