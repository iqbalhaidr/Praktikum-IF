import java.util.HashSet;

public class Course {
    private String courseID;
    private String courseName;
    private HashSet<String> enrolledStudents;

    // Ctor untuk membuat objek Course dengan ID dan nama
    // Note: jangan lupa untuk menginisialisasi enrolledStudents
    public Course(String courseID, String courseName) {
        this.courseID = courseID;
        this.courseName = courseName;
        this.enrolledStudents = new HashSet<>();
    }

    // Method untuk menambahkan student ke dalam enrolledStudents
    public void addStudent(String studentID) {
        enrolledStudents.add(studentID);
    }

    // Getter untuk mendapatkan student yang terdaftar di course
    public HashSet<String> getEnrolledStudents() {
        return this.enrolledStudents;
    }

    // Getter untuk mendapatkan courseID
    public String getCourseID() {
        return courseID;
    }

    // Getter untuk mendapatkan nama course
    public String getCourseName() {
        return courseName;
    }
}