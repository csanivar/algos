import java.util.HashMap;

// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class TargetMean {
    static long MAX = 1000000000;
    public static int solution(int[] A, int S) {
        HashMap<Long, Long> mp = new HashMap<>();
        long sum = 0;
        for(int i=0; i<A.length; i++) {
            A[i] -= S;
        }
        long ans = 0;
        for(int i=0; i<A.length; i++) {
            sum += A[i];
            // System.out.println(""+i+" "+sum);
            if(sum == 0) {
                ans++;
            }
            if(mp.containsKey(sum)) {
                long t = mp.get(sum);
                ans += t;
                mp.put(sum, t+1);
            } else {
                mp.put(sum, (long)1);
            }
            if(ans >= MAX) {
                return (int) MAX;
            }
        }

        return (int) ans;
    }
}