#include<iostream>
using namespace std;

int separateNumber(int number){
    int temp=number;
    int sol=0;
    for(int i=0;temp>=1;i++){
        sol+=temp%10;
        temp/=10;
    }
    return sol;
}

int main(){
    int number;
    bool check=true;
    cin>>number;
    for(int i=64;i>0;i--){
        if(i==separateNumber(number-i)){
            cout<<number-i;
            check=false;
            break;
        }
    }
    if(check) cout<<0;
}

int origin = cur;
while(cur>=0 and story[i] != wishWord[cur]) {
    if(cur==0){
        step_one.push_back('1');
        break;
    }
    cur = prefix_posfix_arr[cur-1];
    char temp = ('0' + (origin - cur));
    step_one.push_back(temp);
    origin = cur;
}
if(story[i] == wishWord[cur]){
    if(cur==wishWord.size()-1){
        ans.push_back(i-wishWord.size()+1);
        cur = prefix_posfix_arr[cur];
        char temp = ('0' + (wishWord.size() - cur));
        if(i!=story.size()-1) step_one.push_back(temp);
    } else cur++;
}
