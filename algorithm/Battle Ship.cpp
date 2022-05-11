
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int limit);
extern void play();

static int board[10][10];

#define MISS        0
#define CARRIER        1
#define BATTLESHIP    2
#define CRUISER        3
#define SUBMARINE    4
#define DESTROYER    5

static int hit;
static const int len[5] = { 5, 4, 3, 3, 2 };

#define MAX_CALLCOUNT    10000

static int callcount;
static int limit;

int fire(int r, int c)
{
    if (r < 0 || r > 9 || c < 0 || c > 9 || callcount >= MAX_CALLCOUNT)
    {
        callcount = MAX_CALLCOUNT;
        return 0;
    }
    
    ++callcount;
    
    int ret = board[r][c];
    
    if (board[r][c] > 0) --hit;
    board[r][c] = 0;
    
    return ret;
}

static int seed;

static int pseudo_rand()
{
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7fff;
}

static bool check(int r, int c, int d, int l)
{
    if (d == 1)
    {
        for (int m = 0; m < l; ++m)
            if (board[r][c + m] > 0)
                return false;
        return true;
    }
    else
    {
        for (int m = 0; m < l; ++m)
            if (board[r + m][c] > 0)
                return false;
        return true;
    }
}

static void doarrangment()
{
    for (int r = 0; r < 10; ++r)
    for (int c = 0; c < 10; ++c)
        board[r][c] = 0;
    
    for (int k = 0; k < 5; ++k)
    {
        while(1)
        {
            int r, c, d;
            
            d = pseudo_rand() % 2;
            if (d == 1)
            {
                r = pseudo_rand() % 10;
                c = pseudo_rand() % (10 - len[k] + 1);
                if (check(r, c, d, len[k]))
                {
                    for (int l = 0; l < len[k]; ++l)
                        board[r][c + l] = k + 1;
                    break;
                }
            }
            else
            {
                r = pseudo_rand() % (10 - len[k] + 1);
                c = pseudo_rand() % 10;
                if (check(r, c, d, len[k]))
                {
                    for (int l = 0; l < len[k]; ++l)
                        board[r + l][c] = k + 1;
                    break;
                }
            }
        }
    }
}

int main()
{
    int TC;
    
    //freopen("sample_input.txt", "r", stdin);

    setbuf(stdout, NULL);
    scanf("%d", &TC);

    int totalscore = 0, totalcallcount = 0;
    for (int testcase = 1; testcase <= TC; ++testcase)
    {
        int score = 100, callcount4tc = 0;
        
        scanf("%d %d", &seed, &limit);
        
        init(limit);

        for (int game = 0; game < 10; ++game)
        {
            doarrangment();
        
            hit = 0;
            for (int k = 0; k < 5; ++k)
                hit += len[k];
        
            callcount = 0;
            play();

            if (hit != 0)
                callcount = MAX_CALLCOUNT;
            
            if (callcount > limit)
                score = 0;

            callcount4tc += callcount;
        }
        
        printf("#%d %d %d\n", testcase, score, callcount4tc);

        totalscore += score;
        totalcallcount += callcount4tc;
    }

    printf("total score = %d, total callcount = %d\n", totalscore / TC, totalcallcount);
    return 0;
}

#define MISS        0
#define CARRIER        1
#define BATTLESHIP    2
#define CRUISER        3
#define SUBMARINE    4
#define DESTROYER    5

#include<utility>
#include<queue>
#include<map>
#include<vector>
#include<iostream>
using namespace std;

int arr[11][11];
vector<pair<int, int>> rc[6];
int sizerc[6]={0,};
int diry[4]={-1,0,1,0};
int dirx[4]={0,-1,0,1};
int checkship[6];


extern int fire(int r, int c);



void init(int limit) {
    checkship[0] = 0;
    checkship[1] = 5;
    checkship[2] = 4;
    checkship[3] = 3;
    checkship[4] = 3;
    checkship[5] = 2;
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<6;i++){
        rc[i].clear();
        sizerc[i]=0;
    }
}

bool checkl(int x){
    return (x>=0 and x<=9);
}

