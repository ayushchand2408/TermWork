import java.util.Scanner;
public class Q4 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Input : ");
        int value= sc.nextInt();
        sc.close();
        int result=0,place=1;
        while(value > 0){
            int digit = value%10;
            if(digit == 0){
                result = result+place;
            }else{
                result = result+digit*place;
            }
            place = place * 10;
            value  = value/10;
        }
        System.out.println("Output : " + result);
    }
}

