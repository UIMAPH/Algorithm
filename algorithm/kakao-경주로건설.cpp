#include <string>
#include <algorithm>
#include <vector>
#include<iostream>

using namespace std;

//가로는 0 세로는 1
int cache[25][25][2];
bool flag[25][25];
int dirX[4]= {1,0,-1,0};
int dirY[4]={0,1,0,-1};
int length;
vector<vector<int>> temp;
int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};

bool checkSize(int y, int x){
    return y>=0 and y < length and x >= 0 and x < length;
}
void initCache(){
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            cache[i][j][0] = 2147483646;
            cache[i][j][1] = 2147483646;
        }
    }
}

//가로는 0 세로는 1
int dp(int y,int x, int dir){
    int& ret = cache[y][x][dir];
    if(ret != 2147483646) return ret;
    if(x==length-1 and y == length-1) return 0;
    flag[y][x] = true;
    for(int i = 0;i<4;i++){
        int nowDir = i  % 2 == 0? 0 : 1;
        if(checkSize(y+dirY[i],x+dirX[i])){
            if(flag[y+dirY[i]][x+dirX[i]] == false and temp[y+dirY[i]][x+dirX[i]] == 0 ){
                ret = min(ret, dp(y+dirY[i],x+dirX[i], nowDir) + (nowDir == dir ? 100 : 600));
            }
        }
    }
    flag[y][x] = false;
    return ret;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    length = board[0].size();
    initCache();
    temp = board;
    dp(0,0,0);
    dp(0,0,1);
    answer = min(cache[0][0][1],cache[0][0][0]);
    return answer;
}

