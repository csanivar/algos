import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Euler5 {

    static int[] primes = new int[]{2,3,5,7,11,13,17,19,23,29,31,37};
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int num = 1;
            for (int p : primes) {
                num *= Math.pow(p, getHighestPower(n, p));
            }
            System.out.println(num);
        }
    }

    private static int getHighestPower(int x, int p) {
        int pow = 0;
        while (true) {
            if (Math.pow(p, pow) > x) {
                return pow-1;
            }
            pow++;
        }
    }
}