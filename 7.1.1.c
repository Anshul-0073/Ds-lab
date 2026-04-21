#include <stdio.h>
#include <stdlib.h>

/* Assuming TreeNode structure and required functions are defined above */

void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            exit(1);
        }

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                printf("In-Order: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Pre-Order: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Post-Order: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5: {
                int found = 0;
                printf("Enter value to delete: ");
                scanf("%d", &data);

                root = deleteNode(root, data, &found);

                if (!found) {
                    printf("Value not found\n");
                }
                break;
            }

            case 6:
                freeTree(root);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
