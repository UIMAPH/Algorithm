#include<iostream>
#include<utility>
using namespace std;
char arr[11][11];
pair<int,int> red;
pair<int,int> blue;
int n;
int ans;

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='R') red = make_pair(i, j);
            else if(arr[i][j]=='B') blue = make_pair(i, j);
        }
    }
}


//1 up 2 down 3 left 4 right
//1 red 0 blue
bool move(int direction,int color){
    //1은 지나가던 길에 파랑이 있는경우
    //2는 지나가던 길에 빨강이 있는경우
    //0은 아무것도 없음
    int check = 0;
    //checkAns 은 빨간이 들어 가면 참으로 바뀌고 그상태에서 파랑이 안드러가면 리턴을 반환
    bool checkAns = false;
    //red
    if(color){
        int redY = red.first;
        int redX = red.second;
        switch(direction){
            case 1:
                for(int i = redY;i>=0;i--){
                    if(arr[i][redX]=='.'){
                        continue;
                    }else if(arr[i][redX]=='B'){
                        check = 1;
                    }else if(arr[i][redX]=='0'){
                        checkAns = true;
                    }
                    else{
                        if(check==1){
                            red = make_pair(i+1, redX);
                        }
                    }
                }
                break;
            case 2:
                for(int i = redY;i<n;i++){
                    if(arr[i][redX]=='.'){
                        continue;
                    }else if(arr[i][redX]=='B'){
                        check = 1;
                    }else if(arr[i][redX]=='0'){
                        checkAns = true;
                    }
                    else{
                        if(check==1){
                            red = make_pair(i-1, redX);
                        }
                    }
                }
                break;
            case 3:
                for(int i = redX;i>=0;i--){
                    if(arr[redY][i]=='.'){
                        continue;
                    }else if(arr[redY][i]=='B'){
                        check = 1;
                    }else if(arr[redY][i]=='0'){
                        checkAns = true;
                    }
                    else{
                        if(check==1){
                            red = make_pair(redY,i+1);
                        }
                    }
                }
                break;
            case 4:
                for(int i = redX;i<n;i++){
                    if(arr[redY][i]=='.'){
                        continue;
                    }else if(arr[redY][i]=='B'){
                        check = 1;
                    }else if(arr[redY][i]=='0'){
                        checkAns = true;
                    }
                    else{
                        if(check==1){
                            red = make_pair(redY,i-1);
                        }
                    }
                }
                break;
            default:
                break;
        }
    }
    //blue
    else{
        int blueY = blue.first;
        int bluex = blue.second;
        switch(direction){
            case 1:
                for(int i = blueY;i>=0;i--){
                    if(arr[i][blueX]=='.'){
                        continue;
                    }else if(arr[i][blueX]=='R'){
                    }else if(arr[i][blueX]=='0'){
                    
                    }
                    else{
                        if(check==1){
                            red = make_pair(i+1, redX);
                        }
                    }
                }
                break;
            case 2:
                for(int i = redY;i<n;i++){
                    if(arr[i][redX]=='.'){
                        continue;
                    }else if(arr[i][redX]=='B'){
                        check = 1;
                    }else if(arr[i][redX]=='0'){
                        checkAns = true;
                    }
                    else{
                        if(check==1){
                            red = make_pair(i-1, redX);
                        }
                    }
                }
                break;
            case 3:
                for(int i = redX;i>=0;i--){
                    if(arr[redY][i]=='.'){
                        continue;
                    }else if(arr[redY][i]=='B'){
                        check = 1;
                    }else if(arr[redY][i]=='0'){
                        checkAns = true;
                    }
                    else{
                        if(check==1){
                            red = make_pair(redY,i+1);
                        }
                    }
                }
                break;
            case 4:
                for(int i = redX;i<n;i++){
                    if(arr[redY][i]=='.'){
                        continue;
                    }else if(arr[redY][i]=='B'){
                        check = 1;
                    }else if(arr[redY][i]=='0'){
                        checkAns = true;
                    }
                    else{
                        if(check==1){
                            red = make_pair(redY,i-1);
                        }
                    }
                }
                break;
            default:
                break;
        }
        
        
    }
    for(int t=0;t<10;t++){
        for(int i=1;i<=4;i++){
            move(i,1);
            move(i,0);
        }
    }
    return true;
}

void solve(){
}


int main(){
    
}
