import java.util.Scanner;

class InvalidEmployeeException extends Exception {
    public InvalidEmployeeException(String message) {
        super(message);
    }
}

public class Q16 {
    public static void main(String args[]){
     
        try{
            Scanner sc = new Scanner(System.in);
            System.out.println("enter the employee id : ");
            int Emp_id = sc.nextInt();
            sc.nextLine();
            System.out.println("enter the employee name : ");
            String Emp_name = sc.nextLine();

            System.out.println("enter the department id : ");
            int Dep_id = sc.nextInt();
            sc.nextLine();
            sc.close();
            if (Emp_id < 2001 || Emp_id > 5001) {
                throw new InvalidEmployeeException("Employee ID must be between 2001 and 5001.");
            }
    
            if (Emp_name.isEmpty() || !Character.isUpperCase(Emp_name.charAt(0))) {
                throw new InvalidEmployeeException("Employee Name must start with a capital letter.");
            }
    
            if (Dep_id < 1 || Dep_id > 5) {
                throw new InvalidEmployeeException("Department ID must be an integer between 1 and 5.");
            }
    
            System.out.println("Employye_ID :- " + Emp_id);
            System.out.println("Employye_Name :- " + Emp_name);
            System.out.println("department_ID :- " + Dep_id);

        }catch(InvalidEmployeeException e){
            System.out.println("Error " + e.getMessage());
        }
        catch(Exception e){
            System.out.println("Error : invalid Input");
        }finally{
            
        }   
    }
}
