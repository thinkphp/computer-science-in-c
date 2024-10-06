#include <iostream>
#include <vector>
#include <functional>
#include <random>

class MathTutor {
private:
    std::vector<std::function<int(int, int)>> operations;
    std::vector<std::string> operationNames;

public:
    MathTutor() {
        // Adăugăm operațiile matematice folosind funcții lambda
        operations.push_back([](int a, int b) { return a + b; });
        operationNames.push_back("Adunare");

        operations.push_back([](int a, int b) { return a - b; });
        operationNames.push_back("Scădere");

        operations.push_back([](int a, int b) { return a * b; });
        operationNames.push_back("Înmulțire");

        operations.push_back([](int a, int b) { return b != 0 ? a / b : 0; });
        operationNames.push_back("Împărțire");
    }

    void practiceSession() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 3);  // Pentru a alege o operație aleatorie
        std::uniform_int_distribution<> num(1, 10);  // Pentru numere între 1 și 10

        int score = 0;
        int totalQuestions = 5;

        for (int i = 0; i < totalQuestions; ++i) {
            int opIndex = dis(gen);
            int a = num(gen);
            int b = num(gen);

            std::cout << "\nÎntrebarea " << i+1 << ": ";
            std::cout << a << " " << (opIndex == 0 ? "+" : opIndex == 1 ? "-" : opIndex == 2 ? "*" : "/") << " " << b << " = ?\n";

            int correctAnswer = operations[opIndex](a, b);
            int userAnswer;
            std::cout << "Răspunsul tău: ";
            std::cin >> userAnswer;

            if (userAnswer == correctAnswer) {
                std::cout << "Corect!\n";
                score++;
            } else {
                std::cout << "Incorect. Răspunsul corect este: " << correctAnswer << "\n";
            }
        }

        std::cout << "\nSesiune încheiată. Scorul tău: " << score << "/" << totalQuestions << "\n";
    }
};

int main() {
    MathTutor tutor;
    std::cout << "Bine ați venit la sesiunea de practică matematică!\n";
    tutor.practiceSession();
    return 0;
}
