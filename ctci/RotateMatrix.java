public class RotateMatrix {

    public static int[][] solve(int[][] img) {
        int N = img.length;
        int len = N % 2 == 0 ? N/2 : N/2 + 1;
        for (int i=0; i<len; i++) {
            for(int j=0; j<N/2; j++) {
                int[] x = new int[]{i, N-1-j, N-1-i, j};
                int[] y = new int[]{j, i, N-1-j, N-1-i};
                int next = img[x[3]][y[3]];
                for(int k=0; k<4; k++) {
                    int idx = (k+1)%4;
                    int temp = next;
                    next = img[x[k]][y[k]];
                    img[x[k]][y[k]] = temp;
                }
            }
        }

        return img;
    }
    
}