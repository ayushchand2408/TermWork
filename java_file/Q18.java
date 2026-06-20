import java.io.*;
import java.util.*;

public class Q18 {
    public static void main(String[] args) {
        String fileName = "myfile.txt";
        int palindromeCount = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] words = line.split("\\s+");
                for (String word : words) {
                    if (isPalindrome(word)) {
                        palindromeCount++;
                        System.out.println(word); 
                    }
                }
            }
            System.out.println("Total Palindromes: " + palindromeCount);
        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }
    }

    private static boolean isPalindrome(String word) {
        word = word.toLowerCase();
        int left = 0, right = word.length() - 1;
        while (left < right) {
            if (word.charAt(left) != word.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
