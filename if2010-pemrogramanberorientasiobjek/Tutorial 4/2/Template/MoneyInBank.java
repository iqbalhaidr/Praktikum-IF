public class MoneyInBank implements MoneyTransaction{
    private int amount;
    private int interestRate;
    private int totalLoanAmount;

    /*
     * Inisialisasi amount = 0, interest rate = 10 yang berarti bunga sebesar 10%, totalLoanAmount = 0;
     */
    public MoneyInBank() {}

    /*
     * Inisialisasi amount sesuai masukan dan interest rate sebesar intereseRate% dan totalLoanAmount sesuai masukan
     */
    public MoneyInBank(int amount, int interestRate, int totalLoanAmount) {}

    /*
     * Mengembalikan nilai amount
     */
    public int getAmount() {}

    /*
     * Mengembalikan nilai interestRate
     */
    public int getInterestRate() {}

    /*
     * Mengembalikan nilai totalLoanAmount
     */
    public int getTotalLoanAmount() {}

    /*
     * Menambahkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInBank dengan interestRate dari this.interestRate dan totalLoanAmount dari this.totalLoanAmount
     */
    public MoneyTransaction add(MoneyTransaction money) {}

    /*
     * Mengurangkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInBank dengan interestRate dari this.interestRate dan totalLoanAmount dari this.totalLoanAmount
     * Jika amount dari masukan lebih besar dari amount, maka objek yang dikembalikan memiliki amount = 0
     */
    public MoneyTransaction subtract(MoneyTransaction money) {}

    /*
     * Menghitung bunga yang diperoleh dari amount
     * Bunga dihitung dengan rumus (amount * interestRate) / 100
     * Jika bunga bukan bilangan bulat, bulatkan ke bawah
     */
    public int calcInterest() {}

    /*
     * Meminjam uang
     * Tambahkan amount dengan loanAmount
     * Tambahkan totalLoanAmount dengan (loanAmount * (100 + interestRate)) / 100)
     * Jika penambahan bukan bilangan bulat, bulatkan ke bawah
     */
    public void borrow(int loanAmount) {}

    /*
     * Menggambarkan transaksi setiap bulannya pada uang di bank
     * Pertama tambahkan bunga pada amount
     * Kemudian kurangkan amount dengan totalLoanAmount
     * Jika amount kurang dari 0, set amount menjadi 0
     * Set totalLoanAmount menjadi 0
     */

    public void monthlyTransaction() {}
}