# ==================================================
# Problem  :   194. Transpose File 
# Run time :   0.120 sec
# Language :   Bash 
# ==================================================

# Read from the file file.txt and print its transposed content to stdout.

declare -A arr
lineNum=0
colNum=0

while read -a words; do
    colNum=0
    for word in ${words[@]}; do
        arr[$lineNum,$(( colNum++ ))]=$word
    done
    (( ++lineNum ))
done < file.txt

(( --lineNum, --colNum ))

for i in $(seq 0 $colNum); do
    line=''
    for j in $(seq 0 $lineNum); do
        if (( j > 0 )) ; then
            line+=' '
        fi
        line+=${arr[$j,$i]}
    done
    echo $line
done

