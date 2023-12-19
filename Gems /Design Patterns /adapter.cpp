#include <iostream>
#include <string>


class SubscriptionSystem {
public:
    virtual void createSubscription(int userId, const std::string& plan) = 0;
    virtual void cancelSubscription(int userId) = 0;
    virtual ~SubscriptionSystem() = default;
};


class ConcreteSubscriptionSystem : public SubscriptionSystem {
public:
    void createSubscription(int userId, const std::string& plan) override {
        std::cout << "Created subscription for user " << userId << " with plan " << plan << std::endl;
    }

    void cancelSubscription(int userId) override {
        std::cout << "Canceled subscription for user " << userId << std::endl;
    }
};

// Third-party subscription service interface
class NewSubscriptionService {
public:
    void subscribeUser(int userId, const std::string& subscriptionType) {
        // Some implementation specific to the new service
    }

    void unsubscribeUser(int userId) {
        // Some implementation specific to the new service
    }
};

// Adapter to make the third-party service compatible with the existing system
class NewSubscriptionServiceAdapter : public SubscriptionSystem {
private:
    NewSubscriptionService* newService;

public:
    NewSubscriptionServiceAdapter(NewSubscriptionService* service) : newService(service) {}

    void createSubscription(int userId, const std::string& plan) override {
        // Adapt the method to the existing system's interface
        newService->subscribeUser(userId, plan);
    }

    void cancelSubscription(int userId) override {
        // Adapt the method to the existing system's interface
        newService->unsubscribeUser(userId);
    }
};

// Client code
void clientCode(SubscriptionSystem* subscriptionSystem, int userId, const std::string& plan) {
    subscriptionSystem->createSubscription(userId, plan);
    subscriptionSystem->cancelSubscription(userId);
}

int main() {
    // Using the existing system directly
    ConcreteSubscriptionSystem existingSystem;
    clientCode(&existingSystem, 123, "Premium");

    // Using the adapter for the new subscription service
    NewSubscriptionService newService;
    NewSubscriptionServiceAdapter adapter(&newService);
    clientCode(&adapter, 456, "Basic");

    return 0;
}
