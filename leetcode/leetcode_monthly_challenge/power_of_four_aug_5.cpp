class Solution {
public:
    bool isPowerOfFour(int num) {
        // return (num > 0) and ((num & (num-1)) == 0) and ((num & 0xaaaaaaaa) == 0);
        return (num > 0) and ((num & (num-1)) == 0) and (num % 3 == 1);
    }
};