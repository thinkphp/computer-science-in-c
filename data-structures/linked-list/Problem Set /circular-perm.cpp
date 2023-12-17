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

Task: Realizati in program care afiseaza numerele obtinute prin permutari circulare ale
cifrelor unui numar natural Nr preluat de la tastatura. Cifrele lui Nr vor fi
retinute intr-o lista simplu inlantuita. Vor fi implementate doua subprograme:

- subprogramul CreateList, care permite memorarea cifrelor numarului Nr intr-o lista
simplu inlantuita. Subprogramul va returna adresa de inceput a listei create prin intermediul unui parametru
- subprogramul Permut, care primind la apel, prin intermediul unui parametru, adresa de inceput a unui liste, realizeaza transferul primului element la finalul listei, fara a folosi memorie suplimentar. Subprogramul va returna noua adresa de inceput a listei prin intermediul aceluiasi parametru.

Input: Nr = 1234
Output: 2341, 3412, 4123, 1234

*/

#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
} *head, *aux;

long nr;

void CreateList(long nr, struct Node *&p) {
  p = NULL;
  struct Node *q;
  while (nr) {
    q = new Node;
    q->data = nr % 10;
    q->next = p;
    nr /= 10;
    p = q;
  }
}

void permut(struct Node *&p) {

  if (p == NULL || p->next == nullptr) {
    return; // Nothing to permute for empty or single-node list
  }

  struct Node *q = p;

  while (q->next != nullptr) {
    q = q->next;
  }

  q->next = p;
  
  p = p->next;
  
  q->next->next = nullptr;
}

void display(struct Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}

int main(int argc, char const *argv[]) {
  cout << "Nr=";
  cin >> nr;
  CreateList(nr, head);
  display(head);
  aux = head;
  do {
    permut(head);
    display(head);
  } while (aux != head);

  return 0;
}
