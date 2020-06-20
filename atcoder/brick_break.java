import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class BrickBreak {
    static long MOD = (long)Math.pow(10, 9) + 7;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int cur = 1;
        for (int i=0; i<N; i++) {
            if(cur == in.nextInt()) {
                cur++;
            }
        }
        if (cur==1) System.out.println(-1);
        else System.out.println(N-cur+1);
    }
}