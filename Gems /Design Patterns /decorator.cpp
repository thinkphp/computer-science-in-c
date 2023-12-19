#include <iostream>
#include <string>

// Component interface (base class)
class Subscription {
public:
    virtual ~Subscription() = default;
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
};

// Concrete Component
class BasicSubscription : public Subscription {
public:
    std::string getDescription() const override {
        return "Basic Subscription";
    }

    double getCost() const override {
        return 10.0;
    }
};

// Decorator base class
class SubscriptionDecorator : public Subscription {
protected:
    Subscription* subscription;

public:
    SubscriptionDecorator(Subscription* subscription) : subscription(subscription) {}

    std::string getDescription() const override {
        return subscription->getDescription();
    }

    double getCost() const override {
        return subscription->getCost();
    }
};

// Concrete Decorator - Additional Feature
class PremiumFeature : public SubscriptionDecorator {
public:
    PremiumFeature(Subscription* subscription) : SubscriptionDecorator(subscription) {}

    std::string getDescription() const override {
        return subscription->getDescription() + ", Premium Feature";
    }

    double getCost() const override {
        return subscription->getCost() + 5.0;
    }
};

// Concrete Decorator - Discount
class DiscountedSubscription : public SubscriptionDecorator {
public:
    DiscountedSubscription(Subscription* subscription) : SubscriptionDecorator(subscription) {}

    std::string getDescription() const override {
        return subscription->getDescription() + ", Discounted";
    }

    double getCost() const override {
        return subscription->getCost() * 0.8; // 20% discount
    }
};

int main() {
    // Creating a basic subscription
    Subscription* basicSubscription = new BasicSubscription();

    // Adding premium feature
    Subscription* premiumSubscription = new PremiumFeature(basicSubscription);

    // Adding discount to premium subscription
    Subscription* discountedPremiumSubscription = new DiscountedSubscription(premiumSubscription);

    // Displaying details
    std::cout << "Description: " << discountedPremiumSubscription->getDescription() << std::endl;
    std::cout << "Cost: $" << discountedPremiumSubscription->getCost() << std::endl;

    // Clean up
    delete discountedPremiumSubscription;
    
    return 0;
}
