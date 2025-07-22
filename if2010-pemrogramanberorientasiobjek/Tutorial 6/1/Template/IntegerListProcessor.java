import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class IntegerListProcessor {
    // Gunakan function ini untuk output
    private static void printList(List<Integer> list) {
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i));
            if (i < list.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    // Wajib menggunakan Java Collections API untuk semua operasi pada list
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 1. Baca N. N adalah jumlah input

        // 2. Baca N bilangan dan simpan ke List<Integer>

        // 3. Hapus semua elemen genap

        // 4. Jika panjang list sekarang ganjil, sort ascending; else sort descending
    
        // 5. Untuk setiap elemen, kalikan dengan tiga

        // 6. Cetak elemen menggunakan method printList
        printList(list);
    }
}