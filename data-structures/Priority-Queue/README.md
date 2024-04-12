### Priority Queue
A priority queue is a type of queue that arranges elements based on their priority values. Elements with higher priority values are typically retrieved before elements with lower priority values.

In a priority queue, each element has a priority value associated with it. When you add an element to the queue, it is inserted in a position based on its priority value.


#### Priority Queue in C++ Standard Template Library (STL)

https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

```

#include <iostream>
#include <queue>
using namespace std;
 
// driver code
int main()
{
    int arr[6] = { 10, 2, 4, 8, 6, 9 };
 
    // defining priority queue
    priority_queue<int> pq;
 
    // printing array
    cout << "Array: ";
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;
    // pushing array sequentially one by one
    for (int i = 0; i < 6; i++) {
        pq.push(arr[i]);
    }
 
    // printing priority queue
    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
 
    return 0;
}
```

```
#include <iostream>
#include <queue>
using namespace std;
 
void showpq(
    priority_queue<int, vector<int>, greater<int> > g)
{
    while (!g.empty()) {
        cout << ' ' << g.top();
        g.pop();
    }
    cout << '\n';
}
 
void showArray(int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
 
// Driver Code
int main()
{
    int arr[6] = { 10, 2, 4, 8, 6, 9 };
    priority_queue<int, vector<int>, greater<int> > gquiz(
        arr, arr + 6);
 
    cout << "Array: ";
      showArray(arr, 6);
 
    cout << "Priority Queue : ";
    showpq(gquiz);
 
    return 0;
}
```
