import java.util.*;

public class Q23 {
    LinkedList<Integer> list3=new LinkedList<Integer>();
    public void alternate(LinkedList<Integer> list1,LinkedList<Integer> list2){
        int m=list1.size(),i=0;
        int n=list2.size(),j=0;
        while(i<m && j<n){
            list3.addLast(list1.get(i++));
            list3.addLast(list2.get(j++));
        }
        while(i<m){
            list3.addLast(list1.get(i++));
        }
        while(j<n){
            list3.addLast(list2.get(j++));
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int m=0;
        LinkedList<Integer> list1=new LinkedList<Integer>();
        System.out.print("Enter number of Elements in list1: ");
        m=sc.nextInt();
        System.out.print("Enter Elements in list1: ");
        for(int i=0;i<m;i++){
            list1.addLast(sc.nextInt());
        }
        int n=0;
        LinkedList<Integer> list2=new LinkedList<Integer>();
        System.out.print("Enter number of Elements in list2: ");
        n=sc.nextInt();
        System.out.print("Enter Elements in list2: ");
        for(int i=0;i<n;i++){
            list2.addLast(sc.nextInt());
        }
        Q23 obj=new Q23();
        obj.alternate(list1, list2);
        System.out.println("List 1: "+list1);
        System.out.println("List 2: "+list2);
        System.out.println("List 3: "+obj.list3);
    }
}

