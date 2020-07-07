import java.util.*;

public class Solution3 {
    public static int solve(int[] A) {
        HashMap<Integer, Integer> cities = new HashMap<>();
        for(int i=0; i<A.length; i++) {
            cities.put(A[i], 1);
        }
        int missing = cities.size();
        int cur_i = 0, result_i = 0, result_j = 0;
        for(int cur_j = 0; cur_j < A.length; cur_j++) {
            if(cities.get(A[cur_j]) > 0) {
                missing--;
            }
            cities.put(A[cur_j], cities.get(A[cur_j])-1);
            if(missing == 0) {
                while(cur_i < cur_j && cities.get(A[cur_i]) < 0) {
                    cities.put(A[cur_i], cities.get(A[cur_i])+1);
                    cur_i++;
                }
                if(result_j == 0 || cur_j - cur_i <= result_j - result_i) {
                    result_j = cur_j;
                    result_i = cur_i;
                }
            }
        }
        System.out.println(result_j+" "+result_i);
        return result_j - result_i + 1;
    }
}