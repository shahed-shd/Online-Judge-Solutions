// ==================================================
// Problem  :   1282 - Group the People Given the Group Size They Belong To
// Run time :   0.009 sec
// Language :   Java
// ==================================================

public class Solution {
    static class Pair<A extends Comparable<? super A>, B extends Comparable<? super B>>
            implements Comparable<Pair<A, B>> {
        public final A first;
        public final B second;

        private Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }

        public static <A extends Comparable<? super A>, B extends Comparable<? super B>> Pair<A, B> of(A first,
                B second) {
            return new Pair<A, B>(first, second);
        }

        @Override
        public int compareTo(Pair<A, B> o) {
            int cmp = o == null ? 1 : (this.first).compareTo(o.first);
            return cmp == 0 ? (this.second).compareTo(o.second) : cmp;
        }

        @Override
        public int hashCode() {
            return (first == null ? 0 : first.hashCode()) ^ (second == null ? 0 : second.hashCode());
        }

        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Pair)) {
                return false;
            }
            if (this == o) {
                return true;
            }

            Pair<?, ?> p = (Pair<?, ?>) o;
            return Objects.equals(p.first, first) && Objects.equals(p.second, second);
        }

        @Override
        public String toString() {
            return "(" + first + ", " + second + ')';
        }
    }

    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        int n = groupSizes.length;
        List<Pair<Integer, Integer>> pairs = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            pairs.add(Pair.of(groupSizes[i], i));
        }

        Collections.sort(pairs);

        List<List<Integer>> groups = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            int size = pairs.get(i).first;
            List<Integer> group = new ArrayList<>();
            int upto = i + size - 1;

            for (int j = i; j <= upto; ++j) {
                group.add(pairs.get(j).second);
            }

            groups.add(group);
            i = upto;
        }

        return groups;
    }
}
