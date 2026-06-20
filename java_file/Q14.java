interface I1{
    void volume();
}

class Cone implements I1{
    double height,radius;
    Cone(double height , double radius){
        this.height = height;
        this.radius= radius;
    }

    public void volume(){
        System.out.println ("Volume of Cone : " + (1.0/3.0)*3.14*radius * (2*height));
    }

}
class Hemisphere implements I1{
    double radius;
    Hemisphere( double radius){
        this.radius= radius;
    }

    public void volume(){
        System.out.println ("Volume of Hemisphere : " + (2.0/3.0) * 3.14 * (radius * radius *radius));
    }
}

class Cylinder implements I1{
    double height,radius;
    Cylinder(double height , double radius){
        this.height = height;
        this.radius= radius;
    }

    public void volume(){
        System.out.println ("Volume of Cylinder : " + 3.14 * (radius * radius) * height);
    }
}
    
public class Q14{
    public static void main(String args[]){
        I1 d = new Cone(4.0,5.0);
        d.volume();
        d = new Hemisphere(6.0);
        d.volume();
        d = new Cylinder(6.0,7.0);
        d.volume();
    }
}