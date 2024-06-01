#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

class SkipListNode {
public:
    int value;
    std::vector<SkipListNode*> forward;

    SkipListNode(int value, int level)
        : value(value), forward(level, nullptr) {}
};

class SkipList {
private:
    int maxLevel;
    float probability;
    int currentLevel;
    SkipListNode* header;

    int randomLevel() {
        int level = 1;
        while (((float)std::rand() / RAND_MAX) < probability && level < maxLevel) {
            level++;
        }
        return level;
    }

public:
    SkipList(int maxLevel, float probability)
        : maxLevel(maxLevel), probability(probability), currentLevel(1) {
        header = new SkipListNode(-1, maxLevel);
        std::srand(std::time(nullptr));
    }

    ~SkipList() {
        delete header;
    }

    void insert(int value) {
        std::vector<SkipListNode*> update(maxLevel, nullptr);
        SkipListNode* current = header;

        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current == nullptr || current->value != value) {
            int rlevel = randomLevel();

            if (rlevel > currentLevel) {
                for (int i = currentLevel; i < rlevel; i++) {
                    update[i] = header;
                }
                currentLevel = rlevel;
            }

            SkipListNode* newNode = new SkipListNode(value, rlevel);

            for (int i = 0; i < rlevel; i++) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    bool search(int value) {
        SkipListNode* current = header;

        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
        }

        current = current->forward[0];

        return current != nullptr && current->value == value;
    }

    void remove(int value) {
        std::vector<SkipListNode*> update(maxLevel, nullptr);
        SkipListNode* current = header;

        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current != nullptr && current->value == value) {
            for (int i = 0; i < currentLevel; i++) {
                if (update[i]->forward[i] != current) {
                    break;
                }
                update[i]->forward[i] = current->forward[i];
            }

            while (currentLevel > 1 && header->forward[currentLevel - 1] == nullptr) {
                currentLevel--;
            }

            delete current;
        }
    }
};

int main() {
    SkipList list(16, 0.5);

    list.insert(3);
    list.insert(6);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(19);
    list.insert(17);
    list.insert(26);
    list.insert(21);
    list.insert(25);

    std::cout << "Search for 19: " << (list.search(19) ? "Found" : "Not Found") << std::endl;
    list.remove(19);
    std::cout << "Search for 19 after deletion: " << (list.search(19) ? "Found" : "Not Found") << std::endl;

    return 0;
}
