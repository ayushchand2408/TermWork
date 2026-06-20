import java.util.Scanner;

class MyCalculator {
    public int power(int n, int p) throws Exception {
        if (n < 0 || p < 0) {
            throw new Exception("n and p should be non-negative");
        }
        else if(n==0){
            throw new Exception("n cannot be zero");
        }
        return (int) Math.pow(n, p);
    }
}

public class Solution {
    public static void main(String[] args) {
        MyCalculator a1 = new MyCalculator();
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the value of n : ");
        int n = sc.nextInt();
        System.out.println("enter the value of p : ");
        int p = sc.nextInt();

        try {
            System.out.println(a1.power(n, p));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        sc.close();
    }
}