import java.io.*;
import java.util.*;

public class Enclosure {
    private ArrayList<Animal> animals;

    public Enclosure() {
        // Inisialisasi ArrayList animals kosong
    } 

    public int getAnimalCount() {
        // Mengembalikan jumlah hewan dalam this.animals
    }

    public void addAnimal(Animal animal) {
        // menambahkan seekor hewan ke dalam this.animals
    }

    public Animal getAnimalAt(int i) {
        // mengembalikan hewan dalam this.animals pada index i (tidak mengubah this.animals)
    }

    public void removeAnimalAt(int i) {
        // menghapus hewan pada this.animals pada index i
    }

    public boolean isEmpty() {
        // mengembalikan boolean yang menyatakan apakah this.animals kosong atau tidak
    }

    public void describe() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong menuliskan output serupa dengan output berikut:
        // Kandang berisi 2 ekor hewan:
        // 1. po, spesies Pandamus Maximus, umur 5 tahun
        // 2. po2, spesies Pandamus Maximus, umur 5 tahun
    }

    public void feed() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong maka akan memanggil method eat pada tiap animal dalam this.animals
    }

    public boolean safeForPetting() {
        // mengembalikan true apabila semua hewan dalam this.animals bersifat friendly
    }
}