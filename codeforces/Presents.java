import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Presents {
    static long MOD = (long)Math.pow(10, 9) + 7;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int arr[] = new int[N];
        for (int i=0; i<N; i++) {
            int a = in.nextInt();
            arr[a-1] = i+1;
        }
        for (int i=0; i<N; i++) {
            System.out.print(arr[i]);
            if (i!=N-1) System.out.print(" ");
        }
    }
}