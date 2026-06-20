import java.util.Scanner;

public class Term_3_1 {
    public static String sortString(String str) {
        char[] charArray = str.toCharArray();
        int n = charArray.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (charArray[j] > charArray[j + 1]) {
                    
                    char temp = charArray[j];
                    charArray[j] = charArray[j + 1];
                    charArray[j + 1] = temp;
                }
            }
        }
        return new String(charArray);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        scanner.close();

        String sortedString = sortString(input);
        System.out.println("Sorted String: " + sortedString);
    }
}