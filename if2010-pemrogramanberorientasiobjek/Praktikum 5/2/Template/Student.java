public class Student {
    private String name;
    private int age;
    private double gpa;
    
    /**
     * Constructor untuk membuat objek Student
     * @param name nama siswa
     * @param age umur siswa
     * @param gpa nilai siswa
     */
    public Student(String name, int age, double gpa) {
        this.name = name;
        this.age = age;
        this.gpa = gpa;
    }
    
    /**
     * Getter untuk mendapatkan nama siswa
     * @return nama siswa
     */
    public String getName() {
        return name;
    }
    
    /**
     * Getter untuk mendapatkan umur siswa
     * @return umur siswa
     */
    public int getAge() {
        return age;
    }
    
    /**
     * Getter untuk mendapatkan nilai siswa
     * @return nilai siswa
     */
    public double getGpa() {
        return gpa;
    }
    
    /**
     * Override method toString untuk memudahkan pencetakan informasi siswa
     */
    @Override
    public String toString() {
        return "Student{name='" + name + "', age=" + age + ", gpa=" + gpa + "}";
    }
}