#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[9];
    int total=0;
    for(int i=0;i<9;i++){
        cin>>arr[i];
        total+=arr[i];
    }
    total-=100;
    int check=0;
    for(int i=0;i<9 and check!= 1;i++){
        for(int k=i+1;k<9 and check!=1;k++){
            if(arr[i]+arr[k]==total) {
                arr[i]=0;
                arr[k]=0;
                check=1;
            }
        }
    }
    sort(arr,arr+9);
    for(int i=2;i<9;i++){
        cout<<arr[i]<<"\n";
    }
    
    
}
