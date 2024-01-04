#include <iostream>

int left[100],
    right[100];

void readBinTree() {
    int n,
        node;
    printf("nodes=");
    scanf("%d",&n);

    for(int i = 1; i <= n; ++i) {

        printf("node %d: ",i);
        printf("left=");
        scanf("%d",&node);
        left[i] = node;
        printf("right=");
        scanf("%d",&node);
        right[i] = node;
    }
}

void inorder(int node) {
     if(node != 0) {
       inorder(left[node]);
       printf("%d ", node);
       inorder(right[node]);
     }
}

void preorder(int node) {
     if(node != 0) {
       printf("%d ", node);
       inorder(left[node]);
       inorder(right[node]);
     }
}

void postorder(int node) {
     if(node != 0) {
       inorder(left[node]);
       inorder(right[node]);
       printf("%d ", node);
     }
}

int main(int argc, char const *argv[]) {

  readBinTree();
  inorder(1);
       printf("\n");
  preorder(1);
       printf("\n");
  postorder(1);

  return 0;
}
