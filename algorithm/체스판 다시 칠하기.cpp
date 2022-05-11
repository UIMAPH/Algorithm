#include<iostream>
#include<string>
using namespace std;
string chess[50];

int repaintChess(int x,int y){
    int b=0;
    int w=0;
    for(int i=0;i<8;i++){
        for(int k=0;k<8;k++){
            if(k%2==0 and i%2==0 and chess[i+y][k+x]=='B'){
                b++;
            }
            else if(k%2!=0 and i%2==0 and chess[i+y][k+x]=='W'){
                b++;
            }
            else if(k%2==0 and i%2!=0 and chess[i+y][k+x]=='W'){
                b++;
            }
            else if(k%2!=0 and i%2!=0 and chess[i+y][k+x]=='B'){
                b++;
            }
        }
    }
    for(int i=0;i<8;i++){
        for(int k=0;k<8;k++){
            if(k%2==0 and i%2==0 and chess[i+y][k+x]=='W'){
                w++;
            }
            else if(k%2!=0 and i%2==0 and chess[i+y][k+x]=='B'){
                w++;
            }
            else if(k%2==0 and i%2!=0 and chess[i+y][k+x]=='B'){
                w++;
            }
            else if(k%2!=0 and i%2!=0 and chess[i+y][k+x]=='W'){
                w++;
            }
        }
    }
    //cout<<x<<" "<<y<<" "<<w<<" "<<b<<"\n";
    return min(w,b);
}

int main(){
    int ga,se;
    cin>>se>>ga;
    for(int i=0;i<se;i++){
        cin>>chess[i];
    }
    int sol=300;
    for(int i=0;i<=se-8;i++){
        for(int k=0;k<=ga-8;k++){
            sol=min(sol,repaintChess(k,i));
        }
    }
   cout<<sol;
}
