#include<iostream>
#include<algorithm>
using namespace std;
int arr[10000];

int main(){
    int play[10000]={0,};
    int win[10000]={0,};
    int time;
    bool check= false;
    cin>>time;
    for(int i=0;i<time;i++){
        cin>>arr[i];
    }
    sort(arr,arr+time);
    for(int i=0;i<time;i++){
        int k=0;
        for(k=i;arr[i]!=win[i];k++){
            play[i]++;
            play[k]++;
            win[i]++;
            if(play[k]>time-1 or win[k]>arr[k]){
                check=true;
                break;
            }
        }
        k++;
        for(;k<time and !check;k++){
            play[i]++;
            play[k]++;
            win[k]++;
            if(play[k]>time-1 or win[k]>arr[k]){
                check=true;
                break;
            }
        }
    }
    if(check) cout<<"-1";
    else cout<<"1";
    
}
/*
 #include <bits/stdc++.h>
 #define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #define FOR(i, a, b) for(int i=a;i<=b;i++)
 using namespace std;

 int main() {
     FIO;
     int n, sum = 0;
     int v[10005];
     cin >> n;
     FOR(i, 1, n) cin >> v[i];
     sort(v + 1, v + n + 1);
     FOR(i, 1, n) {
         sum += v[i];
         if (sum < i * (i - 1) / 2)
             return cout << -1 << '\n', 0;
     }
     cout << (sum == n * (n - 1) / 2 ? 1 : -1) << '\n';
     return 0;
 }
 */
