# ==================================================
# Problem  :   120 - Triangle
# Run time :   0.064 sec
# Language :   Python3
# ==================================================


class Solution:
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        prev_row_result: list[int] = [0]

        for row in triangle:
            curr_row_result: list[int] = []

            for index, value in enumerate(row):
                if index == 0:
                    prev_min = prev_row_result[index]
                elif index == len(row) - 1:
                    prev_min = prev_row_result[index - 1]
                else:
                    prev_min = min(prev_row_result[index - 1], prev_row_result[index])

                curr_row_result.append(prev_min + value)
            
            prev_row_result = curr_row_result

        return min(prev_row_result)
