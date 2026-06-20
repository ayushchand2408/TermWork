package student1;

public class Q15 {
    String StudentId, name;
    int age;

    public Q15(String StudentId, String name, int age) {
        this.StudentId = StudentId;
        this.name = name;
        this.age = age;
    }

    public String getStudentInfo() {
        return "StudnetId:-" + StudentId + " Name:-" + name + " Age:-" + age;
    }
}