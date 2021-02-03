import java.util.ArrayList;

/* Created By Lizzy Asis */

public class Course {
    private String name;
    private int id;
    private int points;
    private int averageGrade;
    private Teacher teacher;
    private int maxStudents;
    private int numOfStudent;
    private ArrayList<Student> students;

    public Course(String name, int id, int points, Teacher teacher, int numOfStudent) {
        this.name = name;
        this.id = id;
        this.points = points;
        this.teacher = teacher;
        this.numOfStudent = numOfStudent;
    }

    public void insertToCourse(Student student){
        if(numOfStudent + 1 <= maxStudents) {
            students.add(student);
            numOfStudent += 1;
        }else{
            System.out.println("no places");
        }

    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getPoints() {
        return points;
    }

    public void setPoints(int points) {
        this.points = points;
    }

    public int getAverageGrade() {
        return averageGrade;
    }

    public void setAverageGrade(int averageGrade) {
        this.averageGrade = averageGrade;
    }

    public Teacher getTeacher() {
        return teacher;
    }

    public void setTeacher(Teacher teacher) {
        this.teacher = teacher;
    }

    public int getMaxStudents() {
        return maxStudents;
    }

    public void setMaxStudents(int maxStudents) {
        this.maxStudents = maxStudents;
    }

    public int getNumOfStudent() {
        return numOfStudent;
    }

    public void setNumOfStudent(int numOfStudent) {
        this.numOfStudent = numOfStudent;
    }

    public ArrayList<Student> getStudents() {
        return students;
    }

    public void setStudents(ArrayList<Student> students) {
        this.students = students;
    }

}
