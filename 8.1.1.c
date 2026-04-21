#include <stdio.h>
#include <stdlib.h>

/* update vertex numbers in adjacency lists */
void updateVertices(int *N, int v) {
    int i;
    GNODE temp;

    for (i = 1; i < *N; i++) {
        temp = graph[i];

        while (temp != NULL) {
            if (temp->vertex > v) {
                temp->vertex--;
            }
            temp = temp->next;
        }
    }

    (*N)--;

    printf("After deleting vertex, the adjacency list is:\n");
    print(N);
}

void deleteEdge(int *N) {
    int src, dest;
    GNODE temp, prev;

    printf("Enter the source vertex of the edge: ");
    scanf("%d", &src);

    printf("Enter the destination vertex of the edge: ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    temp = graph[src];
    prev = NULL;

    while (temp != NULL) {
        if (temp->vertex == dest) {
            if (prev == NULL) {
                graph[src] = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("After deleting edge, the adjacency list is:\n");
    print(N);
}
