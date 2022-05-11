#include <iostream>
using namespace std;

int d,n;
int depth[300000];
int pizza[300000];
int ans[300000];


void input(){
    cin>>d>>n;
    for(int i=0;i<d;i++){
        cin>>depth[i];
    }
    for(int i=0;i<n;i++){
        cin>>pizza[i];
    }
}

int main(){
    //input();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    
}

class car{
    

};

class speed{
    
};

