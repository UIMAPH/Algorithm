#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> w;
vector<int> d;


void solving(int wtime, int count,int wcount,int length,int person){
    for(int i=0;i < w.size() ;i++){
        if(wtime+length > w[i]){
            solving(wtime+length,i,count - (i+1), d[person+1]);
        }
    }
}


int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    for(int i=0;i<weak.size();i++){
        w.push_back(weak[i]);
        w.push_back(weak[i]+n);
    }
    d = dist;
    sort(d.begin(),d.end(),greater<int>());
    
    
    
    
    return answer;
}
