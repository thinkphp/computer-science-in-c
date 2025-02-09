#include <iostream>
#include <string>

class WebPage {
public:
    std::string url;
    std::string title;
    WebPage* next;
    WebPage* prev;

    WebPage(const std::string& url, const std::string& title)
        : url(url), title(title), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
private:
    WebPage* head;        // First page in history
    WebPage* current;     // Current page being viewed
    int historySize;      // Track total pages in history

public:
    BrowserHistory() : head(nullptr), current(nullptr), historySize(0) {}

    ~BrowserHistory() {
        while (head != nullptr) {
            WebPage* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Visit a new webpage
    void visit(const std::string& url, const std::string& title) {
        WebPage* newPage = new WebPage(url, title);

        // If this is the first page
        if (head == nullptr) {
            head = newPage;
            current = newPage;
        } else {
            // If we're not at the end of history, delete forward history
            if (current->next != nullptr) {
                deleteForwardHistory(current->next);
            }

            // Add new page after current
            newPage->prev = current;
            current->next = newPage;
            current = newPage;
        }
        historySize++;
        displayCurrentPage();
    }

    // Go back one page
    bool goBack() {
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
            displayCurrentPage();
            return true;
        }
        std::cout << "Cannot go back - At oldest page in history\n";
        return false;
    }

    // Go forward one page
    bool goForward() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            displayCurrentPage();
            return true;
        }
        std::cout << "Cannot go forward - At newest page in history\n";
        return false;
    }

    // Display current page
    void displayCurrentPage() const {
        if (current != nullptr) {
            std::cout << "Currently viewing: " << current->title
                      << " (" << current->url << ")\n";
        } else {
            std::cout << "No page is currently being viewed\n";
        }
    }

    // Display entire history
    void displayHistory() const {
        std::cout << "\nBrowser History (Latest to Oldest):\n";
        WebPage* temp = current;

        // First, go to the most recent page
        while (temp != nullptr && temp->next != nullptr) {
            temp = temp->next;
        }

        // Then print backwards
        while (temp != nullptr) {
            std::cout << temp->title << " (" << temp->url << ")";
            if (temp == current) {
                std::cout << " <- Current";
            }
            std::cout << "\n";
            temp = temp->prev;
        }
        std::cout << "Total pages in history: " << historySize << "\n";
    }

private:
    // Helper function to delete all forward history from a given point
    void deleteForwardHistory(WebPage* startNode) {
        while (startNode != nullptr) {
            WebPage* temp = startNode;
            startNode = startNode->next;
            delete temp;
            historySize--;
        }
    }
};

int main() {
    BrowserHistory browser;

    // Simulate browser navigation
    std::cout << "Simulating browser navigation...\n\n";

    // Visit some pages
    browser.visit("www.google.com", "Google");
    browser.visit("www.github.com", "GitHub");
    browser.visit("www.stackoverflow.com", "Stack Overflow");
    browser.visit("www.cpp-reference.com", "C++ Reference");

    // Display full history
    browser.displayHistory();

    // Navigate back twice
    std::cout << "\nGoing back twice...\n";
    browser.goBack();
    browser.goBack();

    // Visit a new page (this should clear forward history)
    std::cout << "\nVisiting new page while in middle of history...\n";
    browser.visit("www.wikipedia.org", "Wikipedia");

    // Display updated history
    browser.displayHistory();

    // Try going forward (should fail as forward history was cleared)
    std::cout << "\nTrying to go forward...\n";
    browser.goForward();

    // Go back to start
    std::cout << "\nGoing back to start...\n";
    while (browser.goBack()) {}

    // Try going back again (should fail)
    std::cout << "\nTrying to go back again...\n";
    browser.goBack();

    return 0;
}
