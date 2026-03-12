#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }

        if (maxIndex != i) {
            int temp = arr[maxIndex];
            arr[maxIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int i;

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, n);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
