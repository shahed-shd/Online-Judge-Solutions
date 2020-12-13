// ==================================================
// Problem  :   1461D - Divide and Summarize
// Run time :   0.280 sec
// Language :   Java
// ==================================================

import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
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
            int q = sc.nextInt();

            int[] a = new int[n];

            for (int i = 0; i < n; ++i) {
                a[i] = sc.nextInt();
            }

            Arrays.sort(a);

            int[] s = new int[q];
            Map<Long, Boolean> mp = new HashMap<>();

            for (int i = 0; i < q; ++i) {
                s[i] = sc.nextInt();
                mp.put((long) s[i], false);
            }

            dnc(a, 0, n - 1, mp);

            for (long x : s) {
                out.println(mp.getOrDefault(x, false) ? "Yes" : "No");
            }
        }
    }

    static long dnc(int[] a, int s, int t, Map<Long, Boolean> mp) {
        if (s > t || s < 0 || t < 0) {
            return 0;
        }

        long sum = 0;

        if (s == t) {
            sum = a[s];
        } else {
            int m = (a[s] + a[t]) / 2;
            int idx = upper_bound(a, s, t + 1, m);

            long sum1 = idx - 1 != t ? dnc(a, s, idx - 1, mp) : -1;
            long sum2 = idx != s ? dnc(a, idx, t, mp) : -1;

            if (sum1 < 0 || sum2 < 0) {
                for (int i = s; i <= t; ++i)
                    sum += a[i];
            } else {
                sum = sum1 + sum2;
            }
        }

        mp.replace(sum, true);
        return sum;
    }

    static int upper_bound(int[] a, int lo, int hi, int key) {
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (a[mid] <= key) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo;
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
