#include<iostream>
using namespace std;
int inf = -999999999;

int main(){
    int chance;
    int present=0;
    int max=inf;
    cin>>chance;
    for(int i=0;i<chance;i++){
        int temp;
        cin>>temp;
        present+=temp;
        if(present>max) max = present;
        if(present<0) present=0;
    }
    cout<<max;
}
    

