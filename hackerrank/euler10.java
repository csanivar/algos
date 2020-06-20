import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Euler10 {
    static int MAX = 100000000;
    public static void main(String[] args) {
        boolean prime[] = new boolean[MAX+1];
        for (int i=0; i<=MAX; i++) prime[i] = true;
        for (int i=2; i*i<=MAX; i++) {
            if(prime[i]) {
                for (int j=i*i; j<=MAX; j+=i) prime[j] = false;
            }
        }

        long sums[] = new long[MAX+1];
        sums[0] = sums[1] = 0;
        for (int i=2; i<=MAX; i++) {
            if (prime[i]) sums[i] = sums[i-1] + i;
            else sums[i] = sums[i-1];
        }

        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            System.out.println(sums[n]);
        }
    }
}