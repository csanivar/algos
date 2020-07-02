import java.lang.Math;

public class OneAway {
   public static boolean solve(String s1, String s2) {
       int n1 = s1.length(), n2 = s2.length();
       if(Math.abs(n1 - n2) > 1) return false;
       int i = 0, j = 0;
       boolean flag = false;
       while(i<n1 && j<n2) {
            if(s1.charAt(i) == s2.charAt(j)) {
                i++;
                j++;
            } else {
                if(flag) return false;
                flag = true;
                if(n1 > n2) i++;
                if(n2 > n1) j++;
                if(n1 == n2) {
                    i++;
                    j++;
                }
            }
       }

       return true;
   } 
}