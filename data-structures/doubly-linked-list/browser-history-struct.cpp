#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100
#define MAX_TITLE_LENGTH 100

// Structure for a webpage node
struct WebPage {
    char url[MAX_URL_LENGTH];
    char title[MAX_TITLE_LENGTH];
    struct WebPage* next;
    struct WebPage* prev;
};

// Structure to manage browser history
struct BrowserHistory {
    struct WebPage* head;
    struct WebPage* current;
    int historySize;
};

// Function to create a new webpage node
struct WebPage* createWebPage(const char* url, const char* title) {
    struct WebPage* newPage = (struct WebPage*)malloc(sizeof(struct WebPage));
    strncpy(newPage->url, url, MAX_URL_LENGTH - 1);
    strncpy(newPage->title, title, MAX_TITLE_LENGTH - 1);
    newPage->url[MAX_URL_LENGTH - 1] = '\0';
    newPage->title[MAX_TITLE_LENGTH - 1] = '\0';
    newPage->next = NULL;
    newPage->prev = NULL;
    return newPage;
}

// Initialize browser history
struct BrowserHistory* initBrowserHistory() {
    struct BrowserHistory* history = (struct BrowserHistory*)malloc(sizeof(struct BrowserHistory));
    history->head = NULL;
    history->current = NULL;
    history->historySize = 0;
    return history;
}

// Delete forward history from a given point
void deleteForwardHistory(struct WebPage* startNode) {
    struct WebPage* current = startNode;
    while (current != NULL) {
        struct WebPage* temp = current;
        current = current->next;
        free(temp);
    }
}

// Visit a new webpage
void visit(struct BrowserHistory* history, const char* url, const char* title) {
    struct WebPage* newPage = createWebPage(url, title);

    // If this is the first page
    if (history->head == NULL) {
        history->head = newPage;
        history->current = newPage;
    } else {
        // If we're not at the end of history, delete forward history
        if (history->current->next != NULL) {
            deleteForwardHistory(history->current->next);
        }

        // Add new page after current
        newPage->prev = history->current;
        history->current->next = newPage;
        history->current = newPage;
    }
    history->historySize++;

    // Display current page
    printf("Currently viewing: %s (%s)\n", history->current->title, history->current->url);
}

// Go back one page
int goBack(struct BrowserHistory* history) {
    if (history->current != NULL && history->current->prev != NULL) {
        history->current = history->current->prev;
        printf("Currently viewing: %s (%s)\n", history->current->title, history->current->url);
        return 1;
    }
    printf("Cannot go back - At oldest page in history\n");
    return 0;
}

// Go forward one page
int goForward(struct BrowserHistory* history) {
    if (history->current != NULL && history->current->next != NULL) {
        history->current = history->current->next;
        printf("Currently viewing: %s (%s)\n", history->current->title, history->current->url);
        return 1;
    }
    printf("Cannot go forward - At newest page in history\n");
    return 0;
}

// Display current page
void displayCurrentPage(struct BrowserHistory* history) {
    if (history->current != NULL) {
        printf("Currently viewing: %s (%s)\n", history->current->title, history->current->url);
    } else {
        printf("No page is currently being viewed\n");
    }
}

// Display entire history
void displayHistory(struct BrowserHistory* history) {
    printf("\nBrowser History (Latest to Oldest):\n");
    struct WebPage* temp = history->current;

    // First, go to the most recent page
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    // Then print backwards
    while (temp != NULL) {
        printf("%s (%s)", temp->title, temp->url);
        if (temp == history->current) {
            printf(" <- Current");
        }
        printf("\n");
        temp = temp->prev;
    }
    printf("Total pages in history: %d\n", history->historySize);
}

// Free all memory used by browser history
void freeBrowserHistory(struct BrowserHistory* history) {
    struct WebPage* current = history->head;
    while (current != NULL) {
        struct WebPage* temp = current;
        current = current->next;
        free(temp);
    }
    free(history);
}

int main() {
    struct BrowserHistory* browser = initBrowserHistory();

    printf("Simulating browser navigation...\n\n");

    // Visit some pages
    visit(browser, "www.google.com", "Google");
    visit(browser, "www.github.com", "GitHub");
    visit(browser, "www.stackoverflow.com", "Stack Overflow");
    visit(browser, "www.cpp-reference.com", "C++ Reference");

    // Display full history
    displayHistory(browser);

    // Navigate back twice
    printf("\nGoing back twice...\n");
    goBack(browser);
    goBack(browser);

    // Visit a new page (this should clear forward history)
    printf("\nVisiting new page while in middle of history...\n");
    visit(browser, "www.wikipedia.org", "Wikipedia");

    // Display updated history
    displayHistory(browser);

    // Try going forward (should fail as forward history was cleared)
    printf("\nTrying to go forward...\n");
    goForward(browser);

    // Go back to start
    printf("\nGoing back to start...\n");
    while (goBack(browser)) {}

    // Try going back again (should fail)
    printf("\nTrying to go back again...\n");
    goBack(browser);

    // Clean up
    freeBrowserHistory(browser);

    return 0;
}
