// ==================================================
// Problem  :   1444B - Divide and Sum
// Run time :   0.280 sec
// Language :   Java
// ==================================================

import java.io.*;
import java.util.Arrays;
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
        int n = sc.nextInt();
        int[] arr = new int[2 * n];

        for (int i = 0; i < 2 * n; ++i) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);
        long sumL = 0L;
        long sumR = 0L;

        for (int i = 0; i < n; ++i) {
            sumL += arr[i];
            sumR += arr[n + i];
        }

        final int mod = 998244353;
        long numerator = 1L;
        long denominator = 1L;

        for (int i = 1; i <= n; ++i) {
            numerator *= (n + i);
            if (numerator > mod) numerator %= mod;

            denominator *= i;
            if (denominator > mod) denominator %= mod;
        }

        long modInvRes = modInv(denominator, mod);
        if(modInvRes < 0) modInvRes += mod;
        
        long ans = (sumR - sumL) % mod;
        ans = (ans * numerator) % mod;
        ans = (ans * modInvRes) % mod;

        out.println(ans);
    }

    static class ExtEuclidResult {
        long x, y, gcd;

        ExtEuclidResult(long x, long y, long gcd) {
            this.x = x;
            this.y = y;
            this.gcd = gcd;
        }
    }

    static ExtEuclidResult extEuclid(long a, long b) {
        long x = 0; long y = 1; long gcd = b;
        long m, n, q, r;

        for (long u = 1, v = 0; a != 0; gcd = a, a = r) {
            q = gcd / a; r = gcd % a;
            m = x-u*q; n = y-v*q;
            x = u; y = v; u = m; v = n;
        }

        return new ExtEuclidResult(x, y, gcd);
    }

    // The result could be negative, if it's required to be positive, then add 'm'.
    static long modInv(long n, long m) {
        ExtEuclidResult res = extEuclid(n, m);
        if (res.gcd == 1)
            return res.x % m;
        return 0;
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
