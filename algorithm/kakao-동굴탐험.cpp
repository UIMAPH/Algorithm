#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;
struct room{
    int number = 0;
    room* parent;
};
vector<vector<int>> tree;
room arr[200000];
vector<vector<int>> ord;
int soon[200000];
stack<int>small;
stack<int>big;

void make(int n){
    for(int i=0; i < n ;i++){
        arr[tree[i][1]].parent = &arr[tree[i][0]];
    }
}
int counter = 1;

bool check(){
    for(int i=0;i<ord.size();i++){
        room first = arr[ord[i][0]];
        while(first.number != 0){
            cout<<first.parent->number<<"--------------\n";
            big.push(first.number);
            first = *first.parent;
        }
        room second = arr[ord[i][1]];
        while(first.number != 0){
            small.push(second.number);
            second = *second.parent;
        }
        for(int j=0;!big.empty();j++){
            int temp = big.top();
            if(soon[temp] < soon[small.top()]){
                soon[temp] = counter;
                counter++;
            }
            else return false;
            big.pop();
        }
        while(!small.empty()){
            soon[small.top()] = counter;
            counter++;
            small.pop();
        }
    }
    return true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for(int i=0;i<n;i++){
        arr[i].number = i;
    }
    tree = path;
    ord = order;
    make(n);
    answer = check();
    return answer;
}
int main() {
    vector<vector<int>> path = { {0,1} ,{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5} };
    vector<vector<int>> order = { {8, 5}, {6, 7}, {4, 1} };
    vector<vector<int>> path2 = { {8,1},{0,1},{1,2},{0,7},{4,7},{0,3},{7,5},{3,6}  };
    vector<vector<int>> order2 = { {4, 1}, {5, 2} };
    vector<vector<int>> path3 = { {0, 1}, {0, 3}, {0, 7}, {8, 1}, {3, 6}, {1, 2}, {4, 7}, {7, 5} };
    vector<vector<int>> order3 = { {4, 1}, {8, 7}, {6, 5} };
    solution(9, path, order);
}
