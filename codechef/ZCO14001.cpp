#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std; 
using lint = long long;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
int main()
{   
    int n, h;
    cin >> n >> h;
    int a[n];
    REP(i,n) {
        cin >> a[i];
    }
    int cx = 0;
    int ci = 0;
    while(1) {
        int b;
        cin >> b;
        if (b==0) break;
        switch(b) {
            case 1: {
                if (cx > 0) cx--;
                break;
            }
            case 2: {
                if (cx < n-1) cx++;
                break;
            }
            case 3: {
                if (a[cx] > 0 and ci == 0) {
                    ci = 1;
                    a[cx] = a[cx] - 1;
                }
                break;
            }
            case 4: {
                if (a[cx] < h and ci == 1) {
                    a[cx] = a[cx] + 1;
                    ci = 0;
                }
                break;
            }
            case 0: break;
        }
    }
    REP(i,n) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}