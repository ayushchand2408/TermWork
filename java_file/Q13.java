import java.util.Scanner;
abstract class Temperature {
    double temp;
    
    void setTempData(double val) {
        temp = val;
    }
    
    abstract void changeTemp(double temp);
}

class Fahrenheit extends Temperature {
    double ftemp;

    void changeTemp(double temp) {
        ftemp = 5.0 / 9.0 * (temp - 32);
        System.out.println("Temperature in Celsius: " + ftemp);
    }
}

class Celsius extends Temperature {
    double ctemp;
    
    void changeTemp(double temp) {
        ctemp = (9.0 / 5.0) * temp + 32;
        System.out.println("Temperature in Fahrenheit: " + ctemp);
    }
}

public class Q13 {
    public static void main(String args[]) {
       
        Scanner sc = new Scanner(System.in);

        Temperature t1 = new Fahrenheit();
        System.out.println("Enter the temperature in Fahrenheit: ");
        double fahrenheitTemp = sc.nextDouble();
        t1.setTempData(fahrenheitTemp);
        t1.changeTemp(fahrenheitTemp);

        Temperature t2 = new Celsius();
        System.out.println("Enter the temperature in Celsius: ");
        double celsiusTemp = sc.nextDouble();
        t2.setTempData(celsiusTemp);
        t2.changeTemp(celsiusTemp);

        sc.close();

    }
}
