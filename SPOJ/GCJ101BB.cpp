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
    int C;
	cin >> C;
	for(int c=0; c<C; c++) {
		int N, B, K, T;
		cin >> N >> K >> B >> T;
		int temp;
		vector<int> pos, speed;
		for(int i=0; i<N; i++) {
			cin >> temp;
			pos.push_back(temp);
		}
		for(int i=0; i<N; i++) {
			cin >> temp;
			speed.push_back(temp);
		}
		
		int finishers = 0;
		vector<bool> finishersList(N);
		for(int i=0; i<N; i++) {
            // cout << "pos: " << pos[i] << " speed: " << speed[i] << endl;
			if(pos[i] + speed[i]*T >= B) {
				finishersList[i] = true;
				finishers++;
			} else {
                finishersList[i] = false;
            }
		}
		if(finishers < K) {
			cout <<  "Case #" << c << ": IMPOSSIBLE" << endl;
            continue;
		}
		int swaps = 0;
		int precedingZeroes = 0;
		finishers = 0;
		for(int i=N-1; i>=0; i--) {
			if(finishersList[i]) {
				swaps += precedingZeroes;
				finishers++;
			} else {
				precedingZeroes++;
			}
			if(finishers == K) break;
		}
		
		cout << "Case #" << c << ": " << swaps << endl;
	}
	return 0;
}