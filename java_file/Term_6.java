import java.util.HashSet;

public class Term_6 {
    public static void generatePermutations(String str, int left, int right, HashSet<String> resultSet) {
        if (left == right) {
            resultSet.add(str);
            return;
        }
        
        for (int i = left; i <= right; i++) {
            str = swap(str, left, i);
            generatePermutations(str, left + 1, right, resultSet);
            str = swap(str, left, i); 
        }
    }

    public static String swap(String str, int i, int j) {
        char[] charArray = str.toCharArray();
        char temp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = temp;
        return new String(charArray);
    }

    public static void main(String[] args) {
        String input = "abc";
        HashSet<String> resultSet = new HashSet<>();
        generatePermutations(input, 0, input.length() - 1, resultSet);

        for (String perm : resultSet) {
            System.out.println(perm);
        }
    }
}