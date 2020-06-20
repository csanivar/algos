class Solution:
    
    def gethIndex(self, val, idx, N):
        if idx < 0 or idx > N-1:
            return -1
        if val >= N - idx:
            return N - idx
        else:
            return -1
    
    def hIndex(self, citations: List[int]) -> int:
        N = len(citations)
        lo = 0
        hi = N
        while lo < hi:
            mid = lo + (hi-lo)//2
            print(mid)
            if self.gethIndex(citations[mid], mid, N) != -1:
                if mid == 0 or self.gethIndex(citations[mid-1], mid-1, N) == -1:
                    return N - mid
                else:
                    hi = mid-1
            else:
                lo = mid+1
        
        return N - lo
