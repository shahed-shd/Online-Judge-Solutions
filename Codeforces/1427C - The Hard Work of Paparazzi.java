// ==================================================
// Problem  :   1427C - The Hard Work of Paparazzi
// Run time :   1.201 sec
// Language :   Java
// ==================================================

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static final int INF = Integer.MAX_VALUE;

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
        int r = sc.nextInt();
        int n = sc.nextInt();

        int[] tArr = new int[n + 3];
        int[] xArr = new int[n + 3];
        int[] yArr = new int[n + 3];

        int[] maxFor = new int[n + 3];
        int[] maxUpto = new int[n + 3];

        tArr[0] = 0;
        xArr[0] = 1;
        yArr[0] = 1;

        maxFor[0] = 0;
        maxUpto[0] = 0;

        for (int i = 1; i <= n; ++i) {
            tArr[i] = sc.nextInt();
            xArr[i] = sc.nextInt();
            yArr[i] = sc.nextInt();

            maxFor[i] = -INF;

            for (int j = Math.max(i - 2 * r, 0); j < i; ++j) {
                if (Math.abs(xArr[j] - xArr[i]) + Math.abs(yArr[j] - yArr[i]) <= tArr[i] - tArr[j]) {
                    maxFor[i] = Math.max(maxFor[i], maxFor[j] + 1);
                }
            }

            if (i - 2 * r > 0) {
                maxFor[i] = Math.max(maxFor[i], maxUpto[i - 2 * r] + 1);
            }

            maxUpto[i] = Math.max(maxFor[i], maxUpto[i - 1]);
        }

        out.println(maxUpto[n]);
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
