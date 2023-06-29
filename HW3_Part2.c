#include <stdio.h>
#include <stdlib.h>

// Binary search
// bubble sort function
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// binary search function
int binarySearch(int arr[], int n, int t) {
    int l = 0;
    int r = n-1;
    
    while (l <= r) {
        int mid = l + (r-l)/2;

        if (arr[mid] == t) {
            return mid;
        } 
        else if (arr[mid] < t) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return -1;
}

void printArray(int arr[], int n) {
    if (n > 0) {
        for (int i=0; i<n; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}


// print the result
int main() {
    int n, target, i;
    
    printf("Input array size: \n");
    scanf("%d", &n);

    int arr[n];
    printf("Input elements of the array: \n");
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Input target: \n");
    scanf("%d", &target);

    printf("The array: \n");

    printArray(arr, n);

    printf("The target: \n%d", target);
    
    int result = binarySearch(arr, n, target);
    printf("\nSearch result: \n%d", result);

    return 0;
}