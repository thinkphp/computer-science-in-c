#include <iostream>
#include <vector>

class Subscription {
public:
    Subscription(const std::string& name) : name(name) {}

    void display() const {
        std::cout << "Subscription: " << name << std::endl;
    }

private:
    std::string name;
};

class SubscriptionManager {
private:
    std::vector<Subscription> subscriptions;

    // Private constructor to prevent instantiation
    SubscriptionManager() {}

public:
    
    static SubscriptionManager& getInstance() {
        static SubscriptionManager instance;
        return instance;
    }

    
    void addSubscription(const std::string& subscriptionName) {
        subscriptions.emplace_back(subscriptionName);
    }

    
    void displaySubscriptions() const {
        std::cout << "All Subscriptions:" << std::endl;
        for (const auto& subscription : subscriptions) {
            subscription.display();
        }
        std::cout << "------------------------" << std::endl;
    }
};

int main() {
    // Get the instance of the SubscriptionManager
    SubscriptionManager& manager = SubscriptionManager::getInstance();

    // Add subscriptions
    manager.addSubscription("Basic Plan");
    manager.addSubscription("Premium Plan");
    manager.addSubscription("Business Plan");

    // Display all subscriptions
    manager.displaySubscriptions();

    // incearca sa creezi o alta instanta (compile-time error)
    // SubscriptionManager manager2; // Error: SubscriptionManager constructor is private

    return 0;
}
