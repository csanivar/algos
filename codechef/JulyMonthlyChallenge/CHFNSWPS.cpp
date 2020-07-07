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

int main() {
    int T, N, temp;
    cin >> T;
    map<int, int> a, total;
    while(T--) {
        cin >> N;
        REP(i,0,N-1) {
            cin >> temp;
            if(a.find(temp) != a.end()) {
                a[temp]++;
                total[temp]++;
            } else {
                a.insert({temp, 1});
                total.insert({temp, 1});
            }
        }
        REP(i,0,N-1) {
            cin >> temp;
            if(total.find(temp) != total.end()) {
                total[temp]++;
            } else {
                total.insert({temp, 1});
            }
        }
        int ans = 0;
        for(auto item: total) {
            if((item.second&1) == 1) {
                ans = -1;
                break;
            }
            if(a.find(item.first) != a.end()) {
                temp = abs(total[item.first]/2 - a[item.first]);
            } else {
                temp = total[item.first]/2;
            }
            ans += temp;
        }
        ans = ans != -1 ? ans/2 : -1;
        cout << ans << endl;
        a.clear();
        total.clear();
    }
    return 0;
}

/*
1
5
1 1 1 2 2
3 3 4 4 1
*/