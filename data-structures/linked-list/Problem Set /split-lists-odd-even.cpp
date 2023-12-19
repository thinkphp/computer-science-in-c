/*
                _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . ___
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
Book:
Fundamentele Programarii. Culegere de probleme pentru clasa a X1-a. Autori: Dana Lica si Mircea Pasoi

Consideram o lista simplu inlantuita ce memoreaza valori intregi.
Realizati un subprogram care primeste la apel, prin intermediul unui
unui parametru p, adresa de inceput a unei astfel de liste, separa
elementele in doua liste, una formata din valori pare, iar cealalta, din valori impare.
Subprogramul va returna adresele de inceput ale celor doua liste create prin intermediul a doi parametri.



Input:

Output:

*/
#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node *next;
};
 
void CreateList(Node *&head) {
    Node *q, *last;
    int node, n;
    head = nullptr;
    last = nullptr;
 
    cout << "number of nodes=";
    cin >> n;
 
    while (n--) {
        cout << "node=";
        cin >> node;
 
        q = new Node;
        q->data = node;
        q->next = nullptr;
 
        if (!head) {
            head = last = q;
        } else {
            last->next = q;
            last = q;
        }
    }
}
 
void split(Node *head, Node *&l1, Node *&l2) {
    Node *evenHead = new Node; // for even
    Node *oddHead = new Node;  // for odd
 
    Node *evenLast = evenHead;
    Node *oddLast = oddHead;
 
    while (head != nullptr) {
        if (head->data % 2 == 1) {
            oddLast->next = head;
            oddLast = head;
            head = head->next;
            oddLast->next = nullptr;
        } else {
            evenLast->next = head;
            evenLast = head;
            head = head->next;
            evenLast->next = nullptr;
        }
    }
 
    l1 = evenHead->next;
    l2 = oddHead->next;
 
    delete evenHead;
    delete oddHead;
}
 
void display(Node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 
int main(int argc, char const *argv[]) {
    Node *head, *L1, *L2;
    CreateList(head);
    display(head);
 
    split(head, L1, L2);
 
    cout << "Even List: ";
    display(L1);
 
    cout << "Odd List: ";
    display(L2);
 
    return 0;
}
