import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        // I tried my damned-est to get this regex to work, but the word "receipt" presents problems.  I'm moving on.
        // Pattern p = Pattern.compile(
        //     "^(ie)?([^cie]|(cei)|([^c]ie)|(c[^i])|(ci[^e])|(e[^ic])|(ec[^ei]|e|())|(i[^e]))*$",
        //     Pattern.CASE_INSENSITIVE
        // );
        for(String s : args) {
            if (!followsRule(s)) {
                System.out.println("Invalid: " + s);
            }
        }
    }

    private static boolean followsRule(String s) {
        for(int i=0; i < s.length(); i++) {
            int thisChar = s.charAt(i);

            // the defaulting to 'a' on these is hacky, but it works with the logic
            int nextChar = i < s.length() - 1 ? s.charAt(i+1) : 'a';
            int prevChar = i > 0 ? s.charAt(i-1) : 'a';

            if (!(thisChar == 'i' || thisChar == 'e')) {
                continue;
            }

            if (thisChar == 'i') {
                if (nextChar == 'e' && prevChar == 'c') {
                    return false;
                }
            } else if (nextChar == 'i' && prevChar != 'c') {
                return false;
            }
        }
        return true;
    }
}
