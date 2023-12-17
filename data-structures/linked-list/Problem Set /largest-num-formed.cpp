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
Consideram o lista simplu inlantuita care retine cifrele unui numar natural.
Sa se realizeze o functie care primeste la apel, printr-un parametru, adresa de inceput
a unei astfel de liste si returneaza cel mai mare numar care se poate forma cu cifrele distincte.

Input: 3, 1, 2, 8
Output: 8321

*/

#include <bits/stdc++.h>
#include <chrono>

#define TIMER_START auto TIME_START = std::chrono::high_resolution_clock::now()
#define TIMER_END auto TIME_END = std::chrono::high_resolution_clock::now()
#define TIMECHECK std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(TIME_END - TIME_START).count() << "ms" << std::endl

using namespace std;

typedef double f64;
typedef long long i64;
typedef int i32;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<i32> vi32;
typedef deque<i32> di32;

struct Node {

     int data;

     struct Node *next;

} *head = NULL;

void CreateList( Node *&head ) {
     Node*q;
     int n,x;
     printf("N = ");
     cin>>n;
     while(n--){
       printf("Node = ");
       cin>>x;
       q = new Node;
       q->data = x;
       q->next = head;
       head = q;
     }
}

void Display( Node*head ) {

     for( Node*q = head; q != nullptr; q = q->next ) printf("%d ", q->data);
}

void solve( Node *head ) {

     char cnt[ 10 ];
     long long num = 0;

     memset(cnt, 0, sizeof(cnt));

     for(Node*q=head;q!=nullptr;q=q->next)
          cnt[q->data] = 1;

     for(int i = 9; i >=0; --i) {

          if(cnt[i]) {
            num = num* 10 + i;
          }
     }
     printf("%lld\n", num);
}

int main() {

    CreateList(head);
    Display(head);
    solve(head);
    TIMER_START;

    printf("\nRunning time: ");
    TIMER_END;
    TIMECHECK;

    return 0;
}
