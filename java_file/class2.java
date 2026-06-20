package p1.p2;

import p1.class1; // Regular import for class1
import static p1.class1.fahToCel; // Static import for the static method
import java.util.Scanner;

public class class2 {
    public void demonstrate() {
        class1 obj = new class1();
        Scanner sc = new Scanner(System.in);
        int temp = sc.nextInt();
        sc.nextLine();
        sc.close();

        // Use the instance method to convert Celsius to Fahrenheit
        float fahrenheit = obj.celToFah(temp); // Example: 37°C
        System.out.println("Celsius to Fahrenheit: " + fahrenheit);

        // Use the static method (directly via static import) to convert Fahrenheit to Celsius
        float celsius = fahToCel(98.6f); // Example: 98.6°F
        System.out.println("Fahrenheit to Celsius: " + celsius);
    }
}