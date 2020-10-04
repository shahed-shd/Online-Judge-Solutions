// ==================================================
// Problem  :   1426C - Increase and Copy
// Run time :   0.187 sec
// Language :   Java
// ==================================================

import java.io.*;
import java.util.StringTokenizer;

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
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int res = binSearch(0, n, n);
            out.println(res);
        }
    }

    static int binSearch(int start, int end, int n) {
        int res = -1;

        while (start <= end) {
            int m = (start + end) / 2;

            if (canObtain(m, n)) {
                res = m;
                end = m - 1;
            } else {
                start = m + 1;
            }
        }

        return res;
    }

    static boolean canObtain(int moveCount, int n) {
        int increasingMove = moveCount / 2;
        long copyingMove = moveCount - increasingMove;
        long sum = (increasingMove + 1) + copyingMove * (increasingMove + 1);
        return sum >= n;
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
