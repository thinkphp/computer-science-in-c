#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Forward declaration of the Person and Group classes
class Person;
class Group;

// Group class definition
class Group {
private:
    std::string groupName;
    std::vector<Person*> members;
    std::vector<std::string> messagesReceived; // List of messages received by the group

public:
    // Constructor
    Group(const std::string& name) : groupName(name) {}

    // Add a member to the group
    void addMember(Person* person);

    // Remove a member from the group
    void removeMember(Person* person);

    // Receive a message sent to the group
    void receiveMessage(const std::string& message, Person* sender);

    // Display group members
    void displayMembers() const;

    // Display messages received by the group
    void displayMessages() const;

    // Get the group's name
    std::string getName() const {
        return groupName;
    }
};

// Person class definition
class Person {
public:
    std::string name;
    std::string bio;
    std::vector<std::string> interests;
    std::vector<Person*> friends;
    std::vector<Person*> followers;
    std::vector<std::string> messagesReceived;
    std::vector<Person*> blockedList;
    std::vector<Group*> groups; // List of groups the person is a member of
    std::string status;

    // Constructor
    Person(const std::string& n) : name(n) {}

    // Add a friend
    void addFriend(Person* friendPtr);

    // Follow a person
    void followPerson(Person* personPtr);

    // Unfollow a person
    void unfollowPerson(Person* personPtr);

    // Block a person
    void blockPerson(Person* personPtr);

    // Unblock a person
    void unblockPerson(Person* personPtr);

    // Send a message to another person
    void sendMessage(Person* recipient, const std::string& message);

    // Send a message to a group
    void sendMessage(Group* group, const std::string& message);

    // Receive a message
    void receiveMessage(const std::string& message, Person* sender);

    // Display received messages
    void displayMessages() const;

    // Display information about the person and their friends
    void displayInfo() const;

    // Display the blocked list
    void displayBlockedList() const;

    // Set user's bio
    void setBio(const std::string& newBio);

    // Add interest
    void addInterest(const std::string& interest);

    // Set user's status
    void setStatus(const std::string& newStatus);

    // Display followers
    void displayFollowers() const;

    // Join a group
    void joinGroup(Group* group);

    // Leave a group
    void leaveGroup(Group* group);

    // Destructor
    virtual ~Person() {
        std::cout << name << " is being deleted." << std::endl;
    }
};

// BusinessPerson class definition
class BusinessPerson : public Person {
public:
    std::string businessName;
    std::string businessStatus;

    // Constructor
    BusinessPerson(const std::string& n, const std::string& bName)
        : Person(n), businessName(bName) {}

    // Set business status
    void setBusinessStatus(const std::string& newBusinessStatus) {
        businessStatus = newBusinessStatus;
    }

    // Display business info
    void displayBusinessInfo() const {
        displayInfo();
        std::cout << "Business Name: " << businessName << std::endl;
        std::cout << "Business Status: " << businessStatus << std::endl;
    }

    // Destructor
    ~BusinessPerson() {
        std::cout << "BusinessPerson " << name << " is being deleted." << std::endl;
    }
};

// Group class methods implementation
void Group::addMember(Person* person) {
    if (std::find(members.begin(), members.end(), person) == members.end()) {
        members.push_back(person);
        person->groups.push_back(this);
    }
}

void Group::removeMember(Person* person) {
    members.erase(std::remove(members.begin(), members.end(), person), members.end());
    person->groups.erase(std::remove(person->groups.begin(), person->groups.end(), this), person->groups.end());
}

void Group::receiveMessage(const std::string& message, Person* sender) {
    std::string formattedMessage = sender->name + ": " + message;
    messagesReceived.push_back(formattedMessage);
    for (auto& member : members) {
        if (std::find(member->blockedList.begin(), member->blockedList.end(), sender) == member->blockedList.end()) {
            member->receiveMessage(formattedMessage, sender);
        }
    }
}

void Group::displayMembers() const {
    std::cout << "Members of " << groupName << ":" << std::endl;
    for (const auto& member : members) {
        std::cout << "- " << member->name << std::endl;
    }
}

void Group::displayMessages() const {
    std::cout << "Messages in " << groupName << ":" << std::endl;
    for (const auto& message : messagesReceived) {
        std::cout << "- " << message << std::endl;
    }
}

// Person class methods implementation
void Person::addFriend(Person* friendPtr) {
    if (std::find(friends.begin(), friends.end(), friendPtr) == friends.end()) {
        friends.push_back(friendPtr);
    }
}

void Person::followPerson(Person* personPtr) {
    if (std::find(followers.begin(), followers.end(), personPtr) == followers.end()) {
        followers.push_back(personPtr);
    }
}

void Person::unfollowPerson(Person* personPtr) {
    followers.erase(std::remove(followers.begin(), followers.end(), personPtr), followers.end());
}

void Person::blockPerson(Person* personPtr) {
    if (std::find(blockedList.begin(), blockedList.end(), personPtr) == blockedList.end()) {
        blockedList.push_back(personPtr);
    }
}

