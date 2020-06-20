import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Euler11 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[][] grid = new int[20][20];
        for(int grid_i=0; grid_i < 20; grid_i++){
            for(int grid_j=0; grid_j < 20; grid_j++){
                grid[grid_i][grid_j] = in.nextInt();
            }
        }
        long max = 0;
        int[][] gridnew = new int[26][26];
        for (int i=0; i<20; i++) {
            for (int j=0; j<20; j++) {
                gridnew[i+3][j+3] = grid[i][j];
            }
        }

        for (int i=3; i<23; i++) {
            for (int j=3; j<23; j++) {
                long prod1 = gridnew[i][j]*gridnew[i+1][j]*gridnew[i+2][j]*gridnew[i+3][j];
                long prod2 = gridnew[i][j]*gridnew[i][j+1]*gridnew[i][j+2]*gridnew[i][j+3];
                long prod3 = gridnew[i][j]*gridnew[i+1][j+1]*gridnew[i+2][j+2]*gridnew[i+3][j+3];
                long prod4 = gridnew[i][j]*gridnew[i-1][j-1]*gridnew[i-2][j-2]*gridnew[i-3][j-3];
                long prod5 = gridnew[i][j]*gridnew[i+1][j-1]*gridnew[i+2][j-2]*gridnew[i+3][j-3];
                long prod6 = gridnew[i][j]*gridnew[i-1][j+1]*gridnew[i-2][j+2]*gridnew[i-3][j+3];
                long max_prod = Math.max(Math.max(prod1, prod2), Math.max(prod3, prod4));
                long max_prod2 = Math.max(max_prod, Math.max(prod5, prod6));
                max = Math.max(max, max_prod2);
            }
        }

        System.out.println(max);
    }
}