#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;
pair<int, int> a;
pair<int, int> b;
vector<vector<int>> arr;
int dirx[4] = {0,0,-1,1};
int diry[4] = {-1,1,0,0};
int visit[7][7];
int who;
//0 a , 1 b

int mostFar(int x,int y){
    if(who){//a가호출
        
        
        
        
        
    }else{
        
    }
}
int mostClose(){
    
}

int play(int turn){
    if(who == 0 and turn == 0){
        
    }else if(who == 0 and turn == 1){
        
    }else if(who == 1 and turn == 0){
        
    }else if(who == 1 and turn == 1){
        
    }
}



int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    arr = board;
    a = {aloc[0],aloc[1]};
    b = {bloc[0],bloc[1]};
    who = abs(a.first - b.first) + abs(a.second - b.second);
    who = who % 2 == 0 ? 0 : 1;
    for(int i=0;i<67;i++){
        for(int j=0;j<7;j++){
            
        }
    }
    
    return answer;
}
