import student1.Q15;
import course.Q15a;
import enrollment.Q15b;
 
class Q15c{
    public static void main(String args[]){
        Q15 S1 = new Q15("101","aman",24);
        Q15a C1 = new Q15a("153","Math",3.00);
        Q15b E1 = new Q15b (S1,C1);
        System.out.println(S1.getStudentInfo());
        System.out.println(C1.getCourseInfo());
        System.out.println(E1.getEnrollmentInfo());
    }
}