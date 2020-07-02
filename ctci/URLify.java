public class URLify {

    public static char[] solve(char[] in) {
        int N = in.length;
        int cnt = 0;
        for(int j=N-1; j>=0; j--) {
            if(in[j] == ' ') {
                cnt++;
            } else {
                break;
            }
        }
        for(int j=N-cnt-1; j>=0; j--) {
            if(in[j] != ' ') {
                in[j+cnt] = in[j];
            } else {
                in[j+cnt] = '0';
                in[j+cnt-1] = '2';
                in[j+cnt-2] = '%';
                cnt -= 2;
            }
        }
        return in;
    }
    
}