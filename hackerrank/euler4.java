import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Euler4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        List<Integer> pals = new ArrayList<>();
        for (int i=100; i<=999; i++) {
            for (int j=i; j<=999; j++) {
                int val = i*j;
                if (isPalindrome(val)) pals.add(val);
            }
        }
        Collections.sort(pals);
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int res = pals.get(0);
            for (int pal : pals) {
                if (pal >= n) break;
                res = pal;
            }
            System.out.println(res);
        }
    }

    private static boolean isPalindrome(int x) {
        String s = String.valueOf(x);
        for (int i=0; i<s.length()/2; i++) {
            if (s.charAt(i) != s.charAt(s.length()-1-i)) return false;
        }
        return true;
    }
}