#include<iostream>
using namespace std;

int separateNumber(int number){
    int temp=number;
    int sol=0;
    for(int i=0;temp>=1;i++){
        sol+=temp%10;
        temp/=10;
    }
    return sol;
}

int main(){
    int number;
    bool check=true;
    cin>>number;
    for(int i=64;i>0;i--){
        if(i==separateNumber(number-i)){
            cout<<number-i;
            check=false;
            break;
        }
    }
    if(check) cout<<0;
}
