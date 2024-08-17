#include <stdio.h>

int V[101], n; // Increase array size to accommodate index 1

int getIndMin(int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    if (left <= n && V[left] < V[smallest]) {
        smallest = left;
    }
    if (right <= n && V[right] < V[smallest]) {
        smallest = right;
    }
    return smallest;
}

void heapify(int i, int n) {
    int smallest = getIndMin(i, n);

    while (smallest != i) {
        int temp = V[i];
        V[i] = V[smallest];
        V[smallest] = temp;

        i = smallest;
        smallest = getIndMin(i, n);
    }
}

void minHeap() {
    for (int i = n / 2; i >= 1; i--) {
        heapify(i, n);
    }
}

void heapsort() {
    minHeap();

    for (int i = n; i >= 2; i--) {
        int temp = V[1];
        V[1] = V[i];
        V[i] = temp;

        heapify(1, i - 1);
    }
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &V[i]);
    }
    heapsort();
    for (int i = 1; i <= n; ++i) {
        printf("%d ", V[i]);
    }
    printf("\n");
    return 0;
}
