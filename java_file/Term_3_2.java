import java.util.Arrays;
import java.util.Scanner;

public class Term_3_2 {
    public static String sortString(String str) {
        char[] charArray = str.toCharArray();
        Arrays.sort(charArray);
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