
# ==================================================
# Problem   :   Compute the Average
# Score     :   4 /4
# Language  :   Bash
# ==================================================

read n
sum=0

for _ in $(seq 1 $n); do
    read x;
    (( sum += x ))
done

printf "%.3f\n" $( echo "$sum / $n" | bc -l )
