class Solution:
    def isAnagram(self, s:str, t:str) -> bool:

        # check the len of both strings
        if len(s) != len(t):
            return False
        #make hashmaps 
        countS, countT = {}, {}

        #iterate through keys and values in both hashmaps to check if they are equal
        for i in range(len(s)):
            countS[s[i]] = 1 + countS.get(s[i], 0)
            countT[t[i]] = 1 + countT.get(t[i], 0)
        
        for c in countS:
            if countS[c] != countT.get(c, 0):
                return False
            
        return True
    
        """
        Alternative solution with less time complexity 
        return sorted(s) == sorted(t)
        
        """
        
    

