class Solution:
    
    def nextday(self, state_bitmap):
        state_bitmap = ~ (state_bitmap << 1) ^ (state_bitmap >> 1)
        state_bitmap &= 0b01111110
        
        return state_bitmap
        
    
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        fast_forwarded = False;
        seen = dict()
        
        state_bitmap = 0x0
        for cell in cells:
            state_bitmap <<= 1
            state_bitmap = (state_bitmap | cell)
        
        while N > 0:
            if not fast_forwarded:
                if state_bitmap in seen:
                    N %= (seen[state_bitmap] - N)
                    fast_forwarded = True
                else:
                    seen[state_bitmap] = N
                    
            if N > 0:
                N -= 1
                state_bitmap = self.nextday(state_bitmap)
        
        ret = []
        for i in range(len(cells)):
            ret.append(state_bitmap & 0x1)
            state_bitmap = state_bitmap >> 1
            
        return reversed(ret)
                
        
        
