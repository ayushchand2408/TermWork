import java.util.Scanner;
abstract class Shape {
    abstract double rectangle_Area(double length , double breadth);
    abstract double square_Area(double length);
    abstract double circle_Area(double radius);

}
class Q12 extends Shape{
    double rectangle_Area(double length , double breadth){
        return length * breadth;
    }
    double square_Area(double length){
        return length *length;
    }
    double circle_Area(double radius){
        return 3.14f * (radius *radius);
    }
    public static void main(String args[]){
        Shape a1 = new Q12();
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the length of the rectangle: ");
        double length = sc.nextDouble();
        System.out.println("Enter the breadth of the rectangle: ");
        double breadth = sc.nextDouble();
        System.out.println("Area of the rectangle: " + a1.rectangle_Area(length, breadth));

        System.out.println("Enter the side of the square: ");
        double side = sc.nextDouble();
        System.out.println("Area of the square: " + a1.square_Area(side));
        
        System.out.println("Enter the radius of the circle: ");
        double radius = sc.nextDouble();
        System.out.println("Area of the circle: " + a1.circle_Area(radius));

        sc.close();


    }
         
}
