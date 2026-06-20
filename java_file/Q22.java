import java.util.ArrayList;
import java.util.Scanner;

public class Q22 {
    public void swap(ArrayList<String> list){
        for(int i=0;i<list.size()-1;i+=2){
            String str=list.get(i);
            list.set(i,list.get(i+1));
            list.set(i+1,str);
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        ArrayList<String> list = new ArrayList<String>();
        System.out.print("Enter number of Elements: ");
        int n=sc.nextInt();
        sc.nextLine();
        for(int i=0;i<n;i++){
            System.out.print("Enter element: ");
            String str=sc.nextLine();
            list.add(str);
        }
        System.out.println("Original List: "+list);
        Q22 obj=new Q22();
        obj.swap(list);
        System.out.println("Swapped List: "+list);
    }
}
