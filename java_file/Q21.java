import java.util.*;

public class Q21 {
    public void removeEvenLength(ArrayList<String> list) {
        Iterator<String> it = list.iterator();
        while (it.hasNext()) {
            String str = it.next();
            if (str.length() % 2 == 0) {
                it.remove();
            }
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
        Q21 obj = new Q21();
        obj.removeEvenLength(list);

        System.out.println("Filtered list: " + list);
    }
}
