class Solution {
public:
    
    long MOD = pow(2,32);
    
    int hasDuplicate(string S, int l) {
        // cout << "l: " << l << endl;
        set<long> hashes;
        long h = 0;
        long t = 1;
        for(int i=0; i<l; i++) {
            h = (h*26 % MOD + (S[i]-'a')) % MOD;
            t = (t*26) % MOD;
        }
        // cout << "h: " << h << endl;
        hashes.insert(h);
        int N = S.length();
        for(int i=1; i<N-l+1; i++) {
            h = (h*26 - (S[i-1]-'a')*t%MOD + MOD) % MOD;
            h = (h + (S[i+l-1]-'a')) % MOD;
            if(hashes.count(h) != 0) {
                // cout << "i: " << i << endl;
                return i;
            }
            else hashes.insert(h);
        }
        return -1;
    }
    
    string longestDupSubstring(string S) {
        int N = S.length();
        int lo = 1, hi = N;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(hasDuplicate(S, mid) != -1) lo = mid+1;
            else hi = mid - 1;
        }
        int start = hasDuplicate(S, lo-1);
        return S.substr(start, lo-1);
    }
};
