#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> node[100001];
vector<vector<int>> scc;
int nodeId[100001], id;
int indegree[100001];
int nodeSccNumber[100001];
bool finished[100001];
stack<int> tmp;
int n,m;
int ans;

void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        node[a].push_back(b);
    }
}

int dfs(int x){
    nodeId[x] = ++id;
    tmp.push(x);
    int parent = nodeId[x];
    for(int i=0;i<node[x].size();i++){
        int y = node[x][i];
        if(nodeId[y] == 0) parent = min(parent, dfs(y));
        else if (!finished[y]) parent = min(parent, nodeId[y]);
    }

    if(parent == nodeId[x]){
        vector<int> z;
        while(1){
            int t = tmp.top();
            tmp.pop();
            nodeId[t] = parent;
            z.push_back(t);
            finished[t] = true;
            if(t==x) break;
        }
        scc.push_back(z);
    }
    return  parent;
}


int main(){
    input();
    for(int i=0;i<n;i++){
        if(!finished[i]) {
            dfs(i);
        }
    }
    for(int i=0;i<n;i++){
        indegree[nodeId[i]] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<node[i].size();j++){
            if(nodeId[i] != nodeId[node[i][j]]){
                indegree[nodeId[node[i][j]]]++;
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(indegree[i]==1) ans++;
    }
    cout<<ans;
}









