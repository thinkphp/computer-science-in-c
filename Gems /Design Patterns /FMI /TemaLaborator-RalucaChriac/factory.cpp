#include "include/ManagerClienti.h"
#include "src/ManagerClienti.cpp"
#include "include/AbonamentSimplu.h"
#include "include/AbonamentPremium.h"
#include "include/AbonamentStudent.h"

// Abstract class for the ManagerClienti factory
class ManagerClientiFactory {

public:
    virtual ManagerClienti createManager() = 0;
    
    virtual ~ManagerClientiFactory() = default;
};

// Concrete factory for creating ManagerClienti objects
class DefaultManagerClientiFactory : public ManagerClientiFactory {
public:

    ManagerClienti createManager() override {
        return ManagerClienti();
    }
};

class App {
private:
    ManagerClientiFactory* factory;

public:
    // Constructor that takes a factory as a parameter
    explicit App(ManagerClientiFactory* factory) : factory(factory) {}

    // Method to run the application
    void run() {
        ManagerClienti manager = factory->createManager();

        int optiune;
        do {
            manager.afiseazaMeniu();
            std::cin >> optiune;
            for (int i = 0; i < 10; i++)
                std::cout << std::endl;

            switch (optiune) {
            
                case 1:
                    manager.adaugaClient();
                    break;
                    

                case 3:
                    manager.listeazaClienti();
                    break;
                // Add cases for other options...

                case 7:
                    std::cout << "Programul se inchide.\n";
                    break;

                default:
                    std::cout << "Optiune invalida. Va rugam alegeti o optiune valida.\n";
                    break;
            }

            for (int i = 0; i < 10; i++)
                std::cout << std::endl;

        } while (optiune != 7);
    }
};

int main() {
    // Use the DefaultManagerClientiFactory by default
    DefaultManagerClientiFactory defaultManagerFactory;
    App app(&defaultManagerFactory);

    // Run the application
    app.run();

    return 0;
}
