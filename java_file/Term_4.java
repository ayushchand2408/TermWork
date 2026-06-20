import java.util.HashMap;

public class Term_4 {
    public static int countEqualSubstrings(String str) {
        HashMap<String, Integer> prefixMap = new HashMap<>();
        int count = 0, zero = 0, one = 0, two = 0;

        prefixMap.put("0,0", 1);

        for (char ch : str.toCharArray()) {
            if (ch == '0') zero++;
            else if (ch == '1') one++;
            else if (ch == '2') two++;

            String key = (zero - one) + "," + (zero - two);

            count += prefixMap.getOrDefault(key, 0);

            prefixMap.put(key, prefixMap.getOrDefault(key, 0) + 1);
        }

        return count;
    }

    public static void main(String[] args) {
        String str = "102100211";
        System.out.println("Count of valid substrings: " + countEqualSubstrings(str));
    }
}