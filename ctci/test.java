import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class test {
    static long MOD = (long)Math.pow(10, 9) + 7;
    public static void main(String[] args) {
        // urlify();
        // oneAway();
        // stringCompression();
        // rotateMatrix();
        // zeroMatrix();
        stringRotation();
    }

    public static void zeroMatrix() {
        int[][] mat = {
            {1, 2, 0},
            {4, 0, 6},
            {7, 8, 9}
        };
        mat = ZeroMatrix.solve(mat);
        for(int i=0; i<mat.length; i++) {
            for(int j=0; j<mat[0].length; j++) {
                System.out.print(""+mat[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static void stringRotation() {
        String S1 = "erbottlewat";
        String S2 = "waterbottle";
        System.out.println(StringRotation.solve(S1, S2));
    }

    public static void rotateMatrix() {
        int[][] img = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        int [][] img2 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15 ,16}
        };
        img = RotateMatrix.solve(img2);

        for(int i=0; i<img.length; i++) {
            for(int j=0; j<img.length; j++) {
                System.out.print(""+img[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static void stringCompression() {
        String S = "aabcccccaaa";
        System.out.println(StringCompression.solve(S));
    }

    public static void oneAway() {
        String s1 = "pale";
        String s2 = "paake";
        System.out.println(OneAway.solve(s1, s2));
    }

    public static void urlify() {
        String S = "Mr John Smith    ";
        char[] res = URLify.solve(S.toCharArray());
        for(int i=0; i<res.length; i++) {
            System.out.print(res[i]);
        }
    }

    public static void palindromePermutation() {
        String s = "Tact Coad";
        System.out.println(PalindromePermutation.solve(s));
    }

    public static void checkPermutation() {
        String s1 = "abcd";
        String s2 = "dcba";
        System.out.println(CheckPermutation.solve(s1, s2));
    }
}