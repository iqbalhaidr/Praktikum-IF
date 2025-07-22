import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.Iterator;

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
        this.students.add(student);
    }
    
    @Override
    public void addFirstStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di awal list
        this.students.addFirst(student);
    }
    
    @Override
    public void addLastStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di akhir list
        this.students.addLast(student);
    }
    
    @Override
    public Student getFirstStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa pertama di list
        return this.students.peekFirst();
    }
    
    @Override
    public Student getLastStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa terakhir di list
        return this.students.peekLast();
    }
    
    @Override
    public Student removeFirstStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa pertama di list
        return this.students.pollFirst();
    }
    
    @Override
    public Student removeLastStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa terakhir di list
        return this.students.pollLast();
    }
    
    @Override
    public int removeStudentsByGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Menghapus siswa dengan GPA < minGpa
        // Return jumlah siswa yang dihapus
        int count = 0;
        Iterator<Student> itr = students.iterator();
        while (itr.hasNext()) {
            Student curStu = itr.next();
            if (curStu.getGpa() < minGpa) {
                itr.remove();
                count++;
            }
        }
        return count;
    }
    
    @Override
    public List<Student> getStudentsWithHighGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan GPA >= minGpa
        List<Student> res = new LinkedList<>();
        Iterator<Student> itr = students.iterator();
        while (itr.hasNext()) {
            Student curStu = itr.next();
            if (curStu.getGpa() >= minGpa) {
                res.add(curStu);
            }
        }
        return res;
    }
    
    @Override
    public List<Student> getStudentsByAge(int age) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan umur tertentu
        List<Student> res = new LinkedList<>();
        Iterator<Student> itr = students.iterator();
        while (itr.hasNext()) {
            Student curStu = itr.next();
            if (curStu.getAge() == age) {
                res.add(curStu);
            }
        }
        return res;
    }
    
    @Override
    public List<String> getYoungHighAchieverNames(int maxAge, double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari nama siswa muda (umur < maxAge) dan berprestasi (GPA >= minGpa)
        List<String> res = new LinkedList<>();
        Iterator<Student> itr = this.students.iterator();
        while (itr.hasNext()) {
            Student curStu = itr.next();
            if (curStu.getAge() < maxAge && curStu.getGpa() >= minGpa) {
                res.add(curStu.getName());
            }
        }
        return res;
    }
    
    @Override
    public List<Student> getAllStudents() {
        // TODO: Implementasikan method ini
        // Mengembalikan seluruh siswa dalam list
        return this.students;
    }
}
