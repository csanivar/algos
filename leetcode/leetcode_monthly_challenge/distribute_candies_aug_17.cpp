class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int idx = 0, iter = 1;
        while(candies != 0) {
            idx = idx % num_people;
            int c = candies > iter ? iter : candies;
            ans[idx] += c;
            idx++;
            iter++;
            candies -= c;
        }
        return ans;
    }
};
