import java.util.*;

class Euler1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t--!=0) {
            int N = sc.nextInt();
            Long sum = 0L;
            sum += getSumOfMultiples(N, 3);
            sum += getSumOfMultiples(N, 5);
            sum -= getSumOfMultiples(N, 15);
            System.out.println(sum);
        }
    }
    private static Long getSumOfMultiples(int N, int n) {
        int x = N/n;
        if (N%n==0) x--;
        return (long)n*x*(x+1)/2;
    }
}