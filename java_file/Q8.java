import java.util.Scanner;

public class Q8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String check = sc.nextLine();
        sc.close();
        int len = check.length();
        int count = 0;

        for (int i = 0; i < len - 2; i++) {
            if (check.charAt(i) == '0') {
                for (int j = i + 2; j < len; j++) {
                    if (check.charAt(j) == '0' && (j - 1 >= 0 && check.charAt(j - 1) != '0')) {
                        for (int k = i; k <= j; k++) {
                            System.out.print(check.charAt(k));
                        }
                        System.out.println();
                        i = j;
                        count++;
                    }
                }
            }
        }

        System.out.print("Count: " + count);
    }
}
