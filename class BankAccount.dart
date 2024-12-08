class BankAccount {
  int accountNumber = 123456789;
  int balance = 1000;
  int amount = 0;
  BankAccount(this.accountNumber, this.balance);
  void Withdraw(int am) {
    if (balance >= am) {
      balance -= am;
      print("Withdrawal successful. Remaining balance:   ${balance}");
    } else {
      print("Insufficient funds.");
    }
  }

  void deposit(int amount) {
    balance += amount;
    print("Deposit successful. New balance:  ${balance}");
  }

  void printBalance(int balance) {
    print("Current balance:  ${balance}");
  }
}

void main() {
  BankAccount account = new BankAccount(123456789, 1000);
  account.Withdraw(500);
  account.deposit(2000);
  account.printBalance(account.balance);
}
