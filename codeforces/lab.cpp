#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
 
vector<pi> pr;
 
int main(){
	int n; scanf("%d",&n);
	lint ans = 1ll * n * n;
	for(int i=0; i<n; i++){
		int m; scanf("%d",&m);
		vector<int> v(m);
		for(int i=0; i<m; i++) scanf("%d",&v[i]);
		reverse(all(v));
		if(is_sorted(all(v))){
			pr.emplace_back(v[0], v.back());
		}
	}
	sort(all(pr));
	for(int i=0; i<sz(pr); i++){
		ans -= pr.end() - lower_bound(all(pr), pi(pr[i].second, -1));
	}
	cout << ans << endl;
}

int t[1e5];
void modify(int l, int r, int val) {
	for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if(l&1) t[l++] += val;
		if(r&1) t[--r] += val;
	}
}

int query(int p) {
	int ans = 0;
	for(p+=n;p>0;p>>=1) {
		res += t[p];
	}
	return ans;
}

void push() {
	for(int i=1; i<n; i++) {
		t[i<<1] += t[i];
		t[i<<1|1] += t[i];
		t[i] = 0;
	}
}