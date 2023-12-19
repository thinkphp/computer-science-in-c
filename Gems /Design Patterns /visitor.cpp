#include <iostream>
#include <vector>

// Forward declaration of Subscription classes
class MonthlySubscription;
class YearlySubscription;

// Visitor interface
class SubscriptionVisitor {
public:
    virtual void visit(MonthlySubscription& subscription) = 0;
    virtual void visit(YearlySubscription& subscription) = 0;
};

// Element interface
class Subscription {
public:
    virtual void accept(SubscriptionVisitor& visitor) = 0;
};

// Concrete Element: MonthlySubscription
class MonthlySubscription : public Subscription {
public:
    void accept(SubscriptionVisitor& visitor) override {
        visitor.visit(*this);
    }

    // Additional methods specific to MonthlySubscription
    void monthlyOperation() {
        std::cout << "Performing monthly operation for this subscription.\n";
    }
};

// Concrete Element: YearlySubscription
class YearlySubscription : public Subscription {
public:
    void accept(SubscriptionVisitor& visitor) override {
        visitor.visit(*this);
    }

    // Additional methods specific to YearlySubscription
    void yearlyOperation() {
        std::cout << "Performing yearly operation for this subscription.\n";
    }
};

// Concrete Visitor: SubscriptionRenewalVisitor
class SubscriptionRenewalVisitor : public SubscriptionVisitor {
public:
    void visit(MonthlySubscription& subscription) override {
        std::cout << "Renewing monthly subscription.\n";
        subscription.monthlyOperation();
    }

    void visit(YearlySubscription& subscription) override {
        std::cout << "Renewing yearly subscription.\n";
        subscription.yearlyOperation();
    }
};

int main() {
    // Creating a list of subscriptions
    std::vector<Subscription*> subscriptions = {
        new MonthlySubscription(),
        new YearlySubscription(),
        new MonthlySubscription(),
        new YearlySubscription()
    };

    // Creating a visitor for subscription renewal
    SubscriptionRenewalVisitor renewalVisitor;

    // Performing renewal operation on all subscriptions
    for (Subscription* subscription : subscriptions) {
        subscription->accept(renewalVisitor);
    }

    // Clean up allocated memory
    for (Subscription* subscription : subscriptions) {
        delete subscription;
    }

    return 0;
}
