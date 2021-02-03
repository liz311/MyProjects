import java.util.Date;
import java.util.Scanner;

/* Created By Lizzy Asis */

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student(12, "Eli", "Choen", "eli@gmail.com");
        Teacher t1 = new Teacher(12, "Avi", "Choen", "avi@gmail.com", "10-12");
        System.out.println(s1.getFirstName());
        s1.setFirstName("Alon");
        System.out.println(s1.getFirstName());

        Course c1 = new Course("Programming", 123, 5, t1, 50);
        s1.insertGrade(c1, 100);
        Course c2 = new Course("Database", 125, 5, t1, 30);
        s1.insertGrade(c2, 90);

        System.out.println(s1.getAverage());


    }
}
