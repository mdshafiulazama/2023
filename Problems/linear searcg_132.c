//Name: MD SHAFIUL AZAM
//ID:2122503132
#include <stdio.h>
int elements(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() {
    int a[100];
    int n, key;
    printf("How many elements to search : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter to search: ");
    scanf("%d", &key);
    int index =  elements(a, n, key);
    if (index != -1) {
        printf("found \n", index);
    } else {
        printf("not found\n",key);
    }
    getch ();
}
