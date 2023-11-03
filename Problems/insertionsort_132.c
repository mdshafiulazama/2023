//Name: MD SHAFIUL AZAM
//ID:2122503132
#include <stdio.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
int main() {
    int arr[100];
    int n;
    printf("Enter the elements size: ");
    scanf("%d", &n);
    printf("Enter the elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);
    printf("after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
