#include <iostream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& message) = 0;
};

class SubscriptionManager : public Subject {
private:
    std::vector<Observer*> observers;
    std::string subscriptionStatus;

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        auto it = std::remove(observers.begin(), observers.end(), observer);
        observers.erase(it, observers.end());
    }

    void notifyObservers(const std::string& message) override {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }

    void setSubscriptionStatus(const std::string& status) {
        subscriptionStatus = status;
        notifyObservers("Subscription status changed to: " + status);
    }
};

class Subscriber : public Observer {
private:
    std::string name;

public:
    Subscriber(const std::string& name) : name(name) {}

    void update(const std::string& message) override {
        std::cout << "Subscriber " << name << " received message: " << message << std::endl;
    }
};

int main() {
    // Create a subscription manager
    SubscriptionManager subscriptionManager;

    // Create subscribers
    Subscriber subscriber1("Alice");
    Subscriber subscriber2("Bob");

    // Add subscribers to the subscription manager
    subscriptionManager.addObserver(&subscriber1);
    subscriptionManager.addObserver(&subscriber2);

    // Set the initial subscription status
    subscriptionManager.setSubscriptionStatus("Active");

    // Update the subscription status (this will notify subscribers)
    subscriptionManager.setSubscriptionStatus("Inactive");

    // Remove a subscriber
    subscriptionManager.removeObserver(&subscriber1);

    // Update the subscription status again (only subscriber2 should be notified)
    subscriptionManager.setSubscriptionStatus("Suspended");

    return 0;
}
