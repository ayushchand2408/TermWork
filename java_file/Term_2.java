import java.util.Scanner;

public class Term_2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        boolean check = false;
        System.out.print("Enter the first string : ");
        String arr = sc.nextLine();
        System.out.print("Enter Second String : ");
        StringBuilder arr1 = new StringBuilder(sc.nextLine());
        sc.close();
        if(arr.length() != arr1.length()){
            System.out.println("both Strings are not an anagaram of each other ");
        }else{
            for(int i = 0 ; i < arr.length() ; i++){
                check = false;
                for(int j = 0 ; j < arr.length() ; j++){
                    if(arr.charAt(i) == arr1.charAt(j)){
                        check = true;
                        arr1.setCharAt(j, '0');
                        break;
                    }
                }
                if(!check){
                    System.out.println("both Strings are not an anagaram of each other ");
                    return;
                }
            }
            System.out.println("both Strings are anagaram of each other ");
        }
    }
        
}
