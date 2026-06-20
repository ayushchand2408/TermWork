import java.util.Scanner;

class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the first number: ");
        int num1 = sc.nextInt();
    
        System.out.print("Enter the second number: ");
        int num2 = sc.nextInt();
        
        int sum1 = findSumOfDivisors(num1);
        
        int sum2 = findSumOfDivisors(num2);
        
        if (sum1 == num1 && sum2 == num2) {
            System.out.println("Abundant number");
        } else {
            System.out.println("not a abundant number");
        }
        sc.close();
    }
    
    public static int findSumOfDivisors(int num) {
        int sum = 0;
        for (int i = 1; i <= num -1; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        return sum;
    }
}

