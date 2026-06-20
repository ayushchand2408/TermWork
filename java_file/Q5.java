import java.util.Scanner;

public class Q5 {
    public static void zigzag(int[] arr) {
        boolean flag = true; 
        for (int i = 0; i < arr.length - 1; i++) {
            if (flag) { 
                if (arr[i] > arr[i + 1]) {
                  
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            } else { 
                if (arr[i] < arr[i + 1]) {
        
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
            flag = !flag; 
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size: ");
        int size = sc.nextInt();
        int arr[] = new int[size];

        System.out.println("Enter values of array: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        zigzag(arr);

        System.out.print("Zigzag array: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
