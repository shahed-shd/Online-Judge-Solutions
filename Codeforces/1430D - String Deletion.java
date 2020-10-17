// ==================================================
// Problem  :   1430D - String Deletion
// Run time :   0.186 sec
// Language :   Java
// ==================================================

import java.io.*;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;

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
            String s = sc.nextToken();
            List<Integer> chunks = new ArrayList<>();

            for (int i = 0; i < n;) {
                char newSeqStartChar = s.charAt(i);
                int newSeqStartIndex = i;

                do {
                    ++i;
                } while (i < n && s.charAt(i) == newSeqStartChar);

                chunks.add(i - newSeqStartIndex);
            }

            int ans = 0;

            int i = 0;
            int j = 0;

            while (i < chunks.size()) {
                ++ans;

                if (chunks.get(i) == 1) {
                    while (j < chunks.size() && (j <= i || chunks.get(j) == 1)) {
                        ++j;
                    }

                    if (j < chunks.size()) {
                        // Select index in chunk[j] and delete the i-th chunk as prefix.
                        chunks.set(j, chunks.get(j) - 1);
                        ++i;
                    } else {
                        // Select index in chunk[i] and delete the (i+1)-th chunk as prefix.
                        // Each of these chunks contains 1 character.
                        i += 2;
                    }
                } else {
                    // Select index in i-th chunk and delete the rest of the chunk as prefix.
                    ++i;
                }
            }

            out.println(ans);
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
