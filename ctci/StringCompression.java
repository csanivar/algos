public class StringCompression {
    public static String solve(String S) {
        StringBuilder strb = new StringBuilder();

        char cur = S.charAt(0);
        int cnt = 0;
        for(int i=0; i<S.length(); i++) {
            if(cur == S.charAt(i)) {
                cnt++;
            } else {
                strb.append(cur+""+cnt);
                cur = S.charAt(i);
                cnt = 1;
            }
        }
        strb.append(cur+""+cnt);

        return S.length() > strb.toString().length() ? strb.toString() : S;
    }
}