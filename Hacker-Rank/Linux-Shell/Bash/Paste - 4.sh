
# ==================================================
# Problem   :   Paste - 4
# Score     :   2 /2
# Language  :   Bash
# ==================================================

lineCount=0

while read line; do
    (( ++lineCount ))

    if (( lineCount == 2 || lineCount == 3 )); then
        printf "\t"
    fi

    printf "%s" "$line"
    
    if (( lineCount == 3 )); then
        lineCount=0
        printf "\n"
    fi
done
