import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Term_8 {
    public static boolean isValidEmail(String email) {
        String emailRegex = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,6}$";
        Pattern pattern = Pattern.compile(emailRegex);
        Matcher matcher = pattern.matcher(email);
        
        return matcher.matches();
    }

    public static void main(String[] args) {
        String[] testEmails = {"test@example.com", "invalid_email.com", "user@domain", "hello@abc.xyz"};

        for (String email : testEmails) {
            if (isValidEmail(email))
                System.out.println(email + " -> Valid Email");
            else
                System.out.println(email + " -> Invalid Email");
        }
    }
}