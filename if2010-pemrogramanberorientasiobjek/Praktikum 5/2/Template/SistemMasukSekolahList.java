import java.util.List;

/**
 * Interface yang mendefinisikan operasi dasar untuk sistem masuk sekolah
 */
public interface SistemMasukSekolahList {
    
    /**
     * Menambahkan siswa ke dalam sistem
     * @param student siswa yang akan ditambahkan
     */
    void addStudent(Student student);
    
    /**
     * Menambahkan siswa di awal list
     * @param student siswa yang akan ditambahkan
     */
    void addFirstStudent(Student student);
    
    /**
     * Menambahkan siswa di akhir list
     * @param student siswa yang akan ditambahkan
     */
    void addLastStudent(Student student);
    
    /**
     * Mengambil siswa pertama di list
     * @return siswa pertama
     */
    Student getFirstStudent();
    
    /**
     * Mengambil siswa terakhir di list
     * @return siswa terakhir
     */
    Student getLastStudent();
    
    /**
     * Menghapus siswa pertama di list
     * @return siswa yang dihapus
     */
    Student removeFirstStudent();
    
    /**
     * Menghapus siswa terakhir di list
     * @return siswa yang dihapus
     */
    Student removeLastStudent();
    
    /**
     * Menghapus siswa berdasarkan kondisi (filter)
     * @param minGpa nilai minimum GPA untuk siswa yang akan dipertahankan
     * @return jumlah siswa yang dihapus
     */
    int removeStudentsByGpa(double minGpa);
    
    /**
     * Mencari siswa dengan GPA >= nilai tertentu
     * @param minGpa nilai minimum GPA untuk filtering
     * @return daftar siswa yang memenuhi kriteria
     */
    List<Student> getStudentsWithHighGpa(double minGpa);
    
    /**
     * Mencari siswa dengan umur tertentu
     * @param age umur yang dicari
     * @return daftar siswa dengan umur tersebut
     */
    List<Student> getStudentsByAge(int age);
    
    /**
     * Mencari nama-nama siswa muda berprestasi (umur < maxAge dan GPA >= minGpa)
     * @param maxAge umur maksimum
     * @param minGpa nilai minimum GPA
     * @return daftar nama siswa yang memenuhi kriteria
     */
    List<String> getYoungHighAchieverNames(int maxAge, double minGpa);
    
    /**
     * Mendapatkan semua siswa dalam sistem
     * @return daftar semua siswa
     */
    List<Student> getAllStudents();
}