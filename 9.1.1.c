#include <stdio.h>

/* Assuming Node structure, adjList, visited array, and addEdge() are defined above */

/* Sorting adjacency list */
void sortAdjList(int V) {
    Node *p, *q;

    for (int i = 0; i < V; i++) {
        p = adjList[i];

        while (p != NULL) {
            q = p->next;

            while (q != NULL) {
                if (p->vertex > q->vertex) {
                    int temp = p->vertex;
                    p->vertex = q->vertex;
                    q->vertex = temp;
                }
                q = q->next;
            }

            p = p->next;
        }
    }
}

/* Depth-First Search (DFS) function */
void DFS(int start) {
    visited[start] = 1;
    printf("%d ", start);

    Node* temp = adjList[start];

    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int V, E;
    int u, v, start;

    /* Read number of vertices and edges */
    scanf("%d %d", &V, &E);

    /* Initialize adjacency list and visited array */
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    /* Read the edges */
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    /* Sort the adjacency list for each vertex */
    sortAdjList(V);

    /* Read the starting node */
    scanf("%d", &start);

    /* Perform DFS starting from the given node */
    DFS(start);

    return 0;
}
