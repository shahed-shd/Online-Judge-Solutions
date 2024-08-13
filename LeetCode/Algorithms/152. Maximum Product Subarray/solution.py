# ==================================================
# Problem  :   152. Maximum Product Subarray
# Run time :   0.076 sec
# Language :   Python3
# ==================================================


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_product = nums[0]

        prev_max = curr_max = prev_min = curr_min = 1

        for num in nums:
            if 0 <= num:
                curr_max = max(num, prev_max * num)
                curr_min = min(num, prev_min * num)
            else:
                curr_max = max(num, prev_min * num)
                curr_min = min(num, prev_max * num)
            
            max_product = max(max_product, curr_max)

            prev_max = curr_max
            prev_min = curr_min
        
        return max_product
