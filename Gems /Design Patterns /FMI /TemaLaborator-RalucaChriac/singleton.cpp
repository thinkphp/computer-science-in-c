#include "include/ManagerClienti.h"
#include "src/ManagerClienti.cpp"
#include "include/AbonamentSimplu.h"
#include "include/AbonamentPremium.h"
#include "include/AbonamentStudent.h"

class SingletonManagerClienti {
private:
    ManagerClienti manager;

    // Private constructor to prevent instantiation
    SingletonManagerClienti() {}

public:
    // Static method to access the singleton instance
    static SingletonManagerClienti& getInstance() {
    
        static SingletonManagerClienti instance;
        
        return instance;
    }

    // Other public methods can be forwarded to the ManagerClienti instance
    void afiseazaMeniu() {
    
        manager.afiseazaMeniu();
    }

    void adaugaClient() {
    
        manager.adaugaClient();
    }
    
    void listeazaClienti() {
    
        manager.listeazaClienti();
    
    }
    

    // Add other methods here...

    // You may also need to prevent copying and assignment
    SingletonManagerClienti(const SingletonManagerClienti&) = delete;
    SingletonManagerClienti& operator=(const SingletonManagerClienti&) = delete;

    // Destructor (optional)
    ~SingletonManagerClienti() {
        // Add cleanup code if necessary
    }
};

int main() {
    int optiune;
    do {
        SingletonManagerClienti::getInstance().afiseazaMeniu();
        std::cin >> optiune;
        for (int i = 0; i < 10; i++)
            std::cout << std::endl;

        switch (optiune) {
            case 1:
                SingletonManagerClienti::getInstance().adaugaClient();
                break;
                
            // Add cases for other options...                        
            case 3:
                SingletonManagerClienti::getInstance().listeazaClienti();
                break;

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

    return 0;
}
