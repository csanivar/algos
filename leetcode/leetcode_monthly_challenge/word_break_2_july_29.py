class Solution:
    
    
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        wordSet = set(wordDict)
        dp = defaultdict(list)
        
        def _word_break(s):
            if not s:
                return [[]]
            
            if s in dp:
                return dp[s]
            
            for end in range(1,len(s)+1):
                word = s[:end]
                if word in wordSet:
                    for sub in _word_break(s[end:]):
                        dp[s].append([word]+sub)
            
            return dp[s]
        
        _word_break(s)
        
        return [" ".join(words) for words in dp[s]]
