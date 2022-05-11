#include <string>
#include <vector>

using namespace std;
int dirx[4] = {0,0,-1,1};
int diry[4] = {-1,1,0,0};
vector<vector<string>> room;
int flag[5][5];

bool check(int y, int x){
    return x>=0 and x<5 and y>=0 and y<5;
}

bool find(int y, int x, int num){
    if (room[num][y][x] == 'P') return false;
    for(int i=0;i<4;i++){
        if (check(y+diry[i],x+dirx[i]) and !flag[y+diry[i]][x+dirx[i]]) find(y+diry[i],x+dirx[i],num);
    }
    return truel
}

int oneroom(vector<string> temp, int k){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(temp[i][j] == 'P'){
                find(i,j,k);
            }
        }
    }
    
    
    
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    
    
    room = places;
    return answer;
}
