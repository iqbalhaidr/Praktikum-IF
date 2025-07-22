import java.util.HashMap;
import java.util.HashSet;

public class EnrollmentSystem {
    private HashMap<String, Student> students; // <studentID, Student>
    private HashMap<String, Course> courses; // <courseID, Course>

    // Ctor untuk membuat objek EnrollmentSystem
    // Inisialisasi students dan courses
    public EnrollmentSystem() {
        this.students = new HashMap<>();
        this.courses = new HashMap<>();
    }

    // Method untuk menambahkan student ke dalam sistem
    public void addStudent(String studentID, String name) {
        Student newStudent = new Student(studentID, name);
        students.put(studentID, newStudent);
    }

    // Method untuk menambahkan course ke dalam sistem
    public void addCourse(String courseID, String courseName) {
        Course newCourse = new Course(courseID, courseName);
        courses.put(courseID, newCourse);
    }

    // Method untuk mendaftar student ke dalam course
    // Jika student atau course tidak ditemukan, tampilkan pesan error
    // "Student atau course tidak ditemukan!" (tanpa tanda kutip)
    public void enrollStudentInCourse(String studentID, String courseID) {
        if (!students.containsKey(studentID) || !courses.containsKey(courseID)) {
            System.out.println("Student atau course tidak ditemukan!");
        } else {
            Student targetStudent = students.get(studentID);
            Course targetCourse = courses.get(courseID);

            targetStudent.enrollCourse(courseID);
            targetCourse.addStudent(studentID);
        }
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
        if (!students.containsKey(studentID)) {
            System.out.println("Student tidak ditemukan!");
        } else {
            Student tar = students.get(studentID);
            HashSet<String> ec = tar.getEnrolledCourses();

            System.out.println("Student " + tar.getName() + " terdaftar di " + ec.size() + " course:");
            for (String cid : ec) {
                String cname = courses.get(cid).getCourseName();
                System.out.println(cid + " " + cname);
            }
        }
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
        if (!courses.containsKey(courseID)) {
            System.out.println("Course tidak ditemukan!");
        } else {
            Course cor = courses.get(courseID);
            HashSet<String> es = cor.getEnrolledStudents();

            System.out.println("Course " + cor.getCourseName() + " memiliki " + es.size() + " student:");
            for (String sid : es) {
                String sname = students.get(sid).getName();
                System.out.println(sid + " " + sname);
            }
        }

    }
}