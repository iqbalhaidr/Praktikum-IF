public class Main {
    public static void main(String[] args) {
        EnrollmentSystem system = new EnrollmentSystem();

        // Tambahkan student dan course
        system.addStudent("S001", "Budi");
        system.addStudent("S002", "Ani");
        system.addStudent("S003", "Cici");

        system.addCourse("C001", "Matematika");
        system.addCourse("C002", "Fisika");

        // Tes pendaftaran
        system.enrollStudentInCourse("S001", "C001"); // harus sukses
        system.enrollStudentInCourse("S002", "C001"); // harus sukses
        system.enrollStudentInCourse("S002", "C002"); // harus sukses
        system.enrollStudentInCourse("S999", "C001"); // harus error
        system.enrollStudentInCourse("S001", "C999"); // harus error

        // Tampilkan course yang diambil oleh S002
        system.displayCoursesForStudent("S002");

        // Tampilkan student yang terdaftar di C001
        system.displayStudentsInCourse("C001");

        // Tes error handling
        system.displayCoursesForStudent("S999"); // harus error
        system.displayStudentsInCourse("C999"); // harus error
    }
}
