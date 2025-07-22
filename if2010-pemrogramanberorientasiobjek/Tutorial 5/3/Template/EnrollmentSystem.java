import java.util.HashMap;

public class EnrollmentSystem {
    private HashMap<String, Student> students; // <studentID, Student>
    private HashMap<String, Course> courses; // <courseID, Course>

    // Ctor untuk membuat objek EnrollmentSystem
    // Inisialisasi students dan courses
    public EnrollmentSystem() {
    }

    // Method untuk menambahkan student ke dalam sistem
    public void addStudent(String studentID, String name) {
    }

    // Method untuk menambahkan course ke dalam sistem
    public void addCourse(String courseID, String courseName) {
    }

    // Method untuk mendaftar student ke dalam course
    // Jika student atau course tidak ditemukan, tampilkan pesan error
    // "Student atau course tidak ditemukan!" (tanpa tanda kutip)
    public void enrollStudentInCourse(String studentID, String courseID) {

    }

    // Method untuk menampilkan daftar course yang diambil oleh student
    //
    // Student <studentName> terdaftar di <jumlah course> course:
    // <courseID1> <courseName1>
    // <courseID2> <courseName2>
    // ...
    //
    // Jika student tidak ditemukan, tampilkan pesan error
    // "Student tidak ditemukan!" (tanpa tanda kutip)
    public void displayCoursesForStudent(String studentID) {
    }

    // Method untuk menampilkan daftar student yang terdaftar di course
    //
    // Course <courseName> memiliki <jumlah student> student:
    // <studentID1> <studentName1>
    // <studentID2> <studentName2>
    // ...
    //
    // Jika course tidak ditemukan, tampilkan pesan error
    // "Course tidak ditemukan!" (tanpa tanda kutip)
    public void displayStudentsInCourse(String courseID) {

    }
}