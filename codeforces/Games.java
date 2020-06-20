import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Games {
    static long MOD = (long)Math.pow(10, 9) + 7;

    static class Pair {
        public int a;
        public int b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        ArrayList list = new ArrayList<Pair>(N);
        for(int i=0;i<N;i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            list.add(new Pair(a,b));
        }
        int ans = 0;
        for(int i=0; i<N; i++) {
            Pair p1 = (Pair) list.get(i);
            for (int j=i+1; j<N; j++) {
                Pair p2 = (Pair) list.get(j);
                if(p1.a == p2.b) {
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}