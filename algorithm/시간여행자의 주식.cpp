
#include<queue>
#include<vector>

#include<iostream>
using namespace std;

struct sellorder {
    int num;
    int q;
    int price;
};

struct buyorder{
    int num;
    int q;
    int price;
};

struct comparesell{
    bool operator()(const sellorder& s1, const sellorder& s2) {
        if (s1.price == s2.price){
            if(s1.num > s2.num) return true;
            else return false;
        }
        return s1.price > s2.price;
    }
};
struct comparebuy{
    bool operator()(const buyorder& s1, const buyorder& s2) {
        if (s1.price == s2.price){
            if(s1.num > s2.num) return true;
            else return false;
        }
        return s1.price < s2.price;
    }
};
const int INF=1e9;
priority_queue<sellorder, vector<sellorder>, comparesell> sellq[6];
priority_queue<buyorder, vector<buyorder>, comparebuy> buyq[6];
int maxv[6]={0,};
int minv[6]={INF,};
bool canceld[2000001];

void updatev(int stock, int price){
    minv[stock] = minv[stock] > price ? price : minv[stock];
    maxv[stock] = maxv[stock] > price - minv[stock] ? maxv[stock] : price - minv[stock];
}


void init(){
    for(int i=0;i<6;i++){
        while(!sellq[i].empty()) sellq[i].pop();
        while(!buyq[i].empty()) buyq[i].pop();
    }
    for(int i=0;i<6;i++){
        minv[i] =INF;
        maxv[i] = 0;
    }
    for(int i=0;i<2000001;i++){
        canceld[i] = false;
    }
}


int buy(int mNumber, int mStock, int mQuantity, int mPrice){
    int mq = mQuantity;
    while(!sellq[mStock].empty()){
        if(sellq[mStock].top().price <= mPrice){
            sellorder temp = sellq[mStock].top();
            if(canceld[temp.num]) {
                sellq[mStock].pop();
                continue;
            }
            updatev(mStock, temp.price);
            if(temp.q > mq){
                sellorder tmp = {temp.num, temp.q - mq, temp.price};
                sellq[mStock].push(tmp);
                mq = 0;
                sellq[mStock].pop();
                break;
            } else {
                mq -= temp.q;
                sellq[mStock].pop();
            }
        }
        else {
            break;
        }
    }
    if(mq>0){
        buyq[mStock].push({mNumber,mq,mPrice});
    }
    return mq;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice){
    int mq = mQuantity;
    while(!buyq[mStock].empty()){
        if(buyq[mStock].top().price >= mPrice){
            buyorder temp = buyq[mStock].top();
            if(canceld[temp.num]) {
                buyq[mStock].pop();
                continue;
            }
            updatev(mStock, temp.price);
            if(temp.q > mq){
                buyorder tmp = {temp.num, temp.q - mq, temp.price};
                buyq[mStock].push(tmp);
                mq = 0;
                buyq[mStock].pop();
                break;
            } else {
                mq -= temp.q;
                buyq[mStock].pop();
            }
        }
        else {
            break;
        }
    }
    if(mq>0){
        sellq[mStock].push({mNumber,mq,mPrice});
    }
    return mq;
}

void cancel(int mNumber) {
    canceld[mNumber] = 1;
}

int bestProfit(int mStock){
    return maxv[mStock];
}
