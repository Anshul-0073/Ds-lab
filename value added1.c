#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left  = insert(root->left,  val);
    else                 root->right = insert(root->right, val);
    return root;
}

void findInRange(Node* root, int low, int high) {
    if (!root) return;
    if (root->val > low)  findInRange(root->left,  low, high);
    if (root->val >= low && root->val <= high) printf("%d ", root->val);
    if (root->val < high) findInRange(root->right, low, high);
}

int main() {
    int n, val, low, high;
    Node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter low high: ");
    scanf("%d %d", &low, &high);

    printf("Output: ");
    findInRange(root, low, high);
    printf("\n");

    return 0;
}
