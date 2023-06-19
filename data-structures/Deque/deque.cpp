#include <bits/stdc++.h>

using namespace std;

typedef struct Node {

       int data;
       struct Node *next;
       struct Node *prev;

} Deque;

void create(Deque *&first, Deque *&last) {

      Deque *new_node = new Deque();
      cout<<"Node = ";
      cin>>new_node->data;
      new_node->next = NULL;
      new_node->prev = NULL;

      if(first==NULL) {
        first = new_node;
        last = first;
      } else {
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
      }
}

void display(Deque*first) {
     Deque *q = first;
     while(q!=NULL) {
       cout<<q->data<<" ";
       q = q->next;
     }
}

void push_front(Deque *&first, int data) {

     Deque *new_node = new Deque;
     new_node->data = data;
     new_node->next = first;
     new_node->prev = NULL;
     first = new_node;
}

void push_back(Deque *&last, int data) {

  Deque *new_node = new Deque;
  new_node->data = data;
  new_node->next = NULL;
  last->next = new_node;
  new_node->prev = last;
  last = new_node;
}

void remove_back(Deque *&last) {

  Deque *q = last;
  last = last->prev;
  last->next = NULL;
  delete q;
}

void remove_front(Deque *&first) {

     Deque *q = first;
     first = first->next;
     first->prev = NULL;
     delete q;
}

void menu ()
{
    cout << "\nYour Options are:" << endl;
    cout << "1. Push Front" << endl;
    cout << "2. Push Back" << endl;
    cout << "3. Remove Front" << endl;
    cout << "4. Remove Back" << endl;
    cout << "5. Exit" << endl;
}

int main(int argc, char const *argv[]) {

  Deque *first = NULL,
        *last = NULL;
  int count;
  cout<<"N=";
  cin>>count;
  for (size_t i = 0; i < count; i++) create(first, last);

  display(first);
  int data;

  cout<<"node=";
  cin>>data;
  push_front(first,data);
  display(first);

  cout<<"node=";
  cin>>data;
  push_back(last,data);
  display(first);

  cout<<"\nRemove front()\n";
  remove_front(first);
  display(first);

  cout<<"\nRemove back()\n";
  remove_back(last);
  display(first);

  menu();

  int x;
    cout << "Your choice: ";
    cin >> x;

    while (x != 5)
        {
             switch (x)
            {
                case 1:


                    cout << endl;
                    break;
                case 2:


                    cout << endl;
                    break;

                case 3:

                    cout << endl;
                    break;
                case 4:

                    cout << endl;
                    break;

                case 5:

                    return 0;
            }
            cin >> x;
        }
        
        cout<<"Bye!";
}
