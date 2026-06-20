package enrollment;

import student1.Q15;
import course.Q15a;

public class Q15b{
    Q15 s1;
    Q15a c1;
    public Q15b(Q15 s1,Q15a c1){
        this.s1=s1;
        this.c1=c1;
    }
    public String getEnrollmentInfo(){
        return "Enrollment info"+s1.getStudentInfo()+"\n"+c1.getCourseInfo();
    }
}
