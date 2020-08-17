class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        int N = prices.size();
        if(N <=1 ) return 0;
        
        int leftMin = prices[0], rightMax = prices[N-1];
        vector<int> leftProfits(N, 0);
        vector<int> rightProfits(N+1, 0);
        
        for(int l=1; l<N; ++l) {
            leftProfits[l] = max(leftProfits[l-1], prices[l] - leftMin);
            leftMin = min(prices[l], leftMin);
            
            int r = N-l-1;
            rightProfits[r] = max(rightProfits[r+1], rightMax-prices[r]);
            rightMax = max(prices[r], rightMax);
        }
        
        int ans = 0;
        for(int i=0; i<N; ++i) {
            ans = max(ans, leftProfits[i]+rightProfits[i+1]);
        }
        return ans;
        */
        int t1Cost = INT_MAX, t2Cost = INT_MAX;
        int t1Profit = 0, t2Profit = 0;
        for(int price: prices) {
            t1Cost = min(t1Cost, price);
            t1Profit = max(t1Profit, price-t1Cost);
            t2Cost = min(t2Cost, price - t1Profit);
            t2Profit = max(t2Profit, price - t2Cost);
        }
        
        return t2Profit;
    }
};