void Person::unblockPerson(Person* personPtr) {
    blockedList.erase(std::remove(blockedList.begin(), blockedList.end(), personPtr), blockedList.end());
}

void Person::sendMessage(Person* recipient, const std::string& message) {
    if (std::find(recipient->blockedList.begin(), recipient->blockedList.end(), this) == recipient->blockedList.end()) {
        recipient->receiveMessage(message, this);
    } else {
        std::cout << "Message could not be delivered. " << recipient->name << " has blocked you." << std::endl;
    }
}

void Person::sendMessage(Group* group, const std::string& message) {
    group->receiveMessage(message, this);
}

void Person::receiveMessage(const std::string& message, Person* sender) {
    std::string formattedMessage = sender->name + ": " + message;
    messagesReceived.push_back(formattedMessage);
}

void Person::displayMessages() const {
    std::cout << "Messages received by " << name << ":" << std::endl;
    for (const auto& message : messagesReceived) {
        std::cout << "- " << message << std::endl;
    }
}

void Person::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Bio: " << bio << std::endl;
    std::cout << "Interests: ";
    for (const auto& interest : interests) {
        std::cout << interest << " ";
    }
    std::cout << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "Friends: ";
    for (const auto& friendPtr : friends) {
        std::cout << friendPtr->name << " ";
    }
    std::cout << std::endl;
    std::cout << "Followers: ";
    for (const auto& follower : followers) {
        std::cout << follower->name << " ";
    }
    std::cout << std::endl;
    std::cout << "Groups: ";
    for (const auto& group : groups) {
        std::cout << group->getName() << " ";
    }
    std::cout << std::endl;
}

void Person::displayBlockedList() const {
    std::cout << "Blocked persons by " << name << ":" << std::endl;
    if (blockedList.empty()) {
        std::cout << "- None" << std::endl;
    } else {
        for (const auto& blockedPtr : blockedList) {
            std::cout << "- " << blockedPtr->name << std::endl;
        }
    }
}

void Person::setBio(const std::string& newBio) {
    bio = newBio;
}

void Person::addInterest(const std::string& interest) {
    interests.push_back(interest);
}

void Person::setStatus(const std::string& newStatus) {
    status = newStatus;
}

void Person::displayFollowers() const {
    std::cout << "Followers of " << name << ":" << std::endl;
    for (const auto& follower : followers) {
        std::cout << "- " << follower->name << std::endl;
    }
}

void Person::joinGroup(Group* group) {
    group->addMember(this);
}

void Person::leaveGroup(Group* group) {
    group->removeMember(this);
}

int main() {
    // Create Person and BusinessPerson objects using pointers
    Person* person1 = new Person("Alice");
    Person* person2 = new Person("Bob");
    Person* person3 = new Person("Charlie");
    BusinessPerson* businessPerson1 = new BusinessPerson("David", "David's Tech");

    // Create Group objects using pointers
    Group* group1 = new Group("Chess Club");
    Group* group2 = new Group("Book Club");

    // Add members to groups
    group1->addMember(person1);
    group1->addMember(person2);
    group2->addMember(person3);
    group2->addMember(businessPerson1);

    // Display group members
    group1->displayMembers();
    group2->displayMembers();

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

    // Send messages to groups
    person1->sendMessage(group1, "Hello Chess Club!");
    person2->sendMessage(group1, "Hi everyone in Chess Club!");
    person3->sendMessage(group2, "Hello Book Club members!");
    businessPerson1->sendMessage(group2, "Welcome to David's Tech!");

    // Display messages received by people
    person1->displayMessages();
    person2->displayMessages();
    person3->displayMessages();
    businessPerson1->displayMessages();

    // Display messages received by groups
    group1->displayMessages();
    group2->displayMessages();

    // Display blocked list
    person2->displayBlockedList();

    // Unblock a person
    person2->unblockPerson(person1);
    person1->sendMessage(person2, "Hello Bob again!");

    // Display messages received by people after unblocking
    person2->displayMessages();

    // Display blocked list after unblocking
    person2->displayBlockedList();

    // Display personal info
    person1->setBio("A passionate chess player.");
    person1->addInterest("Chess");
    person1->addInterest("Reading");
    person1->setStatus("Feeling great!");

    person1->displayInfo();
    person2->displayInfo();
    person3->displayInfo();

    // Display business person info
    businessPerson1->setBio("Tech Enthusiast");
    businessPerson1->addInterest("Technology");
    businessPerson1->setStatus("Busy innovating!");
    businessPerson1->setBusinessStatus("Open for new projects.");

    businessPerson1->displayBusinessInfo();

    // Display followers
    person1->followPerson(person2);
    person1->followPerson(person3);
    person1->displayFollowers();

    // Leave groups
    person1->leaveGroup(group1);

    // Display group members after leaving
    group1->displayMembers();
    group2->displayMembers();

    // Free memory
    delete person1;
    delete person2;
    delete person3;
    delete businessPerson1;
    delete group1;
    delete group2;

    return 0;
}
