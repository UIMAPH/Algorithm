#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int triple[46];
    for(int i=1;i<46;i++){
        triple[i]=(pow(i,2)+i)/2;
    }
    int testCase;
    cin>>testCase;
    while(testCase--){
        int testNumber;
        cin>>testNumber;
        bool check=false;
        for(int i=1;i<46;i++){
            for(int k=i;k<46;k++){
                for(int z=k;z<46;z++){
                    if(triple[i]+triple[k]+triple[z]==testNumber){
                        check=true;
                        break;
                    }
                }
                if(check) break;
            }
            if(check) break;
        }
        if(check) cout<<"1"<<"\n";
        else cout<<"0"<<"\n";
    }
}
