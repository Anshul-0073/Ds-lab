#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, x;
    
    scanf("%d", &n);

    int arr[n];
    int i = 0;

    while (i < n) {
        scanf("%d", &arr[i]);
        i++;
    }

    scanf("%d", &x);

    int index = binarySearch(arr, n, x);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } 
    else {
        printf("Element not found\n");
    }

    return 0;
}
