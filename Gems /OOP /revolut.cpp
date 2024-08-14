#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip> // For std::fixed and std::setprecision

class Vault {
private:
    std::string vaultName;
    double vaultBalance;

public:
    // Constructors
    Vault() : vaultName(""), vaultBalance(0.0) {}
    Vault(const std::string& name, double balance = 0.0)
        : vaultName(name), vaultBalance(balance) {}

    // Defaulted special members
    Vault(const Vault& other) = default;
    Vault(Vault&& other) noexcept = default;
    Vault& operator=(const Vault& other) = default;
    Vault& operator=(Vault&& other) noexcept = default;

    // Methods
    void deposit(double amount) {
        if (amount > 0) vaultBalance += amount;
    }

    double getVaultBalance() const { return vaultBalance; }
    std::string getVaultName() const { return vaultName; }
};

class User {
private:
    std::string username;
    std::string password;
    double balance;
    std::vector<std::string> transactionHistory;
    std::unordered_map<std::string, Vault> vaults;
    double loanBalance;

public:
    // Constructor
    User(const std::string& user, const std::string& pass)
        : username(user), password(pass), balance(0.0), loanBalance(0.0) {}

    // Getters
    std::string getUsername() const { return username; }
    bool authenticate(const std::string& pass) const { return password == pass; }
    double getBalance() const { return balance; }
    double getLoanBalance() const { return loanBalance; }

    // Methods
    bool transferTo(User& toUser, double amount, double fee = 1.0) {
        if (amount > 0 && fee >= 0) {
            double totalAmount = amount + fee;
            if (totalAmount <= balance) {
                balance -= totalAmount;
                toUser.balance += amount;
                transactionHistory.push_back("Transfer: $" + formatAmount(amount) + " to " + toUser.getUsername() + " (Fee: $" + formatAmount(fee) + ")");
                toUser.transactionHistory.push_back("Received: $" + formatAmount(amount) + " from " + username);
                return true;
            } else {
                std::cout << "Transfer failed due to insufficient funds.\n";
            }
        } else {
            std::cout << "Invalid transfer amount or fee.\n";
        }
        return false;
    }

    void topUp(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back("Top-Up: $" + formatAmount(amount));
        } else {
            std::cout << "Invalid top-up amount.\n";
        }
    }

    bool exchangeCurrency(double amount, double rate) {
        if (amount > 0 && rate > 0 && amount <= balance) {
            double exchangedAmount = amount * rate;
            balance -= amount;
            balance += exchangedAmount;
            transactionHistory.push_back("Currency Exchange: $" + formatAmount(amount) + " exchanged at rate " + formatAmount(rate));
            return true;
        }
        std::cout << "Invalid exchange amount or rate.\n";
        return false;
    }

    void createVault(const std::string& vaultName) {
        if (vaults.find(vaultName) == vaults.end()) {
            vaults.emplace(vaultName, Vault(vaultName));
            transactionHistory.push_back("Vault Created: " + vaultName);
        } else {
            std::cout << "Vault already exists.\n";
        }
    }

    void depositToVault(const std::string& vaultName, double amount) {
        auto vaultIt = vaults.find(vaultName);
        if (vaultIt != vaults.end() && amount > 0 && amount <= balance) {
            balance -= amount;
            vaultIt->second.deposit(amount);
            transactionHistory.push_back("Deposited to Vault: $" + formatAmount(amount) + " to " + vaultName);
        } else {
            std::cout << "Invalid vault name or deposit amount.\n";
        }
    }

    double getVaultBalance(const std::string& vaultName) const {
        auto vaultIt = vaults.find(vaultName);
        if (vaultIt != vaults.end()) {
            return vaultIt->second.getVaultBalance();
        }
        return 0.0;
    }

    bool requestLoan(double amount, double interestRate) {
        if (amount > 0 && interestRate >= 0) {
            double totalLoan = amount * (1 + interestRate / 100);
            loanBalance += totalLoan;
            balance += amount;
            transactionHistory.push_back("Loan Granted: $" + formatAmount(amount) + " (Total Repayable: $" + formatAmount(totalLoan) + ")");
            return true;
        }
        std::cout << "Invalid loan amount or interest rate.\n";
        return false;
    }

    bool repayLoan(double amount) {
        if (amount > 0 && amount <= balance && amount <= loanBalance) {
            balance -= amount;
            loanBalance -= amount;
            transactionHistory.push_back("Loan Repayment: $" + formatAmount(amount));
            return true;
        }
        std::cout << "Invalid repayment amount or insufficient balance.\n";
        return false;
    }

    void printTransactionHistory() const {
        std::cout << "Transaction History for " << username << ":\n";
        for (const auto& transaction : transactionHistory) {
            std::cout << transaction << std::endl;
        }
    }

private:
    static std::string formatAmount(double amount) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << amount;
        return oss.str();
    }
};

class BankSystem {
private:
    std::unordered_map<std::string, User> users;

public:
    void createUser(const std::string& username, const std::string& password) {
        if (users.find(username) == users.end()) {
            users.emplace(username, User(username, password));
            std::cout << "User " << username << " created successfully.\n";
        } else {
            std::cout << "Username already exists.\n";
        }
    }

    User* authenticateUser(const std::string& username, const std::string& password) {
        auto it = users.find(username);
        if (it != users.end() && it->second.authenticate(password)) {
            std::cout << "User " << username << " authenticated successfully.\n";
            return &it->second;
        }
        std::cout << (it == users.end() ? "User not found." : "Incorrect password.") << "\n";
        return nullptr;
    }

    void transferMoney(User& fromUser, User& toUser, double amount) {
        double fee = 1.0; // Fixed fee for simplicity
        if (fromUser.transferTo(toUser, amount, fee)) {
            std::cout << "Transfer of $" << formatAmount(amount) << " from " << fromUser.getUsername() << " to " << toUser.getUsername() << " successful.\n";
        } else {
            std::cout << "Transfer failed.\n";
        }
    }

private:
    static std::string formatAmount(double amount) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << amount;
        return oss.str();
    }
};

int main() {
    BankSystem bank;

    // Create some users
    bank.createUser("john_doe", "password123");
    bank.createUser("jane_smith", "mypassword");

    // Authenticate users
    User* user1 = bank.authenticateUser("john_doe", "password123");
    User* user2 = bank.authenticateUser("jane_smith", "mypassword");

    if (user1) {
        user1->topUp(1000);  // Top-up user1 with $1000
        user1->createVault("Vacation Fund");
        user1->depositToVault("Vacation Fund", 200);  // Deposit $200 to the vault
        user1->exchangeCurrency(100, 0.9);  // Exchange $100 to another currency at a rate of 0.9
        user1->requestLoan(500, 5.0);  // Request a loan of $500 at 5% interest rate
        user1->repayLoan(100);  // Repay $100 of the loan
        user1->printTransactionHistory();
    }

    if (user2) {
        user2->topUp(500);  // Top-up user2 with $500
        user2->printTransactionHistory();
    }

    // Transfer money
    if (user1 && user2) {
        bank.transferMoney(*user1, *user2, 300);  // Transfer $300 from user1 to user2
        user1->printTransactionHistory();
        user2->printTransactionHistory();
    }

    return 0;
}
