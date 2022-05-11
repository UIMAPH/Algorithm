#include<iostream>
#include<cmath>

using namespace std;
bool arr[1000];


void check(int x,int y,int strike,int ball){
    int s=0;
    int b=0;
    int xxx=x;
    int yyy=y;
    for(int i=0;i<3;i++){
        if(xxx%10==yyy%10) s++;
        xxx/=10;
        yyy/=10;
    }
    int xx[3];
    int yy[3];
    xxx=x;
    yyy=y;
    
    for(int i=0;i<3;i++){
        xx[i]=xxx%10;
        xxx/=10;
    }
    for(int i=0;i<3;i++){
        yy[i]=yyy%10;
        yyy/=10;
    }
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            if(k!=i and xx[k]==yy[i]){
                b++;
                
            }
        }
    }
    if(strike!=s or ball!=b){
        arr[y]=false;
    }
}

void sibal(int a){
    int xx[3];
    int xxx=a;
    for(int i=0;i<3;i++){
        xx[i]=xxx%10;
        xxx/=10;
    }
    for(int i=0;i<3;i++){
        for(int k=0;k<3;k++){
            if((k!=i and xx[k]==xx[i] and arr[a]) or xx[k]==0){
                arr[a]=false;
               
            }
        }
    }
}



int main(){
    for(int i=111;i<1000;i++){
        arr[i]=true;
    }
    for(int i=111;i<1000;i++){
        sibal(i);
    }
    int testCase;
    cin>>testCase;
    while(testCase--){
        int number,st,ba;
        cin>>number>>st>>ba;
        for(int i=111;i<1000;i++){
            if(arr[i]){
                check(number,i,st,ba);
            }
        }
    }
    int sol=0;
    for(int i=111;i<1000;i++){
        if(arr[i]){
            sol++;
            
            
        }
    }
    cout<<sol;
}

