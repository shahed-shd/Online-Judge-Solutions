// ==================================================
// Problem  :   1455B - Jumps
// Run time :   0.202 sec
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
            int x = sc.nextInt();

            int n = (int) Math.ceil((-1 + Math.sqrt(1 + 8 * x)) / 2);
            int sum = (int) ((long) n * (1 + n) / 2);
            int d = sum - x;    // d will be non-negative.

            int ans;

            if (d == 1) {
                ans = n + 1;
            } else {    // if d is any non-negative number except 1.
                ans = n;
            }

            out.printf("%d\n", ans);
        }
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
