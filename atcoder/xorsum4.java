import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class xorsum4 {
    static long MOD = (long)Math.pow(10, 9) + 7;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        long a[] = new long[60];
        long b[] = new long[60];
        for (int i=0; i<N; i++) {
            long val = in.nextLong();
            for(int j=0; j<60; j++) {
                if (val%2==0) {
                    a[j]++;
                } else {
                    b[j]++;
                }
                val /= 2;
            }
        }
        long ans = 0;
        for (int i=0; i<60; i++) {
            long t = (long)Math.pow(2,i) % MOD;
            t = (t * a[i]) % MOD;
            t = (t * b[i]) % MOD;
            ans = (ans + t)%MOD;
        }
        System.out.println(ans);
    }
}