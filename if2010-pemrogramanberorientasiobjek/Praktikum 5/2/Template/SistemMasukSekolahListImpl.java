import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Implementasi dari interface SistemMasukSekolahList menggunakan LinkedList
 * PETUNJUK:
 * - Gunakan LinkedList sebagai struktur data utama
 * - Manfaatkan fitur Java Collections
 */
public class SistemMasukSekolahListImpl implements SistemMasukSekolahList {
    
    // Atribut: gunakan LinkedList<Student> untuk menyimpan data siswa
    private LinkedList<Student> students;
    
    /**
     * Constructor: inisialisasi LinkedList students
     */
    public SistemMasukSekolahListImpl() {
        this.students = new LinkedList<>();
    }
    
    @Override
    public void addStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa ke dalam list
    }
    
    @Override
    public void addFirstStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di awal list
    }
    
    @Override
    public void addLastStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di akhir list
    }
    
    @Override
    public Student getFirstStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa pertama di list
        return null;
    }
    
    @Override
    public Student getLastStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa terakhir di list
        return null;
    }
    
    @Override
    public Student removeFirstStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa pertama di list
        return null;
    }
    
    @Override
    public Student removeLastStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa terakhir di list
        return null;
    }
    
    @Override
    public int removeStudentsByGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Menghapus siswa dengan GPA < minGpa
        // Return jumlah siswa yang dihapus
        return 0;
    }
    
    @Override
    public List<Student> getStudentsWithHighGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan GPA >= minGpa
        return null;
    }
    
    @Override
    public List<Student> getStudentsByAge(int age) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan umur tertentu
        return null;
    }
    
    @Override
    public List<String> getYoungHighAchieverNames(int maxAge, double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari nama siswa muda (umur < maxAge) dan berprestasi (GPA >= minGpa)
        return null;
    }
    
    @Override
    public List<Student> getAllStudents() {
        // TODO: Implementasikan method ini
        // Mengembalikan seluruh siswa dalam list
        return null;
    }
}