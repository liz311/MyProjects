import java.util.ArrayList;
import java.util.HashMap;

/* Created By Lizzy Asis */

public class Student extends User {
    private ArrayList<Course> courses;
    private HashMap<Course, Integer> grades = new HashMap<>();


    public Student(int id, String firstName, String lastName, String email){
        super(id, firstName, lastName, email);
    }

    public void insertGrade(Course course, int grade){
        courses.add(course);
        grades.put(course,grade);
    }

    public double getAverage(){
        double sum = 0;
        for (int grade : grades.values()) {
            sum += grade;
        }
        return sum / grades.size();
    }
}
