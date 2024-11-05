#include <stdio.h>
#include <stdlib.h>

#define n 10

void insertionSort(int a[], int size);
int binarySearch(int a[], int key, int left, int right);

int main() {
    int a[n], key, i;

    printf("***** BINARY SEARCH *****\n\n");
    printf("Enter 10 numbers:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertionSort(a, n);

    printf("\nEnter the number to search: ");
    scanf("%d", &key);

    int foundIndex = binarySearch(a, key, 0, n - 1);

    if (foundIndex != -1)
        printf("\n%d was found at position %d\n", key, foundIndex + 1);
    else
        printf("\n%d was not found\n", key);

    return 0;
}

void insertionSort(int a[], int size) {
    int i, j, temp;
    for (i = 1; i < size; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int binarySearch(int a[], int key, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Key not found
}
