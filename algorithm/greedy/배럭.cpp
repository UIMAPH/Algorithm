#include <iostream>
using namespace std;
int N, B, U, M, TU, t;
int main() {
    cin >> N >> B >> U;
    for(t = 1; ; ++t) {
        B -= N;
        N -= TU;
        if (B > 0) {
            TU += U;
        }
        else {
            break;
        }
    }
    TU += B;
    for (; TU > 0 && N > 0; ++t) {
        TU -= N;
        N -= TU;
    }
    if (TU <= 0) {
        cout << t;
        
    }
    else { cout << -1; }
}


