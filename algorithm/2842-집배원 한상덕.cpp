#include <iostream>
#include <cmath>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n,small=100000000,big=-1;
vector<pair<int, pair<int, int>>> pq;
char arr[51][51];
int dirx[8] = {0,0,-1,1,-1,-1,1,1};
int diry[8] = {-1,1,0,0,-1,1,-1,1};
int height[51][51];
pair<int, int> start;
int house = 0;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b){
    return a.first > b.first;
}


void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>height[i][j];
            if(arr[i][j] == 'K' or arr[i][j] == 'P'){
                if(arr[i][j] == 'P') start = {i,j};
                else house++;
                if(height[i][j] > big) big = height[i][j];
                if(height[i][j] < small) small = height[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == '.'){
                if(height[i][j] > big) pq.push_back({abs(height[i][j]-big),{i,j}});
                else if(height[i][j] < small) pq.push_back({abs(height[i][j]-small),{i,j}});
            }
        }
    }
    sort(pq.begin(),pq.end(),cmp);
}
bool isSize(int i,int j){
    return i<n and i>=0 and j<n and j>=0;
}
queue<pair<int,int>> check;
bool visit[51][51];

bool cango(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j] = false;
        }
    }
    check.push({start.first,start.second});
    visit[start.first][start.second]=true;
    int temp = house;
    while (!check.empty()) {
        pair<int,int> p = check.front();
        check.pop();
        if(arr[p.first][p.second] == 'K') temp--;
        if(temp == 0) break;
        for(int i=0;i<8;i++){
            if(isSize(p.first+diry[i], p.second+dirx[i]) and !visit[p.first+diry[i]][p.second+dirx[i]] and height[p.first+diry[i]][p.second+dirx[i]] != -1){
                visit[p.first+diry[i]][p.second+dirx[i]] = true;
                check.push({p.first+diry[i],p.second+dirx[i]});
            }
        }
    }
    return temp == 0;
}

int solve(){
    for(int i=0;i<pq.size();i++){
        int origin = height[pq[i].second.first][pq[i].second.second];
        height[pq[i].second.first][pq[i].second.second] = -1;
        if(cango()) continue;
        else {
            height[pq[i].second.first][pq[i].second.second] = origin;
            if (origin < small) small = origin;
            else if (origin > big) big = origin;
        }
    }
    return big-small;
}


int main(){
    input();
    cout<<solve();
}
