#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

typedef long long ll;
using pi = pair<int, int>;

int getPower(int x) {
    int pow = 0;
    while(x/10 != 0) {
        pow += x%10;
        x /= 10;
    }
    pow += x;
    return pow;
}

int main() {
    int T, N, Ai, Bi, cSum, mSum, cpow, mpow;
    cin >> T;
    while(T--) {
        cin >> N;
        cSum = 0;
        mSum = 0;
        while (N--) {
            cin >> Ai >> Bi;
            cpow = getPower(Ai);
            mpow = getPower(Bi);
            // cout << Ai << " " << cpow << endl;
            // cout << Bi << " " << mpow << endl;
            cSum += cpow >= mpow ? 1 : 0;
            mSum += mpow >= cpow ? 1 : 0;
        }
        if(cSum > mSum) cout << 0 << " " << cSum << endl;
        else if(mSum > cSum) cout << 1 << " " << mSum << endl;
        else cout << 2 << " " << cSum << endl;
    }
    return 0;
}