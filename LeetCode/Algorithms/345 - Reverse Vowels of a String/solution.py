# ==================================================
# Problem  :   345 - Reverse Vowels of a String
# Run time :   0.051 sec
# Language :   Python3
# ==================================================


class Solution:
    vowels: list[str] = ['a', 'e', 'i', 'o', 'u']

    def reverseVowels(self, s: str) -> str:
        letters: list[str] = list(s)

        i, j = 0, len(letters) - 1

        while i < j:
            while i < j and not self.is_vowel(letters[i]):
                i = i + 1
            while i < j and not self.is_vowel(letters[j]):
                j = j - 1
            if i < j:
                temp = letters[i]
                letters[i] = letters[j]
                letters[j] = temp
                i = i + 1
                j = j - 1

        return ''.join(letters)


    def is_vowel(self, letter: str) -> bool:
        return letter.lower() in self.vowels
