import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in);

        // 1. Baca N dan data array
        int N = sc.nextInt();
        int[] data = new int[N];
        for (int i = 0; i < N; i++) {
            data[i] = sc.nextInt();
        }

        // 2. Baca T = jumlah thread yang diinginkan
        int T = sc.nextInt();
        if (T <= 0) {
            System.out.println("Jumlah thread harus >= 1");
            sc.close();
            return;
        }

        // 3. Siapkan array untuk hasil dan thread pool
        int[] sums    = new int[T];
        Thread[] threads = new Thread[T];

        // 4. BAGIAN PENGERJAAN (TODO):
        //    - Bagi array `data` ke dalam T segmen sedemikian rupa sehingga selisih jumlah elemen antar segmen <= 1.
        //      Jika N tidak habis dibagi T, maka thread dengan indeks lebih kecil akan mendapatkan 1 elemen ekstra.
        //      Contoh: N=8, T=3 -> segmen ukuran [3, 3, 2].
        int rem = N % T;
        int nElem = N / T;
        //    - Untuk setiap segmen ke-i (0 <= i < T):
        //        Buat satu SumThread yang menghitung jumlah elemen pada segmen tersebut.
        //        SumThread menulis hasilnya ke sums[i].
        int idx = 0;
        for (int i = 0; i < T; i++) {
            int elemCount = nElem + (i < rem ? 1 : 0);
            threads[i] = new SumThread(data, sums, idx, idx + elemCount, i);
            idx += elemCount;
        }
        //    - Jalankan semua SumThread, kemudian tunggu
        //      hingga semua perhitungan selesai sebelum mencetak hasil.
        for (int i = 0; i < T; i++) {
            threads[i].start();
        }

        for (int i = 0; i < T; i++) { // Menunggu supaya semua sub-thread selesai sebelum thread utama dilanjutkan
            threads[i].join();
        }

        // 7. Cetak hasil per-segmen dan total
        int total = 0;
        for (int i = 0; i < T; i++) {
            System.out.println("Sum" + i + " = " + sums[i]);
            total += sums[i];
        }
        System.out.println("Total = " + total);

        sc.close();
    }

    /**
     * Thread yang menghitung jumlah elemen pada sebagian array integer.
     * Setiap SumThread bertugas menjumlahkan elemen pada rentang
     * data[dataStartIndex..dataEndIndex-1] dan menyimpan hasilnya di result[threadIndex].
     */
    private static class SumThread extends Thread {
        private final int[] data;
        private final int[] result;
        private final int dataStartIndex;
        private final int dataEndIndex;
        private final int threadIndex;

        /**
         * @param data             Array lengkap bilangan bulat yang akan dijumlahkan.
         * @param result           Array bersama untuk menyimpan hasil setiap thread.
         * @param dataStartIndex   Indeks awal (inklusif) segmen data yang dihitung.
         * @param dataEndIndex     Indeks akhir (eksklusif) segmen data yang dihitung.
         * @param threadIndex      Posisi di array result tempat menyimpan hasil.
         */
        public SumThread(int[] data, int[] result,
                        int dataStartIndex, int dataEndIndex,
                        int threadIndex) {
            this.data             = data;
            this.result           = result;
            this.dataStartIndex   = dataStartIndex;
            this.dataEndIndex     = dataEndIndex;
            this.threadIndex      = threadIndex;
        }

        /**
         * Menjalankan perhitungan jumlah elemen pada segmen yang ditentukan
         * dan menyimpan nilai sum ke result[threadIndex].
         */
        @Override
        public void run() {
            // TODO
            int idx = dataStartIndex;
            int sum = 0;

            while (idx < dataEndIndex) {
                sum += data[idx];
                idx++;
            }

            result[threadIndex] = sum;
        }
    }
}