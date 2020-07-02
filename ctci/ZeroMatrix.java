public class ZeroMatrix {
    
    public static int[][] solve(int[][] mat) {
        int N = mat.length;
        int M = mat[0].length;
        boolean row_flag = false, col_flag = false;
        for(int row=0; row<N; row++) {
            if(mat[row][0] == 0) {
                row_flag = true;
                break;
            }
        }
        for(int col=0; col<M; col++) {
            if(mat[0][col] == 0) {
                col_flag = true;
                break;
            }
        }
        for(int row=0; row<N; row++) {
            for(int col=0; col<M; col++) {
                if(mat[row][col] == 0) {
                    mat[row][0] = 0;
                    mat[0][col] = 0;
                }
            }
        }
        for(int row=1; row<N; row++) {
            for(int col=1; col<M; col++) {
                if(mat[row][0] == 0 || mat[0][col] == 0) {
                    mat[row][col] = 0;
                }
            }
        }
        if(row_flag) {
            for(int row=0; row<N; row++) {
                mat[row][0] = 0;
            } 
        }
        if(col_flag) {
            for(int col=0; col<M; col++) {
                mat[0][col] = 0;
            }
        }
        return mat;
    }
}