import java.util.ArrayList;

/* Created By Lizzy Asis */

public class Teacher extends User {
    private String officeHour;
    private ArrayList<Course> courses;

    public Teacher(int id, String firstName, String lastName, String email, String officeHour) {
        super(id, firstName, lastName, email);
        this.officeHour = officeHour;
    }

    public String getOfficeHour() {
        return officeHour;
    }

    public void setOfficeHour(String officeHour) {
        this.officeHour = officeHour;
    }

    public ArrayList<Course> getCourses() {
        return courses;
    }

    public void setCourses(ArrayList<Course> courses) {
        this.courses = courses;
    }
}
