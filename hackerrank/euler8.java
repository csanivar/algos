import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Euler8 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int k = in.nextInt();
            String num = in.next();
            int max = 0;
            for (int i=0; i<=num.length()-k; i++) {
                int product = 1;
                for (int j=0; j<k; j++) {
                    product *= Character.getNumericValue(num.charAt(i+j));
                }
                if (product > max) max = product;
            }
            System.out.println(max);
        }
    }
}