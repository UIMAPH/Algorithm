#include <string>
#include <vector>
#include <cmath>

using namespace std;
int temp[1000000];



string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i =0;i < survey.size();i++){
        if(choices[i] < 4){
            temp[survey[i][0]] += abs(4 - choices[i]);
        } else if (choices[i] > 4) {
            temp[survey[i][1]] += abs(4 - choices[i]);
        }
    }
    if(temp['R'] < temp['T']) answer.push_back('T');
    else answer.push_back('R');
    if(temp['C'] < temp['F']) answer.push_back('F');
    else answer.push_back('C');
    if(temp['J'] < temp['M']) answer.push_back('M');
    else answer.push_back('J');
    if(temp['A'] < temp['N']) answer.push_back('N');
    else answer.push_back('A');
    return answer;
}


#include <string>
#include <vector>

using namespace std;
int alphabet[26];

char makeMBTI(char mbti1, char mbti2) {
    if (alphabet[mbti1 - 'A'] >= alphabet[mbti2 - 'A'])
        return mbti1;
    else
        return mbti2;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    for (int surveyIdx = 0; surveyIdx < survey.size(); surveyIdx++) {
        int choice = choices[surveyIdx];
        if (choice == 4)
            continue;
        int myAlphabet = (choice > 4 ? 1 : 0);
        alphabet[survey[surveyIdx][myAlphabet] - 'A'] += abs(choice - 4);
    }
    answer += makeMBTI('R', 'T');
    answer += makeMBTI('C', 'F');
    answer += makeMBTI('J', 'M');
    answer += makeMBTI('A', 'N');
    return answer;
}
