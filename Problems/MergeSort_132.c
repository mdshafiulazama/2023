
#include <stdio.h>
void merge(int arr[], int left, int mid, int right) {
    int i=0, j=0, k=left,n1,n2;
     n1 = mid-left + 1;
     n2 = right-mid;
    int L[n1];
    int R[n2];
    for (int i = 0; i<n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j<n2; j++)
        R[j] = arr[mid + 1 + j];

    while (i<n1 && j<n2) {
        if (L[i]<= R[j]) {
            arr[k]=L[i];
            i++;
        } else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int left,int right) {
    if (left < right) {
        int mid = left+(right-left) / 2;
        mergeSort(arr,left,mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
int main() {
    int size;
    printf("Enter  Array Size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, size - 1);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
