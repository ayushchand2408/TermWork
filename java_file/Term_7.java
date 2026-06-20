import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Term_7 {
    public static int countWordOccurrences(String sentence, String word) {
        Pattern pattern = Pattern.compile("\\b" + word + "\\b", Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(sentence);
        
        int count = 0;
        while (matcher.find()) {
            count++;
        }
        
        return count;
    }

    public static void main(String[] args) {
        String sentence = "I love my city. My city is clean. It is a popular city.";
        String word = "city";

        int occurrence = countWordOccurrences(sentence, word);
        System.out.println("Occurrence of '" + word + "' is: " + occurrence);
    }
}