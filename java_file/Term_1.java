import java.util.Scanner;

public class Term_1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the original string: ");
        String arr = sc.nextLine();

        System.out.println("Enter the index: ");
        int ind = sc.nextInt(); 
        sc.nextLine(); 

        System.out.println("Insert the string you want to add: ");
        String arr1 = sc.nextLine();
        sc.close();

        
        String result = "";
        for (int i = 0; i < ind; i++) {
            result += arr.charAt(i); 
        }
        result += arr1;
        for (int i = ind; i < arr.length(); i++) {
            result += arr.charAt(i); 
        }

        System.out.println("Result: " + result);
    }
}