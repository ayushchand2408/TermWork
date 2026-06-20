import java.util.Scanner;
public class Word_Example {
    private String strdata;

    public Word_Example(String strdata) {
        if (strdata.endsWith(".") || strdata.endsWith("?") || strdata.endsWith("!")) {
            this.strdata = strdata.trim();
        } else {
            System.out.println("Given String is not acceptable");
        }
    }
    public void countWord() {
        String[] words = strdata.split("\\s+");
        int count = 0;
        for (String word : words) {
            if (word.length() > 0 && isVowel(word.charAt(0)) && isVowel(word.charAt(word.length() - 1))) {
                count++;
            }
        }
        System.out.println("Number of words beginning and ending with a vowel: " + count);
    }

    public void placeWord() {
        String[] words = strdata.split("\\s+");
        StringBuilder vowelWords = new StringBuilder();
        StringBuilder otherWords = new StringBuilder();

        for (String word : words) {
            if (word.length() > 0 && isVowel(word.charAt(0)) && isVowel(word.charAt(word.length() - 1))) {
                vowelWords.append(word).append(" ");
            } else {
                otherWords.append(word).append(" ");
            }
        }

        String result = vowelWords.toString().trim() + " " + otherWords.toString().trim();
        System.out.println("Rearranged sentence: " + result);
    }

    private boolean isVowel(char c) {
        return "AEIOUaeiou".indexOf(c) != -1;
    }

    public String getStrdata() {
        return strdata;
    }

    public void setStrdata(String strdata) {
        if (strdata.endsWith(".") || strdata.endsWith("?") || strdata.endsWith("!")) {
            this.strdata = strdata.trim();
        } else {
            System.out.println("Given String is not acceptable");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input;
        System.out.print("Enter the value of striing : ");
        input = sc.nextLine();
        sc.close();

        Word_Example input_array = new Word_Example(input);
        input_array.countWord();
        input_array.placeWord();
    }
}
