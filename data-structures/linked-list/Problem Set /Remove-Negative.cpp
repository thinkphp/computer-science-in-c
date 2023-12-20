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

Consideram o lista simplu inlantuita in care sunt retinute
valori intregi distincte. Realizati un subprogram care, primeste la apel,
prin intermediul unui parametru head, adresa de inceput a unei astfel de liste
si efectueaza stergerea nodurilor de informatie negativa.
Subprogramul va intoarce noua adresa de inceput a listei tot prin parametrul head.

Input:
-1 3 -5 1 -2 3
Output:
1 2 3
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
     int data;
     struct Node *next;
};

void CreateList(struct Node *&head) {
     int node, nr;
     struct Node*q;
      cout<<"number of elements:";
      cin>>nr;

      while(nr--) {
        cin>>node;
        q = new Node;
        q->data = node;
        q->next = head;
        head = q;
      }

}

void DisplayList(struct Node *head) {
    while(head) {
      cout<<head->data<<" ";
      head = head->next;
    }

    cout<<endl;
}

void Remove_negative_elements(struct Node*&head) {

  struct Node*q,
             *last,
             *tmp;
  q = new Node;
  q->next = head;
  last = q;

  while(head != NULL) {

       if( head->data < 0 ) {

            tmp = head;

            last->next = head->next;

            head = head->next;

            delete tmp;

       } else {

            last = last->next;
            head = head->next;
       }
  }

  head = q->next;

  delete q;
}

int main(int argc, char const *argv[]) {

  struct Node *head = NULL;

  CreateList(head);
  DisplayList(head);
  Remove_negative_elements(head);
  DisplayList(head);

  return 0;

}
