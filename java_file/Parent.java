abstract class hello{
    abstract void shape(int r);
}
class circle extends hello{
    void shape(int r){
        System.out.println("ans : " + 2*3.14*r);
    }
}
 class Parent {
    public static void main(String args[]){
        hello h1 = new circle();
        h1.shape(5);
    }
}
