# This was tough and had to look at the solution to do in liner time with constant extra space
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        seen_once = 0
        seen_twice = 0
        for num in nums:
            seen_once = ~seen_twice & (seen_once^num)
            seen_twice = ~seen_once & (seen_twice^num)
        
        return seen_once
        
