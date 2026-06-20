import java.util.Scanner;

class InvalidEmployeeException extends Exception {
    public InvalidEmployeeException(String message) {
        super(message);
    }
}

public class emp{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter Employee ID: ");
            int empId = scanner.nextInt();
            scanner.nextLine(); 

            System.out.print("Enter Employee Name: ");
            String empName = scanner.nextLine();

            System.out.print("Enter Department ID: ");
            int deptId = scanner.nextInt();

            if (empId < 2001 || empId > 5001) {
                throw new InvalidEmployeeException("Employee ID must be between 2001 and 5001.");
            }

            if (empName.isEmpty() || !Character.isUpperCase(empName.charAt(0))) {
                throw new InvalidEmployeeException("Employee Name must start with a capital letter.");
            }

            if (deptId < 1 || deptId > 5) {
                throw new InvalidEmployeeException("Department ID must be an integer between 1 and 5.");
            }

            System.out.println("Employee Details:");
            System.out.println("ID: " + empId);
            System.out.println("Name: " + empName);
            System.out.println("Department ID: " + deptId);

        } catch (InvalidEmployeeException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Error: Invalid input provided.");
        } finally {
            scanner.close();
        }
    }
}
