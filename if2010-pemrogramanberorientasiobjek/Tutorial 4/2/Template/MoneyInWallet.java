public class MoneyInWallet implements MoneyTransaction{
    private int amount;

    /*
     * Inisialisasi amount = 0
     */
    public MoneyInWallet() {}

    /*
     * Inisialisasi amount sesuai masukan
     */
    public MoneyInWallet(int amount) {}

    /*
     * Mengembalikan nilai amount
     */
    public int getAmount() {}

    /*
     * Menambahkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInWallet
     */
    public MoneyTransaction add(MoneyTransaction money) {}

    /*
     * Mengurangkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInWallet
     * Jika amount dari masukan lebih besar dari amount, maka objek yang dikembalikan memiliki amount = 0
     */
    public MoneyTransaction subtract(MoneyTransaction money) {}

    /*
     * Menyimpan uang di dompet dapat membuang uang menjadi lapuk
     * Amount akan menjadi 90% dari sebelumnya
     * Jika hasil bukan integer, bulatkan hasil ke bawah
     */
    public void decay() {}
}