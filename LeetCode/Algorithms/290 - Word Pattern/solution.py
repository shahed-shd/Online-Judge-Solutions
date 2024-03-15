# ==================================================
# Problem  :   290 - Word Pattern
# Run time :   0.030 sec
# Language :   Python3
# ==================================================


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words: list[str] = s.split()

        if (len(pattern) != len(words)):
            return False

        pattern_to_s_map: map[str, str] = {}
        s_to_pattern_map: map[str, str] = {}

        for letter, word in zip(pattern, words):
            if letter not in pattern_to_s_map and word not in s_to_pattern_map:
                pattern_to_s_map[letter] = word
                s_to_pattern_map[word] = letter
            elif letter in pattern_to_s_map and pattern_to_s_map[letter] == word and word in s_to_pattern_map and s_to_pattern_map[word] == letter:
                pass
            else:
                return False
        
        return True
