#include <string>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;
pair<int, int>xy[10];
pair<int, int>l = make_pair(1,4);
pair<int, int>r = make_pair(3,4);


int cal(int dest, pair<int, int> start){
    return abs(xy[dest].first - start.first) + abs(xy[dest].second - start.second);
}


string solution(vector<int> numbers, string hand) {
    string answer = "";
    int num = 1;
    for(int i = 1;i<=3;i++){
        for(int j=1;j<=3;j++){
            xy[num] = make_pair(j, i);
            num++;
        }
    }
    xy[0] = make_pair(2, 4);
    for(int i=0;i<numbers.size();i++){
        if(numbers[i] == 1 or numbers[i] == 4 or numbers[i] == 7){
            answer.push_back('L');
            l = xy[numbers[i]];
        }
        else if(numbers[i] == 3 or numbers[i] == 6 or numbers[i] == 9){
            answer.push_back('R');
            r = xy[numbers[i]];
        }
        else {
            if (cal(numbers[i],l) > cal(numbers[i],r)){
                answer.push_back('R');
                r = xy[numbers[i]];
            }
            else if(cal(numbers[i],l) < cal(numbers[i],r)){
                answer.push_back('L');
                l = xy[numbers[i]];
            }
            else if(hand[0] == 'r'){
                answer.push_back('R');
                r = xy[numbers[i]];
            }
            else {
                answer.push_back('L');
                l = xy[numbers[i]];
            }
        }
    }
    return answer;
}
