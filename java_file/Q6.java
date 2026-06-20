import java.util.Scanner;
public class Q6 {
    public static void sort(int[] arr,int n){
        for(int i = 0 ; i < n -1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(arr[j] < 0){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
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
    sort(arr,size);
    System.out.println("Modified array : ");
    for (int i = 0; i < size; i++) {
        System.out.print(arr[i] + " ");
    }

   }
}