void found(){
    for(int i=1;i<=5;i++){
        int dir = 0;
        for(int j=0;j<rc[i].size()-1;j++){
            int y = rc[i][j].first;
            int x = rc[i][j].second;
            int ny = rc[i][j+1].first;
            if(y==ny){
                dir = 1;
                fire(y,x+1);
                arr[y][x+1]=i;
            } else{
                dir = 2;
                fire(y+1,x);
                arr[y+1][x]=i;
            }
        }
        switch (checkship[i]) {
            case 5:
                if(rc[i].size()==2){
                    if(dir == 1){
                        arr[rc[i][0].first][rc[i][0].second-1] = arr[rc[i][0].first][rc[i][0].second-1] ? arr[rc[i][0].first][rc[i][0].second-1] : fire(rc[i][0].first,rc[i][0].second-1);
                        arr[rc[i].back().first][rc[i].back().second+1]= arr[rc[i].back().first][rc[i].back().second+1] ? arr[rc[i].back().first][rc[i].back().second+1] : fire(rc[i].back().first,rc[i].back().second+1);
                    } else{
                        arr[rc[i][0].first-1][rc[i][0].second] = arr[rc[i][0].first-1][rc[i][0].second] ? arr[rc[i][0].first-1][rc[i][0].second] : fire(rc[i][0].first-1,rc[i][0].second);
                        arr[rc[i].back().first+1][rc[i].back().second] = arr[rc[i].back().first+1][rc[i].back().second] ? arr[rc[i].back().first+1][rc[i].back().second] :fire(rc[i].back().first+1,rc[i].back().second);
                    }
                }
                break;
            case 4:
                if(dir == 1){
                    if(checkl(rc[i][0].second-1)){
                        arr[rc[i][0].first][rc[i][0].second-1] =  arr[rc[i][0].first][rc[i][0].second-1] ? arr[rc[i][0].first][rc[i][0].second-1] :fire(rc[i][0].first,rc[i][0].second-1);
                        if(arr[rc[i][0].first][rc[i][0].second-1] == i) break;
                    }
                    arr[rc[i].back().first][rc[i].back().second+1]=arr[rc[i].back().first][rc[i].back().second+1]? arr[rc[i].back().first][rc[i].back().second+1]:fire(rc[i].back().first,rc[i].back().second+1);
                } else{
                    if(checkl(rc[i][0].first-1)){
                        
                       arr[rc[i][0].first-1][rc[i][0].second] = arr[rc[i][0].first-1][rc[i][0].second]? arr[rc[i][0].first-1][rc[i][0].second]:fire(rc[i][0].first-1,rc[i][0].second);
            
                        
                        if(arr[rc[i][0].first-1][rc[i][0].second]==i) break;
                    }
                    arr[rc[i].back().first+1][rc[i].back().second] = arr[rc[i].back().first+1][rc[i].back().second] ? arr[rc[i].back().first+1][rc[i].back().second] :fire(rc[i].back().first+1,rc[i].back().second);
                }
                break;
            case 3:
                if(rc[i].size() == 1){
                    if(checkl(rc[i][0].second-1) and checkl(rc[i][0].second+1)){
                        arr[rc[i][0].first][rc[i][0].second-1] = arr[rc[i][0].first][rc[i][0].second-1] ? arr[rc[i][0].first][rc[i][0].second-1] : fire(rc[i][0].first,rc[i][0].second-1);
                        if(arr[rc[i][0].first][rc[i][0].second-1]==i) {
                            arr[rc[i][0].first][rc[i][0].second+1] = arr[rc[i][0].first][rc[i][0].second+1]?arr[rc[i][0].first][rc[i][0].second+1]:fire(rc[i][0].first,rc[i][0].second+1);
                            break;
                        }
                    }
                    if(checkl(rc[i][0].first-1) and checkl(rc[i][0].first+1)){
                        arr[rc[i][0].first-1][rc[i][0].second] = arr[rc[i][0].first-1][rc[i][0].second] ?arr[rc[i][0].first-1][rc[i][0].second] :fire(rc[i][0].first-1,rc[i][0].second);
                        arr[rc[i][0].first+1][rc[i][0].second] = arr[rc[i][0].first+1][rc[i][0].second]? arr[rc[i][0].first+1][rc[i][0].second]: fire(rc[i][0].first+1,rc[i][0].second);
                    }
                }
                break;
            case 2:
                if(checkl(rc[i][0].second-1))arr[rc[i][0].first][rc[i][0].second-1] = arr[rc[i][0].first][rc[i][0].second-1]?arr[rc[i][0].first][rc[i][0].second-1]:fire(rc[i][0].first,rc[i][0].second-1);
                if(arr[rc[i][0].first][rc[i][0].second-1]==i) break;
                if(checkl(rc[i][0].second+1))arr[rc[i].back().first][rc[i].back().second+1]=arr[rc[i].back().first][rc[i].back().second+1]?arr[rc[i].back().first][rc[i].back().second+1]:fire(rc[i].back().first,rc[i].back().second+1);
                if(arr[rc[i][0].first][rc[i][0].second+1]==i) break;
                if(checkl(rc[i][0].first-1))arr[rc[i][0].first-1][rc[i][0].second] = arr[rc[i][0].first-1][rc[i][0].second]?arr[rc[i][0].first-1][rc[i][0].second]:fire(rc[i][0].first-1,rc[i][0].second);
                if(arr[rc[i][0].first-1][rc[i][0].second]==i) break;
                if(checkl(rc[i][0].first+1))arr[rc[i].back().first+1][rc[i].back().second] = arr[rc[i].back().first+1][rc[i].back().second]?arr[rc[i].back().first+1][rc[i].back().second]:fire(rc[i].back().first+1,rc[i].back().second);
                break;
        }
        
    }
}



void play(){
    checkship[0] = 0;
    checkship[1] = 5;
    checkship[2] = 4;
    checkship[3] = 3;
    checkship[4] = 3;
    checkship[5] = 2;
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<6;i++){
        rc[i].clear();
        sizerc[i]=0;
    }
    int breakpoint=0;
    int term = 2;
    for(int i=0;i<=9;i++){
        if(rc[5].size()==1){
            term = 3;
            if(rc[4].size()>=2 and rc[3].size()>=2){
                term=4;
                if(rc[2].size()>=2){
                    term=5;
                    if(rc[1].size()>=3){
                        break;
                    }
                }
            }
        }
        for(int j = i % term; j<=9; j+=term){
            int temp = fire(i,j);
            arr[i][j]=temp;
            if(temp!=0){
                rc[temp].push_back(make_pair(i, j));
                breakpoint++;
            }
            if(breakpoint>=10) break;
        }
    }
    found();
}

