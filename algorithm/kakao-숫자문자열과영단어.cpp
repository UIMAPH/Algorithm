#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string arr[10] = {"zero", "one","two","three","four","five","six","seven","eight","nine"};
map<string,int> num;
bool isnum(char temp){
    return temp >= '0' and temp <= '9';
}

int make(string temp){
    int ans = 0;
    for(int i=0;i<temp.size();i++){
        if(!isnum(temp[i])){
            string cute;
            int j;
            for(j = i;; j++){
                cute.push_back(temp[j]);
                cout<< cute<<" ";
                if(num.find(cute) != num.end()){
                    ans = ans * 10 + num.find(cute)->second;
                    cout << ans<<" ";
                    i=j;
                    break;
                }
            }
            cout<<endl;
        }
        else ans = ans * 10 + (temp[i]-'0');
    }
    return ans;
}

int solution(string s) {
    int answer = 0;
    for(int i=0;i<10;i++){
        num.insert({arr[i],i});
    }
    
    answer = make(s);
    return answer;
}

int main(){
    solution("23four5six7");
}
