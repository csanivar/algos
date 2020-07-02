public class CheckPermutation {
    public static boolean solve(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        int[] c1 = new int[128];
        int[] c2 = new int[128];

        for(int i=0; i<s1.length(); i++) {
            int char1 = (int) s1.charAt(i);
            int char2 = (int) s2.charAt(i);
            c1[char1] += 1;
            c2[char2] += 1;
        }

        for(int i=0; i<128; i++) {
            if (c1[i] != c2[i]) return false;
        }

        return true;
    }
}