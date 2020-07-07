import java.util.HashMap;
import java.util.Scanner;

public class PTMSSNG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T, N, x, y;
        T = sc.nextInt();
        int rx = 0, ry = 0;
        while (T-- > 0) {
            N = sc.nextInt();
            N = 4*N - 1;
            while(N-- > 0) {
                x = sc.nextInt();
                y = sc.nextInt();
                rx ^= x;
                ry ^= y;
            }
            System.out.println(""+rx+" "+ry);
             rx = 0; ry = 0;
        }
    }
}
