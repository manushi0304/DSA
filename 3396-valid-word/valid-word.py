class Solution:
    def isValid(self, word: str) -> bool:
        if len(word)<3:
            return False
        has_vowel=False
        has_con=False

        for c in word:
            if not c.isalnum():
                return False
            if c.isalpha():
                if c.lower() in'aeiou':
                    has_vowel=True
                else:
                    has_con=True
        
        return has_vowel and has_con

        