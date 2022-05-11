
// Title : 범인 색출, Score 를 최소화하라
// 20 초
// stack Memory : 1M  (전역 변수 사용 금지)

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
#include <random>
#include <vector>
#include <iostream>
using namespace std;

extern void investigate();

const int MAX_NUM = 1000000;
static int SCORE, TOTAL_SCORE, TOTAL_TIME;
static char citizen[MAX_NUM];
static char room[MAX_NUM];
static char arrested[MAX_NUM];

void putIn(int n, int a)
{
   if (n < 0 || n >= MAX_NUM) return;
   if (a < 0 || a >= MAX_NUM) return;
   room[n] |= citizen[a];
}

int closeDoor(int n)
{
   SCORE += 1;
   if (n < 0 || n >= MAX_NUM) return 0;
   return room[n];
}

void clearRoom() {
   for (int i = 0; i < MAX_NUM; i++) room[i] = 0;
}

void arrest(int a)
{
   SCORE += 10;
   if (a < 0 || a >= MAX_NUM) return;
   if(citizen[a] == 0) SCORE += 10000;
   arrested[a] = 1;
}


static unsigned long long seed = 113;
std::random_device rd;
std::mt19937 gen(seed);
std::uniform_int_distribution<int> dis(0, MAX_NUM - 1);
int cute=0;
void init() {
   SCORE = 0;
   for (int i = 0; i < MAX_NUM; i++) {
      citizen[i] = 0; room[i] = 0; arrested[i] = 0;
   }
   int j;
   for (int i = 0; i < MAX_NUM / 1000; i++) {
      j = dis(gen);
      if (citizen[j] == 1) {
         i--;
         continue;
      }
      citizen[j] = 1;
   }
}


int main()
{
   int TC;
   TOTAL_SCORE = TOTAL_TIME = 0;
   //freopen("sample_input.txt", "r", stdin);
   scanf("%d", &TC);
   for (int t = 1; t <= TC; t++) {
      init();
      investigate();
       for (int i = 0; i < MAX_NUM; i++) if (citizen[i] == 1 && arrested[i] == 0) SCORE += 0;//90000;
      if (SCORE < 86400) printf("#%d 100 %d\n", t, SCORE);
      else printf("#%d 0 0\n", t);
      TOTAL_SCORE += SCORE;
      
   }
   printf("TOTAL SCORE : %d\n", TOTAL_SCORE);

}

extern void putIn(int n, int a);
extern int closeDoor(int n);
extern void arrest(int n);
extern void clearRoom();



bool check(int start,int end,int num, int& idx){
    //cout<<start<<" "<<end;
    if(start+1 == end){
       
        arrest(start);
        return true;
    }
    if(idx == 0){}
    else if((end-start) % 5 == 0) num = 5;
    else if((end-start) % 4 == 0) num = 4;
    else if (((end-start) % 4 != 0)) num = 2;
    double temp = (end-start) / num;
    //cout<<" "<<temp<<"\n";
    for(int i=0;i<num;i++){
        idx++;
        for(double j = start+(temp*i) ; j < start + (temp * (i+1)) ; j++){
            putIn(idx, j);
        }
        if(closeDoor(idx)){
            check(start+(temp*i), start + (temp * (i+1)), num, idx);
        }
    }
    return true;
}

void investigate() {
    int id = 0;
    clearRoom();
    check(0,MAX_NUM,1000,id);
  
}

