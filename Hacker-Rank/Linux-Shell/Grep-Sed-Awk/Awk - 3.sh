# ==================================================
# Problem   :   'Awk' - 3
# Score     :   2 /2
# Language  :   Bash
# ==================================================

awk '{
    average = ($2 + $3 + $4) / 3
     
    if (average >= 80) {
        grade = "A"
    } else if ( average >= 60) {
        grade = "B"
    } else if (average >= 50) {
        grade = "C"
    } else {
        grade = "FAIL"
    }
    
    print $0 " : " grade
}'
