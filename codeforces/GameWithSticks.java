import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class GameWithSticks {
    static long MOD = (long)Math.pow(10, 9) + 7;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int min = Math.min(n, m);
        if(min%2==0) {
            System.out.println("Malvika");
        } else {
            System.out.println("Akshat");
        }
    }
}