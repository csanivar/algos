import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class tap1 {
    static long MOD = (long)Math.pow(10, 9) + 7;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        String s = in.next();
        String t = in.next();
        for (int i=0; i<N; i++) {
            System.out.print(s.charAt(i));
            System.out.print(t.charAt(i));
        }
    }
}

class Solution {
    public int solution(String S, int[] X, int[] Y) {
        // write your code in Java SE 8
        int[] minx = new int[26];
        int[] maxx = new int[26];
        for(int i=0; i<26; i++) {
            minx[i] = Integer.MAX_VALUE;
            maxx[i] = Integer.MIN_VALUE;
        }
        for(int i=0; i<S.length(); i++) {
            int dist = Math.sqrt(X[i]*X[i] + Y[i]*Y[i]);
            int index = S.charAt(i) - 'A';
            minx[index] = 
        }
    }
}