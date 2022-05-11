#include <iostream>
#include <algorithm>

using namespace std;

bool arr[11][11];
int dirX[5]={0,0,0,-1,1};
int dirY[5]={0,1,-1,0,0};
bool arr_tmp[11][11];
int ans = 101;

void show(){
    cout<<"------------------------------\n";
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
    cout<<"----------------------------\n";
}

bool outRange(int y,int x){
    return (y>-1 and y<10 and x>-1 and x<10);
}

void click(int y,int x){
    for(int i=0;i<5;i++){
        if(outRange(y+dirY[i], x+dirX[i])){
            arr[y+dirY[i]][x+dirX[i]] = !arr[y+dirY[i]][x+dirX[i]];
        }
    }
}

void input(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            char temp;
            cin>>temp;
            if(temp == '#'){
                arr[i][j] = false;
                arr_tmp[i][j]=false;
            }
            else{
                arr[i][j] = true;
                arr_tmp[i][j] = true;
            }
        }
    }

}

void init(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            arr[i][j]=arr_tmp[i][j];
        }
    }
}

bool check(){
    int temp = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(!arr[i][j]){
                temp++;
            }
        }
    }
    return temp == 100;
}

void solve(){
    for(int step=0;step<(1<<10);step++){
        int cnt = 0;
        init();
        for(int i=0;i<10;i++){
            if(step & (1<<i)){
                cnt++;
                click(0,i);
            }
        }
        for(int y = 1;y<10;y++){
            for(int x=0;x<10;x++){
                if(arr[y-1][x]){
                    cnt++;
                    click(y, x);
                }
            }
        }
        if(check()){
            ans = min(ans,cnt);
        }
    }
}

int main(){
    input();
    solve();
    cout<< (ans>100 ? -1 : ans);
}
