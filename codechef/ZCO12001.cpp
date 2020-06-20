#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std; 

int main() {
    int N;
    cin >> N;
    int depth = 0, cnt = 0, maxDepth = 0, maxCnt = 0, startIndex1 = 0, startIndex2 = 0, flag = 0, t;
    REP(i,N) {
        cin >> t;
        if(t == 1) {
            depth++;
            if(cnt == 0) flag = i+1;
        }
        if(depth > maxDepth) {
            maxDepth = depth;
            startIndex1 = i+1;
        }
        if(t == 2) {
            depth--;
        }
        cnt++;
        if(depth == 0) {
            if(cnt > maxCnt) {
                maxCnt = cnt;
                startIndex2 = flag;
                flag = i+1;
            }
            cnt = 0;
        }
    }

    cout << maxDepth << " " << startIndex1 << " " << maxCnt << " " << startIndex2 << endl; 
    return 0;
}