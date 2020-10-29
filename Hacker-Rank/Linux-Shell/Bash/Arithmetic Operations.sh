# ==================================================
# Problem   :   Arithmetic Operations
# Score     :   3 /3
# Language  :   Bash
# ==================================================

read line
printf "%.3f\n" $(echo $line | bc -l)
