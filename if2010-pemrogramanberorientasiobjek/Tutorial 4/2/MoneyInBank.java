public class MoneyInBank implements MoneyTransaction {
    private int amount;
    private int interestRate;
    private int totalLoanAmount;

    /*
     * Inisialisasi amount = 0, interest rate = 10 yang berarti bunga sebesar 10%,
     * totalLoanAmount = 0;
     */
    public MoneyInBank() {
        this.amount = 0;
        this.interestRate = 10;
        this.totalLoanAmount = 0;
    }

    /*
     * Inisialisasi amount sesuai masukan dan interest rate sebesar intereseRate%
     * dan totalLoanAmount sesuai masukan
     */
    public MoneyInBank(int amount, int interestRate, int totalLoanAmount) {
        this.amount = amount;
        this.interestRate = interestRate;
        this.totalLoanAmount = totalLoanAmount;
    }

    /*
     * Mengembalikan nilai amount
     */
    public int getAmount() {
        return amount;
    }

    /*
     * Mengembalikan nilai interestRate
     */
    public int getInterestRate() {
        return interestRate;
    }

    /*
     * Mengembalikan nilai totalLoanAmount
     */
    public int getTotalLoanAmount() {
        return totalLoanAmount;
    }

    /*
     * Menambahkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInBank dengan interestRate dari
     * this.interestRate dan totalLoanAmount dari this.totalLoanAmount
     */
    public MoneyTransaction add(MoneyTransaction money) {
        return new MoneyInBank(amount + money.getAmount(), this.interestRate, this.totalLoanAmount);
    }

    /*
     * Mengurangkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInBank dengan interestRate dari
     * this.interestRate dan totalLoanAmount dari this.totalLoanAmount
     * Jika amount dari masukan lebih besar dari amount, maka objek yang
     * dikembalikan memiliki amount = 0
     *
     */

    public MoneyTransaction subtract(MoneyTransaction money) {

        if (money.getAmount() > amount) {
            return new MoneyInBank(0, this.interestRate, this.totalLoanAmount);
        } else {
            return new MoneyInBank(amount - money.getAmount(), this.interestRate, this.totalLoanAmount);
        }
    }

    /*
     * Menghitung bunga yang diperoleh dari amount
     * Bunga dihitung dengan rumus (amount * interestRate) / 100
     * Jika bunga bukan bilangan bulat, bulatkan ke bawah
     */
    public int calcInterest() {
        return (int) ((amount * interestRate) / 100);
    }

    /*
     * Meminjam uang
     * Tambahkan amount dengan loanAmount
     * Tambahkan totalLoanAmount dengan (loanAmount * (100 + interestRate)) / 100)
     * Jika penambahan bukan bilangan bulat, bulatkan ke bawah
     */
    public void borrow(int loanAmount) {
        amount += loanAmount;
        totalLoanAmount += (int) ((loanAmount * (100 + interestRate)) / 100);
    }

    /*
     * Menggambarkan transaksi setiap bulannya pada uang di bank
     * Pertama tambahkan bunga pada amount
     * Kemudian kurangkan amount dengan totalLoanAmount
     * Jika amount kurang dari 0, set amount menjadi 0
     * Set totalLoanAmount menjadi 0
     */

    public void monthlyTransaction() {
        amount += amount * interestRate / 100;
        amount -= totalLoanAmount;
        if (amount < 0) {
            amount = 0;
        }
        totalLoanAmount = 0;
    }
}
