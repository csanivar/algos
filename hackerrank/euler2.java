import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Euler2 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        long input[] = new long[t];
        long max = 0;
        for(int a0 = 0; a0 < t; a0++){
            input[a0] = in.nextLong();
            if (input[a0] > max) max = input[a0];
        }
        List<Long> seq = genereateFibonacci(max);
        for(int a0 = 0; a0 < t; a0++){
            System.out.println(getSumOfEvens(input[a0], seq));
        }
    }

    private static List<Long> genereateFibonacci(long max) {
        List<Long> res = new ArrayList<>();
        res.add(1L);
        res.add(2L);
        int index = 2;
        while(true) {
            long val = res.get(index-1) + res.get(index-2);
            if (val > max) break;
            res.add(val);
            index++;
        }
        return res;
    }

    private static long getSumOfEvens(long max2, List<Long> fibSeq) {
        long sum = 0;
        for (long val : fibSeq) {
            if (val > max2) break;
            if (val%2 == 0) sum += val;
        }
        return sum;
    }
}

