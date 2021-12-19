class Solution:
    def isPalin(self,word):
        _len = len(word)
        for i in range(0,_len//2):
            if(word[i] != word[_len-i-1]):
                return False
        return True
    
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if(self.isPalin(word)):
                return word
        return ""
    
    
        