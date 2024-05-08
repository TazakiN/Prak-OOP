import java.util.*;

public class Pasukan<T extends List<Integer>> {
    private int n;
    private List<Integer> pasukan;

    public Pasukan(T list, int n) {
        this.n = n;
        pasukan = list;
    }

    public void reset() {
        pasukan.clear();
        for (int i = 0; i < n; i++) {
            pasukan.add(0);
        }
    }

    public long get(int idx) {
        reset();
        long start = Util.getTime();
        int result = pasukan.get(idx);
        long end = Util.getTime();
        return end - start;
    }

    public long del(int idx, int count) {
        reset();
        long start = Util.getTime();
        for (int i = 0; i < count; i++) {
            pasukan.remove(idx);
        }
        long end = Util.getTime();
        return end - start;
    }
}
