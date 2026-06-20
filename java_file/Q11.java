import java.util.*;

class Q11 {

   
    void arrayFunc(int[] arr, int target) {
        System.out.println("Pairs of elements whose sum is " + target + " are:");
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] + arr[j] == target) {
                    System.out.println(arr[i] + " + " + arr[j] + " = " + target);
                }
            }
        }
    }

    
    void arrayFunc(int[] A, int p, int[] B, int q) {
        int[] mergedArray = new int[p + q];
        int i = 0, j = 0, k = 0;

      
        while (i < p && j < q) {
            if (A[i] < B[j]) {
                mergedArray[k++] = A[i++];
            } else {
                mergedArray[k++] = B[j++];
            }
        }

        
        while (i < p) {
            mergedArray[k++] = A[i++];
        }
        while (j < q) {
            mergedArray[k++] = B[j++];
        }

       
        for (i = 0; i < p; i++) {
            A[i] = mergedArray[i];
        }

        
        for (j = 0; j < q; j++) {
            B[j] = mergedArray[p + j];
        }

        System.out.println("Updated Array A: " + Arrays.toString(A));
        System.out.println("Updated Array B: " + Arrays.toString(B));
    }

    public static void main(String[] args) {
        Q11 demo = new Q11();
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the size of array : ");
        int size = sc.nextInt();
        System.out.println("Enter the array : ");
        int numbers[] = new int[size];
        for(int i = 0 ; i < size ; i++){
            numbers[i] = sc.nextInt();
        }
        System.out.println("Enter the value of target : ");
        int target = sc.nextInt();
        demo.arrayFunc(numbers, target);
        
        
        System.out.println("Enter the size of array A: ");
        int p = sc.nextInt();
        int[] A = new int[p];
        System.out.println("Enter the elements of array A (sorted): ");
        for (int i = 0; i < p; i++) {
            A[i] = sc.nextInt();
        }

        System.out.println("Enter the size of array B: ");
        int q = sc.nextInt();
        int[] B = new int[q];
        System.out.println("Enter the elements of array B (sorted): ");
        for (int i = 0; i < q; i++) {
            B[i] = sc.nextInt();
        }

        demo.arrayFunc(A, A.length, B, B.length);
    }
}