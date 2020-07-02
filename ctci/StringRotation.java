public class StringRotation {

    public static boolean solve(String S1, String S2) {
        String S3 = S1 + S1;
        return S1.length() == S2.length() && S3.contains(S2);
    }
    
}