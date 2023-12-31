
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
valori naturale distincte. Sa se realizeze un subprogram care sterge
elementul din lista ce contine cel mai mare numar prim. Subprogramul
va primi la apel, prin intermediul unui parametru, adresa de inceput
a listei.
Input:
3, 1, 2, 8, 14, 9, 7, 5
Output:
will remove 7
3, 1, 2, 8, 14, 9, 5
*/
#include <iostream>
using namespace std;
struct Node {
     int data;
     struct Node *next;
};

int isPrime(int nr) {

    if(nr==1)return 0;
    if(nr==2 || nr == 3) return 1;
    int i = 2,
        prime = 1;
    while(i*i<=nr && prime) {
      prime = (nr%i != 0);
      i++;
    }
    return prime;
}

void CreateList(struct Node*&p, int nr) {
     struct Node*q;
     int node;
     for(int i = 1; i <= nr; ++i) {
       cout<<"node=";
       cin>>node;
       q = new Node;
       q->data = node;
       q->next = p;
       p = q;
     }
}

void DisplayList(struct Node*head) {

     for(struct Node *q = head;q != NULL; q = q->next) {

       cout<<q->data<<" ";
     }

     cout<<"\n";
}

void remove_largest_prime(struct Node*&p, int nr) {
       struct Node *q = p,
                   *tmp = NULL;
       int max;

       if(isPrime(p->data)) max = p->data;

       else max = 0;

       while(q->next != NULL) {

         if( isPrime(q->next->data) && q->next->data > max ) {

            max = q->next->data;
            tmp = q;
         }
         q = q->next;
       }

       if(max!=0) {
         if(tmp == NULL) {
           tmp = p;
           p = p->next;
           delete tmp;
         } else {
           q = tmp->next;
           tmp->next = tmp->next->next;
           delete q;
         }

       }
}

int main(int argc, char const *argv[]) {
  int nr;
  cout<<"nr=";
  cin>>nr;
  struct Node *head = NULL;
  CreateList(head, nr);
  DisplayList(head);
  remove_largest_prime(head,nr);
  DisplayList(head);
  return 0;
}
