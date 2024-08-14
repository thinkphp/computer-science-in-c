#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class User {
private:
    std::string username;
    std::string password;
    double balance;
    std::vector<std::string> transactionHistory;

public:
    // Constructor
    User(const std::string& user, const std::string& pass)
        : username(user), password(pass), balance(0.0) {}

    // Getters
    std::string getUsername() const { return username; }

    bool authenticate(const std::string& pass) const { return password == pass; }

    double getBalance() const { return balance; }

    // Methods
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back("Deposit: $" + std::to_string(amount));
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionHistory.push_back("Withdraw: $" + std::to_string(amount));
            return true;
        }
        return false;
    }

    void addTransaction(const std::string& transaction) {
        transactionHistory.push_back(transaction);
    }

    void printTransactionHistory() const {
        std::cout << "Transaction History for " << username << ":\n";
        for (const auto& transaction : transactionHistory) {
            std::cout << transaction << std::endl;
        }
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
        } else {
            std::cout << (it == users.end() ? "User not found." : "Incorrect password.") << "\n";
        }
        return nullptr;
    }

    void transferMoney(User& fromUser, User& toUser, double amount) {
        if (fromUser.withdraw(amount)) {
            toUser.deposit(amount);
            fromUser.addTransaction("Transfer: $" + std::to_string(amount) + " to " + toUser.getUsername());
            toUser.addTransaction("Received: $" + std::to_string(amount) + " from " + fromUser.getUsername());
            std::cout << "Transfer successful.\n";
        } else {
            std::cout << "Transfer failed due to insufficient funds.\n";
        }
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
        user1->deposit(1000);
        user1->withdraw(200);
        user1->printTransactionHistory();
    }

    if (user2) {
        user2->deposit(1500);
        user2->printTransactionHistory();
    }

    // Transfer money
    if (user1 && user2) {
        bank.transferMoney(*user1, *user2, 300);
        user1->printTransactionHistory();
        user2->printTransactionHistory();
    }

    return 0;
}
