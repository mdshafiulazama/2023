#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int quick(int arr[], int low, int high) {
    int sort = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < sort) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int sort = quick(arr, low, high);
        quickSort(arr, low, sort - 1);
        quickSort(arr, sort + 1, high);
    }
}
void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int n;
    printf("Array Size:  ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

    }
      quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    print(arr, n);

    return 0;
}
