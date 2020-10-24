// ==================================================
// Problem  :   1381 - Design a Stack With Increment Operation 
// Run time :   0.004 sec
// Language :   Java
// ==================================================

class CustomStack {
    int maxSize;
    int currSize;
    BinIdxTree binIdxTree;

    static class BinIdxTree {
        long[] tree;
        int sz; // 1 based indexed fenwick tree

        BinIdxTree(int n) {
            sz = n;
            tree = new long[n + 3];
            Arrays.fill(tree, 0L);
        }

        int offset(int x) {
            return x & (-x);
        }

        void update(int idx, long val) {
            while (idx <= sz) {
                tree[idx] += val;
                idx += offset(idx);
            }
        }

        long query(int idx) {
            long sum = 0;

            while (idx > 0) {
                sum += tree[idx];
                idx -= offset(idx);
            }

            return sum;
        }
    }

    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        currSize = 0;
        binIdxTree = new BinIdxTree(maxSize);
    }

    public void push(int x) {
        if (currSize < maxSize) {
            ++currSize;
            binIdxTree.update(currSize, x);
            binIdxTree.update(currSize + 1, -x);
        }
    }

    public int pop() {
        int val = -1;

        if (currSize > 0) {
            val = (int) binIdxTree.query(currSize);
            binIdxTree.update(currSize, -val);
            binIdxTree.update(currSize+1, val);
            --currSize;
        }

        return val;
    }

    public void increment(int k, int val) {
        int kk = Math.min(k, currSize);
        binIdxTree.update(1, val);
        binIdxTree.update(kk + 1, -val);
    }
}
