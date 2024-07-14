#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Person {
public:
    std::string name;
    std::vector<Person*> friends;
    std::vector<std::string> messagesReceived;
    std::vector<Person*> blockedList;

    // Constructor
    Person(const std::string& n) : name(n) {}

    // Add a friend
    void addFriend(Person* friendPtr) {
        if (std::find(friends.begin(), friends.end(), friendPtr) == friends.end()) {
            friends.push_back(friendPtr);
        }
    }

    // Block a person
    void blockPerson(Person* personPtr) {
        if (std::find(blockedList.begin(), blockedList.end(), personPtr) == blockedList.end()) {
            blockedList.push_back(personPtr);
        }
    }

    // Unblock a person
    void unblockPerson(Person* personPtr) {
        blockedList.erase(std::remove(blockedList.begin(), blockedList.end(), personPtr), blockedList.end());
    }

    // Send a message to another person
    void sendMessage(Person* recipient, const std::string& message) {
        if (std::find(recipient->blockedList.begin(), recipient->blockedList.end(), this) == recipient->blockedList.end()) {
            recipient->receiveMessage(message, this);
        } else {
            std::cout << "Message could not be delivered. " << recipient->name << " has blocked you." << std::endl;
        }
    }

    // Receive a message
    void receiveMessage(const std::string& message, Person* sender) {
        std::string formattedMessage = sender->name + ": " + message;
        messagesReceived.push_back(formattedMessage);
    }

    // Display received messages
    void displayMessages() const {
        std::cout << "Messages received by " << name << ":" << std::endl;
        for (const auto& message : messagesReceived) {
            std::cout << "- " << message << std::endl;
        }
    }

    // Display information about the person and their friends
    void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Friends: ";
        for (const auto& friendPtr : friends) {
            std::cout << friendPtr->name << " ";
        }
        std::cout << std::endl;
    }

    // Display the blocked list
    void displayBlockedList() const {
        std::cout << "Blocked persons by " << name << ":" << std::endl;
        if (blockedList.empty()) {
            std::cout << "- None" << std::endl;
        } else {
            for (const auto& blockedPtr : blockedList) {
                std::cout << "- " << blockedPtr->name << std::endl;
            }
        }
    }

    // Destructor
    ~Person() {
        std::cout << name << " is being deleted." << std::endl;
    }
};

int main() {
    // Create Person objects using pointers
    Person* person1 = new Person("Alice");
    Person* person2 = new Person("Bob");
    Person* person3 = new Person("Charlie");

    // Add friends
    person1->addFriend(person2);
    person1->addFriend(person3);
    person2->addFriend(person1);

    // Block a person
    person2->blockPerson(person1);

    // Send messages between people
    person1->sendMessage(person2, "Hello Bob!");
    person3->sendMessage(person1, "Hi Alice, how are you?");
    person2->sendMessage(person1, "Hi Alice!");

    // Display messages received by people
    person1->displayMessages();
    person2->displayMessages();
    person3->displayMessages();

    // Display blocked list
    person2->displayBlockedList();

    // Unblock a person
    person2->unblockPerson(person1);
    person1->sendMessage(person2, "Hello Bob again!");

    // Display messages received by people after unblocking
    person2->displayMessages();

    // Display blocked list after unblocking
    person2->displayBlockedList();

    // Free memory
    delete person1;
    delete person2;
    delete person3;

    return 0;
}
