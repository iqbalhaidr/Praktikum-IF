public interface MoneyTransaction {
    int getAmount();
    MoneyTransaction add(MoneyTransaction money);
    MoneyTransaction subtract(MoneyTransaction money);
}