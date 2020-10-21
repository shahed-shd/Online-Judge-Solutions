// ==================================================
// Problem  :   3 - Longest Substring Without Repeating Characters
// Run time :   0.005 sec
// Language :   Java
// ==================================================

class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Boolean> mp = new HashMap<>();
        int ans = 0;
        int i = 0, j = 0, len = s.length();

        while (i < len) {
            char ch = s.charAt(i);
            mp.putIfAbsent(ch, false);

            boolean isFoundBefore = mp.get(ch);

            if (isFoundBefore) {
                ans = Math.max(ans, i - j);

                while (s.charAt(j) != ch) {
                    mp.put(s.charAt(j), false);
                    ++j;
                }

                ++j;
            }

            mp.put(ch, true);
            ++i;
        }

        ans = Math.max(ans, i - j);

        return ans;
    }
}
