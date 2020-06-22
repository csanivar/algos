class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        mp = {}
        res = []
        for i,name in enumerate(names):
            if name in mp.keys():
                k = mp[name]
                while name+"("+str(k)+")" in mp.keys():
                    k += 1
                    mp[name] += 1
                mp[name] += 1
                names[i] = names[i]+"("+str(k)+")"
                
            mp[names[i]] = 1
        
        return names
        
