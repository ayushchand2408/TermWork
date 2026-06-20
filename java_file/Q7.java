import java.util.Scanner;
public class Q7{
    public static int saddle_element(int arr[][] ){
        int min,f ;
        for(int i  =0 ; i < arr.length ; i++){
            boolean check = true;
            min = arr[i][0];
            f = 0;
            for(int j = 0 ; j < arr[i].length ; j++){
                if(min > arr[i][j]){
                    min = arr[i][j];
                    f = j;
                }
            }
            int j = 0;
            while(j < arr.length){ 
                if(min < arr[j][f] ){
                    check = false;
                    break; 
                }
                j++;
            }
            if(check){
                return min;
            }
        }
        return -1;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("enter the number of rows : ");
        int n = sc.nextInt();
        System.out.print("enter the number of column : ");
        int m = sc.nextInt();
        int arr[][] = new int[n][m];
        for(int i = 0 ; i < arr.length ; i++){
            for(int j = 0 ; j < arr[i].length ; j++){
                arr[i][j]=sc.nextInt();
            }
        }
        sc.close();
        int element = saddle_element(arr);
        if(element != -1){
            System.out.println("Saddle element : " + element);
        }else{
            System.out.println("there is no saddle element ");
        }
    }
}