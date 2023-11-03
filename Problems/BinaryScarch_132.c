//Name: MD SHAFIUL AZAM
//ID:2122503132
#include <stdio.h>
int element(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[100];
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the sorted elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = element(arr, 0, n - 1, key);
    printf("\n");
    if (index != -1) {
        printf("Key found at index\n", index);
    } else {
        printf("Key not found\n");
    }
    return 0;
}
