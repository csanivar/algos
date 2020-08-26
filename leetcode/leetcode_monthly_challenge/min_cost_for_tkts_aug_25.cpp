class Solution {
public:
    vector<int> res, d, c;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        res = vector<int>(366, -1);
        d = vector<int>(366, 0);
        for(int day: days) d[day] = 1;
        c = costs;
        return dp(1);
    }
    
    int dp(int day) {
        if(day > 365) return 0;
        if(res[day] != -1) return res[day];
        int ans;
        if(d[day] == 1) {
            ans = min(dp(day+1)+c[0], dp(day+7)+c[1]);
            ans = min(ans, dp(day+30)+c[2]);
        } else {
            ans = dp(day+1);
        }
        res[day] = ans;
        return ans;
    }
};
