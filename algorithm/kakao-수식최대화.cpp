#include <string>
#include <vector>
#include <stdlib.h>


using namespace std;

char arr[3] = {'-','+','*'};
bool flag[3];

bool isnum(char t){
    return t>='0' or t<='9';
}

string cal(int num, string temp){
    for(int i = 0;i<temp.size();i++){
        if(temp[i] == arr[num]){
            int l = i-1;
            for(; isnum(temp[l]);l--);
            l++;
            int left = atoi(&temp[l]);
            int right = atoi(&temp[i+1]);
            int tempans;
            switch (arr[num]) {
                case '-':
                    tempans = left - right;
                    break;
                case '+':
                    tempans = left + right;
                    break;
                case '*':
                    tempans = left * right;
                    break;
                default:
                    break;
            }
        string cute = itoa
            
        
            
        }
    }
}

void makeSoon(int num, string temp){
    flag[0] = true;
    int i=0;
    for(;i<3;i++){
        if(flag[i] == false){
            makeSoon(i, cal(num,temp));
        }
    }
    if(i==3){
        temp
    }
}


long long solution(string expression) {
    long long answer = 0;
    
    
     
    return answer;
}


