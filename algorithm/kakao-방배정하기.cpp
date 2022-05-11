#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
vector<pair<long long, int>>arr;
int soon[200001];

bool sorting(pair <int,int> p1, pair <int,int> p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0;i<room_number.size();i++){
        arr.push_back({room_number[i],i});
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        soon[arr[i].second] = i;
    }
    for(int i=0;i<arr.size();i++){
        if(arr[arr[soon[i]].first].second() > arr[soon[i]].first)
    }
    
    
    
    return answer;
}
