#include<iostream>
#include<string>
using namespace std;

int moveX[8]={-1,-1,-1,0,0,1,1,1};
int moveY[8]={1,0,-1,1,-1,1,0,-1};
string board[50];
 

int eatCandy(int x,int y,int size){
    int garo=0;
    int sero=0;
    for(int left=x;left>=0;left--){
        if(board[y][x]==board[y][left]) garo++;
        else break;
    }
    for(int right=x+1;right<size;right++){
        if(board[y][x]==board[y][right]) garo++;
        else break;
    }
    for(int down=y;down>=0;down--){
        if(board[y][x]==board[down][x]) sero++;
        else break;
    }
    for(int up=y+1;up<size;up++){
        if(board[y][x]==board[up][x]) sero++;
        else break;
    }
    return max(garo,sero);
}

int main(){
    int boardSize;
    cin>>boardSize;
    for(int i=0;i<boardSize;i++){
        cin>>board[i];
    }
    int sol=0;
    char temp;
    for(int i=0;i<boardSize;i++){
        for (int k=0; k<boardSize-1; k++) {
            temp=board[i][k];
            board[i][k]=board[i][k+1];
            board[i][k+1]=temp;
            sol=max(sol,max(eatCandy(k,i,boardSize),eatCandy(k+1,i,boardSize)));
            temp=board[i][k];
            board[i][k]=board[i][k+1];
            board[i][k+1]=temp;
        }
    }
    for(int i=0;i<boardSize;i++){
        for (int k=0; k<boardSize-1; k++) {
            temp=board[k][i];
            board[k][i]=board[k+1][i];
            board[k+1][i]=temp;
            sol=max(sol,max(eatCandy(i,k,boardSize),eatCandy(i,k+1,boardSize)));
            temp=board[k][i];
            board[k][i]=board[k+1][i];
            board[k+1][i]=temp;
        }
    }
    cout<<sol;
}
