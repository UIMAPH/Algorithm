#include <string>
#include <vector>
#include <iostream>

using namespace std;
struct node{
    int fx;
    int fy;
    int sx;
    int sy;
    int value;
};
node arr[10001];

int search(int num, int fy,int fx, int sy, int sx){
    node temp = arr[num];
    if(fx==sx and fy==sy) return temp.value;
    if(fx <= temp.fx/2 and fy <= temp.sy/2 ) return temp.value + search(num*4 + 1, fy, fx, sy/2, sx/2);
    if(fx >= temp.fx/2 and fy <= temp.sy/2 ) return temp.value + search(num*4 + 2, fy, fx/2, sy/2, sx);
    if(fx >= temp.fx/2 and fy >= temp.sy/2 ) return temp.value + search(num*4 + 3, fy/2, fx, sy, sx/2);
    if(fx <= temp.fx/2 and fy >= temp.sy/2 ) return temp.value + search(num*4 + 4, fy/2, fx/2, sy, sx);
    return 0;
}

void update(int value,int num, int fy,int fx, int sy, int sx){
    node temp = arr[num];
    if(temp.fx == fx and temp.fy == fy and temp.sx == sx and temp.sy == sy){
        temp.value += value;
        return;
    }
    if(fx <= temp.fx/2 and fy <= temp.sy/2 ) update(value, num*4 + 1, fy, fx, sy/2, sx/2);
    if(fx >= temp.fx/2 and fy <= temp.sy/2 ) update(value, num*4 + 2, fy, fx/2, sy/2, sx);
    if(fx >= temp.fx/2 and fy >= temp.sy/2 ) update(value, num*4 + 3, fy/2, fx, sy, sx/2);
    if(fx <= temp.fx/2 and fy >= temp.sy/2 ) update(value, num*4 + 4, fy/2, fx/2, sy, sx);
}

void make(int num, int fy,int fx, int sy, int sx){
    cout<<fy<<" "<<fx<<" "<<sy<<" "<<sx<<endl;
    if(fx >= sx or fy >= sy) return;
    arr[num].fy = fy;
    arr[num].fx = fx;
    arr[num].sx = sx;
    arr[num].sy = sy;
    make(num * 4 + 1,fy,fx,sy/2,sx/2);
    make(num * 4 + 2,fy,(fx+sx)/2,sy/2,sx);
    make(num * 4 + 3,(fy+sy)/2,fx,sy,sx/2);
    make(num * 4 + 4,(fy+sy)/2,(fx+sx)/2,sy,sx);
}


int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    make(0, 0, 0, board.size(), board[0].size());
    for(int i=0;i<skill.size();i++){
        update(skill[i][0]==1 ? skill[i][5] : -1 * skill[i][5] , 0, skill[i][1], skill[i][2], skill[i][3], skill[i][4]);
    }
    for(int i=0;i<board.size();i++){
        for(int j = 0;j<board[0].size();j++){
            if(board[i][j] - search(0,i,j,i,j)) answer++;
        }
    }
    return answer;
}
int main(){
    vector<vector<int>> f = {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}};
    vector<vector<int>> s = {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};
    cout<<solution(f, s);
}
/*
 00 44
 00 22
 03 24
 
 
 */
