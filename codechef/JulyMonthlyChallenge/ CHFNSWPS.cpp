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
        while(N--) {
            cin >> temp;
            if(a.find(temp) != a.end()) {
                a[temp]++;
                total[temp]++;
            } else {
                a.insert({temp, 1});
                total.insert({temp, 1});
            }
        }
        while(N--) {
            cin >> temp;
            if(total.find(temp) != total.end()) {
                total[temp]++;
            } else {
                total.insert({temp, 1});
            }
        }
        int ans = 0;
        for(auto item: total) {
            if(a.find(item.first) != a.end()) {
                temp = abs(total[item.first] - a[item.first]);
            } else {
                temp = total[item.first];
            }
            if((temp&1) != 1) {
                ans = -1;
                break;
            } else {
                ans += temp/2;
            }
        }
        cout << ans << endl;
        a.clear();
        total.clear();
    }
    return 0;
}