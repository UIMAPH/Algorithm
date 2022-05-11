#include <string>
#include <vector>

using namespace std;
int arr[399999999];
int pt;
int at;




int stringToSecond(string t){
    int ans=0;
    ans += ((t[6]-'0') * 10) + (t[7]-'0');
    ans += (((t[3]-'0') * 10) + (t[4]-'0'))*60;
    ans += (((t[0]-'0') * 10) + (t[1]-'0')* 3600);
    return ans;
}

string make(int a){
    string temp;
    temp.push_back((a / 3600) / 10 + '0');
    temp.push_back((a / 3600) % 10 + '0');
    temp.push_back(':');
    a %= 3600;
    temp.push_back((a / 60) / 10 + '0');
    temp.push_back((a / 60) % 10 + '0');
    temp.push_back(':');
    a %=60;
    temp.push_back(a/ 10 + '0');
    temp.push_back(a % 10 + '0');
    return temp;
}


string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    pt = stringToSecond(play_time);
    at = stringToSecond(adv_time);
    for(int i=0;i<logs.size();i++){
        for(int j=0;j<logs[i].size();j++){
            string temp;
            if(logs[i][j] == '-'){
                arr[stringToSecond(temp)]++;
                temp.clear();
                continue;
            }
            temp.push_back(logs[i][j]);
            if(logs[i].size()== j+1){
                arr[stringToSecond(temp)+1]--;
                temp.clear();
            }
        }
    }
    int ctime=0;
    int cperson=0;
    int nowsize=0;
    for(int i=0;i<at;i++){
        if(arr[i] != 0){
            cperson += arr[i];
        }
        ctime += cperson;
    }
    int max=0;
    int maxtime = ctime;
    for(int i=at;i<=pt;i++){
        cperson += arr[i];
        cperson += arr[i - at];
        ctime += cperson;
        if(ctime > maxtime){
            max = i;
            maxtime = ctime;
        }
    }
    answer = make(max);
    return answer;
}
