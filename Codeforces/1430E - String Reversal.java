// ==================================================
// Problem  :   1430E - String Reversal
// Run time :   0.249 sec
// Language :   Java
// ==================================================

import java.io.*;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.HashMap;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Arrays;

public class Main {

    public static void main(final String[] args) {
        // FastScanner sc = new FastScanner("in.txt");
        // PrintWriter out;
        // try {
        //     out = new PrintWriter("out.txt");
        // } catch (FileNotFoundException e) {
        //     e.printStackTrace();
        //     return;
        // }

        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        solve(sc, out);
        out.flush();

        sc.close();
        out.close();
    }

    static void solve(FastScanner sc, PrintWriter out) {
        int n = sc.nextInt();
        char[] s = sc.nextToken().toCharArray();

        Map<Character, Queue<Integer>> positions = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            if (!positions.containsKey(s[i])) {
                positions.put(s[i], new ArrayDeque<>());
            }
            positions.get(s[i]).add(i);
        }

        boolean[] isMoved = new boolean[n];
        Arrays.fill(isMoved, false);

        BinIdxTree bit = new BinIdxTree(n + 1);
        long ans = 0;

        for (int i = 0, j = n - 1; i < n && j >= 0; --j) {
            char currChar = s[i];
            char charToMove = s[j];

            if (currChar != charToMove) {
                int currCharPos = positions.get(currChar).element();
                int currCharPosWithOffset = currCharPos + bit.query(currCharPos + 1);

                int charToMovePos = positions.get(charToMove).remove();
                int charToMovePosWithOffset = charToMovePos + bit.query(charToMovePos + 1);

                int swapCount = charToMovePosWithOffset - currCharPosWithOffset;
                ans += swapCount;

                isMoved[charToMovePos] = true;
                bit.update(currCharPos + 1, 1);
                bit.update(charToMovePos + 2, -1);
            } else {
                ++i;
                while (i < n && isMoved[i]) {
                    ++i;
                }
                positions.get(currChar).remove();
            }
        }

        out.println(ans);
    }
}

class BinIdxTree {
    int[] tree;
    int sz;

    BinIdxTree(int n) {
        sz = n;
        tree = new int[n + 3];
        Arrays.fill(tree, 0);
    }

    int offset(int x) {
        return x & (-x);
    }

    void update(int idx, int val) {
        while (idx <= sz) {
            tree[idx] += val;
            idx += offset(idx);
        }
    }

    int query(int idx) {
        int sum = 0;

        while (idx > 0) {
            sum += tree[idx];
            idx -= offset(idx);
        }

        return sum;
    }
}

class FastScanner {
    private BufferedReader br;
    private StringTokenizer st;

    public FastScanner(String fileName) {
        try {
            br = new BufferedReader(new FileReader(fileName));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String readLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    public String nextToken() {
        while (st == null || !st.hasMoreElements()) {
            st = new StringTokenizer(readLine());
        }
        return st.nextToken();
    }

    public String nextLine() {
        String str = "";

        if (st != null && st.hasMoreElements()) {
            str = st.nextToken("\n\r\f");
        } else {
            str = readLine();
        }

        return str;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    public void close() {
        try {
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
