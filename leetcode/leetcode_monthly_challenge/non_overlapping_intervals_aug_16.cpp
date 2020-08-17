class Solution {
public:
    
    bool checkOverlap(vector<int> a, vector<int> b) {
        return a[1] > b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int N = intervals.size();
        if(N==0) return 0;
        sort(intervals.begin(), intervals.end());
        vector<int> dp(N, 0);
        dp[0] = 1;
        int ans = 1;
        for(int i=1; i<N; ++i) {
            int m = 0;
            for(int j=i-1; j>=0; --j) {
                if(!checkOverlap(intervals[j], intervals[i])) {
                    m = max(m, dp[j]);
                    break;
                }
            }
            dp[i] = m + 1;
            ans = max(ans, dp[i]);
        }
        
        return N-ans;
    }
};
