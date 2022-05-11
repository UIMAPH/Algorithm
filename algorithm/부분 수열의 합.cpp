#include<iostream>
using namespace std;

int arr[21];
int counnt=0;
int goal;

void chang(int x,int time,int pass){

    if(arr[x]+pass==goal and x!=0) counnt++;
    for(int i=x+1;i<=time;i++){
        chang(i, time, arr[x]+pass);
    }
    
}

int main(){
    int time;
    cin>>time>>goal;
    arr[0]=0;
    for(int i=1;i<=time;i++){
        cin>>arr[i];
    }
    chang(0,time,0);
    cout<<counnt;
}
