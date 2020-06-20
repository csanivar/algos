import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Euler7 {
    static int MAX = 100000000;
    public static void main(String[] args) {
        boolean prime[] = new boolean[MAX+1];
        for (int i=0; i<=MAX; i++) prime[i] = true;
        for (int i=2; i*i<=MAX; i++) {
            if(prime[i]) {
                for (int j=i*i; j<=MAX; j+=i) prime[j] = false;
            }
        }
        List<Integer> primes = new ArrayList<>();
        for (int i=2; i<=MAX; i++) {
            if (prime[i]) primes.add(i);
        }

        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            System.out.println(primes.get(n-1));
        }
    }
}