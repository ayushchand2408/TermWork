package course;
public class Q15a{
    String CourseId , CourseName;
    double credits;
    public Q15a(String CourseId,String CourseName, double credits){
        this.CourseId=CourseId;
        this.CourseName=CourseName;
        this.credits=credits;
    }
    public String getCourseInfo(){
        return "Course Id:-" + CourseId + " CourseName:-" + CourseName + " Credits:-" + credits;
    }
}