public class PalindromePermutation {
    
    public static boolean solve(String S) {
        int[] arr = new int[128];
        for(int i=0; i<S.length(); i++) {
            if(S.charAt(i) == ' ') continue;
            int c = Character.toLowerCase(S.charAt(i));
            arr[c] += 1;
        }

        boolean flag = false;
        for(int i=0; i<128; i++) {
            if(arr[i]%2 != 0) {
                if(flag == true) return false;
                flag = true;
            }
        }

        return true;
    }
}