
#include<iostream>
#include<vector>
#include <utility>

using namespace std;

struct shark {
    int num;
    int speed;
    int dir;
    int size;
};


shark arr[101][101];
vector<pair<int, int>> sharklocation;
int r,c,m;


void input(){
    cin>>r>>c>>m;
    for(int i=0;i<m;i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        shark temp = {i,c,d,e};
        arr[a][b] = temp;
        sharklocation.push_back(make_pair(a, b));
    }
}


void solve(){
    for(int i=0;i<c;i++){
        
        
        
        
    }
}
void sharkmove(){
    for(int i=0;i<sharklocation.size();i++){
        shark now = arr[sharklocation[i].first][sharklocation[i].second];
        if(arr[sharklocation[i].first][sharklocation[i].second].size != 0){
            switch (now.dir) {
                case 1:
                    
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                
            }
            
        }
        
        
    }
    
}







int main(){
    
    
    
}
