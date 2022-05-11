#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

map<string, int> kind;
int number[100000]={0,};

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int k=0;
    for(int i=0;i<gems.size();i++){
        if(kind.find(gems[i]) == kind.end()){
            kind.insert({gems[i], k});
            k++;
        }
    }
    int l = 0;
    int r = 0;
    int total = kind.size();
    int check = 0;
    int ansl;
    int ansr;
    int max = 100000;
    while(r < gems.size()){
        while(check!=total){
            if(number[kind.find(gems[r])->second] == 0){
                number[kind.find(gems[r])->second]++;
                check++;
                r++;
            }
            else {
                r++;
            }
        }
        while(check==total){
            if(number[kind.find(gems[l])->second] == 1){
                number[kind.find(gems[l])->second]--;
                check--;
                l++;
            }
            else {
                l++;
            }
        }
        if(r-l < max){
            ansl = l;
            ansr = r;
        }
    }
    answer.push_back(ansl+1);
    answer.push_back(ansr+1);
    return answer;

}
