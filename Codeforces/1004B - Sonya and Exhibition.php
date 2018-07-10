<?php
// ==================================================
// Problem  :   1004B - Sonya and Exhibition
// Run time :   0.046 sec
// Language :   PHP 7.0.12
// ==================================================


function main() {
    # I/O stream.
    define('INSTREAM', STDIN, FALSE);
    define('OUTSTREAM', STDOUT, FALSE);
    // define('INSTREAM', fopen("in.txt", "r"), FALSE);
    // define('OUTSTREAM', fopen("out.txt", "w"), FALSE);

    fscanf(INSTREAM, "%d %d", $n, $m);

    for($i = 0; $i < $m; ++$i) {
        fscanf(INSTREAM, "%*d %*d");
    }

    for($i = 0; $i < $n; ++$i) {
        echo ($i & 1)? '0' : '1';
    }

    echo "\n";
}

main();

?>
