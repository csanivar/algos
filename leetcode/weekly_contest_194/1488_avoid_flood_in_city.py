class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        filled = {}
        dry_days = []
        ans = [0]*len(rains)
        for i in range(len(rains)):
            if rains[i] == 0:
                dry_days.append(i)
            if rains[i] > 0:
                ans[i] = -1
                if rains[i] in filled.keys():
                    dry_day = -1
                    for day in dry_days:
                        if day > filled[rains[i]]:
                            dry_day = day
                            break
                    if dry_day == -1:
                        return []
                    # print(rains[i]," ",dry_day)
                    ans[dry_day] = rains[i]
                    del filled[rains[i]]
                    dry_days.remove(dry_day)
                filled[rains[i]] = i
        
        for dry_day in dry_days:
            ans[dry_day] = 1
        
        return ans
                
