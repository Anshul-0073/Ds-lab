#include <stdio.h>
#include <stdlib.h>

/* Assuming Node structure and global heads are defined somewhere above */

void concatenate() {
    if (head == NULL) {
        head = secondHead;
    } else {
        struct Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = secondHead;

        if (secondHead != NULL) {
            secondHead->prev = temp;
        }
    }

    struct Node* curr = head;

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main() {
    int choice, num;

    while (1) {
        printf("\nEnter operation:\n");
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Display\n");
        printf("4: Reverse\n");
        printf("5: Concatenate\n");
        printf("6: Exit\n");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &num);
                insert(num);
                break;

            case 2:
                printf("Enter number to delete: ");
                scanf("%d", &num);
                deleteNumber(num);
                break;

            case 3:
                display();
                break;

            case 4:
                reverseList();
                break;

            case 5:
                concatenate();
                break;

            case 6:
                printf("Exit\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
