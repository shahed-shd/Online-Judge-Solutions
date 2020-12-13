// ==================================================
// Problem  :   1461B - Find the Spruce
// Run time :   0.920 sec
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
            int m = sc.nextInt();

            int[][] up = new int[n][m];
            int[][] left = new int[n][m];
            int[][] right = new int[n][m];

            for (int i = 0; i < n; ++i) {
                String line = sc.nextLine();

                for (int j = 0; j < m; ++j) {
                    if (line.charAt(j) == '*') {
                        up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
                        left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
                    } else {
                        up[i][j] = left[i][j] = 0;
                    }

                    int revJ = m - 1 - j;
                    if (line.charAt(revJ) == '*') {
                        right[i][revJ] = revJ == m - 1 ? 1 : right[i][revJ + 1] + 1;
                    } else {
                        right[i][revJ] = 0;
                    }
                }

            }

            long ans = 0;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int mx = Math.min(Math.min(up[i][j], left[i][j]), right[i][j]);

                    if (mx > 0) {
                        ans += binSearch(1, mx, i, j, up, left, right);
                    }
                }
            }

            out.println(ans);
        }
    }

    static int binSearch(int s, int t, int r, int c, int[][] up, int[][] left, int[][] right) {
        int ret = 0;

        while (s <= t) {
            int mid = (s + t) / 2;
            if (isSpruceTree(r, c, mid, up, left, right)) {
                ret = mid;
                s = mid + 1;
            } else {
                t = mid - 1;
            }
        }

        return ret;
    }

    static boolean isSpruceTree(int r, int c, int h, int[][] up, int[][] left, int[][] right) {
        for (int i = 1; i <= h; ++i) {
            int rr = r - h + i;
            if (!(up[rr][c] >= i && left[rr][c] >= i && right[rr][c] >= i)) {
                return false;
            }
        }

        return true;
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
