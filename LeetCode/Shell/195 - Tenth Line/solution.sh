# ==================================================
# Problem  :   195 - Tenth Line  
# Run time :   0.004 sec
# Language :   Bash 
# ==================================================

# Read from the file file.txt and output the tenth line to stdout.
head -n 10 file.txt | tail -n +10
