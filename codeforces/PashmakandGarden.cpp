#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std; 
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
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    int ox = x1;
    int oy = y1;
    x1 -= ox;
    y1 -= oy;
    x2 -= ox;
    y2 -= oy;
    if(x2==0 and y2!=0) {
        x3 = y2; y3 = 0;
        x4 = y2; y4 = y2;
    } else if(x2!=0 and y2==0) {
        x3 = 0; y3 = x2;
        x4 = x2; y4 = x2;
    } else if(abs(x2)==abs(y2)) {
        x3 = x2; y3 = 0;
        x4 = 0; y4 = y2;
    } else {
        cout << -1 << endl;
        return 0;
    }
    cout << x3+ox << " " << y3+oy << " " << x4+ox << " " << y4+oy;
    ///////////////////////
    return 0;
}