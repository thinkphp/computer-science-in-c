#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Abstract Product
class Transport {
protected:
    std::string cargo;
    std::string destination;

public:
    Transport() = default;
    virtual ~Transport() = default;

    void setCargo(const std::string& cargo) {
        this->cargo = cargo;
    }

    void setDestination(const std::string& destination) {
        this->destination = destination;
    }

    virtual void deliver() const = 0;
    virtual std::string getType() const = 0;
    virtual float calculateCost() const = 0;
};

// Concrete Products
class Truck : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering " << cargo << " by land to " << destination << std::endl;
        std::cout << "Using trucks for road transportation" << std::endl;
    }

    std::string getType() const override {
        return "Truck";
    }

    float calculateCost() const override {
        // Simple cost calculation based on cargo length
        return cargo.length() * 0.5f; // $0.5 per character in cargo name
    }
};

class Ship : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering " << cargo << " by sea to " << destination << std::endl;
        std::cout << "Using cargo ships for maritime transportation" << std::endl;
    }

    std::string getType() const override {
        return "Ship";
    }

    float calculateCost() const override {
        // Simple cost calculation based on cargo length
        return cargo.length() * 0.3f; // $0.3 per character in cargo name (cheaper for large volumes)
    }
};

class Airplane : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering " << cargo << " by air to " << destination << std::endl;
        std::cout << "Using cargo planes for air transportation" << std::endl;
    }

    std::string getType() const override {
        return "Airplane";
    }

    float calculateCost() const override {
        // Simple cost calculation based on cargo length
        return cargo.length() * 1.2f; // $1.2 per character in cargo name (most expensive)
    }
};

// Abstract Creator
class LogisticsFactory {
public:
    virtual ~LogisticsFactory() = default;
    virtual std::unique_ptr<Transport> createTransport() const = 0;
    
    // Template method that uses the factory method
    std::unique_ptr<Transport> planDelivery(const std::string& cargo, const std::string& destination) const {
        std::unique_ptr<Transport> transport = createTransport();
        transport->setCargo(cargo);
        transport->setDestination(destination);
        return transport;
    }
};

// Concrete Creators
class RoadLogistics : public LogisticsFactory {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Truck>();
    }
};

class SeaLogistics : public LogisticsFactory {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Ship>();
    }
};

class AirLogistics : public LogisticsFactory {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Airplane>();
    }
};

// Logistics Management System
class LogisticsSystem {
private:
    std::vector<std::unique_ptr<Transport>> shipments;

public:
    void createShipment(const LogisticsFactory& factory, const std::string& cargo, const std::string& destination) {
        auto transport = factory.planDelivery(cargo, destination);
        
        std::cout << "Created " << transport->getType() << " shipment for " << cargo 
                  << " to " << destination << std::endl;
        std::cout << "Estimated cost: $" << transport->calculateCost() << std::endl;
        
        shipments.push_back(std::move(transport));
    }

    void listShipments() const {
        std::cout << "\nCurrent Shipments:" << std::endl;
        std::cout << "------------------" << std::endl;
        
        if (shipments.empty()) {
            std::cout << "No shipments in the system." << std::endl;
            return;
        }

        for (size_t i = 0; i < shipments.size(); ++i) {
            std::cout << i + 1 << ". Type: " << shipments[i]->getType() 
                      << " | Cost: $" << shipments[i]->calculateCost() << std::endl;
        }
    }

    void deliverShipment(size_t index) {
        if (index >= 1 && index <= shipments.size()) {
            std::cout << "\nDelivering shipment #" << index << ":" << std::endl;
            shipments[index - 1]->deliver();
            
            // Remove the shipment after delivery
            std::cout << "Shipment delivered and removed from the system." << std::endl;
            shipments.erase(shipments.begin() + (index - 1));
        } else {
            std::cout << "Invalid shipment index." << std::endl;
        }
    }

    void deliverAllShipments() {
        std::cout << "\nDelivering all shipments:" << std::endl;
        if (shipments.empty()) {
            std::cout << "No shipments to deliver." << std::endl;
            return;
        }

        for (const auto& shipment : shipments) {
            shipment->deliver();
            std::cout << "------------------" << std::endl;
        }
        
        // Clear all shipments after delivery
        shipments.clear();
        std::cout << "All shipments delivered and removed from the system." << std::endl;
    }

    int getTotalShipments() const {
        return shipments.size();
    }
};

// Client code
int main() {
    LogisticsSystem system;
    RoadLogistics roadLogistics;
    SeaLogistics seaLogistics;
    AirLogistics airLogistics;

    // Create shipments using different logistics methods
    system.createShipment(roadLogistics, "Furniture", "Local Warehouse");
    system.createShipment(seaLogistics, "Electronics", "Shanghai");
    system.createShipment(airLogistics, "Medical Supplies", "Emergency Relief Center");
    system.createShipment(roadLogistics, "Construction Materials", "Building Site");

    // List all shipments
    system.listShipments();

    // Deliver a specific shipment
    system.deliverShipment(2); // Deliver the second shipment (Electronics to Shanghai)

    // List remaining shipments
    system.listShipments();

    // Deliver all remaining shipments
    system.deliverAllShipments();

    // Verify all shipments are delivered
    std::cout << "\nRemaining shipments: " << system.getTotalShipments() << std::endl;

    return 0;
}
