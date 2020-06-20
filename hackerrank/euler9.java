import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Euler9 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int a, b, c;
            int max = -1;
            for (a=1; a<n/3; a++) {
                b = n*(2*a-n)/(2*(a-n));
                c = n - b - a;
                if (a*a + b*b == c*c) {
                    int prod = a*b*c;
                    if (prod > max) max = prod;
                }
            }
            System.out.println(max);
        }
    }
}