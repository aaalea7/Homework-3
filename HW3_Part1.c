#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Linear Search

// function to convert decimal to binary
int convertToBinary(int n) {
    int binaryNumber = 0;
    int r = 0;
    int i = 1; // i is the pos in the binary number

    // n is a decimal number
    // n = 2; r = 0; n = 1; binaryNumber = 0, i = 10
    while (n!=0) {
        r = n%2; 
        n/=2;
        binaryNumber = binaryNumber + r * i;
        i*=10; // times 10 for each iteration as a binary number
    }
    return binaryNumber;
}

// function to convert binary to decimal
int convertToDecimal(int n) {
    int decimalNumber = 0;
    int i = 0; // initialize
    int r;

    while (n!=0) {
        // n = 0010, r = 0010%10 = 0; n = 1; decimalNumber = 2; i+=1 
        r = n%10;
        n/=10;
        decimalNumber = decimalNumber + r * pow(2, i);
        i++;
    }
    return decimalNumber;
}

// linear search function
// n = converted number, x = converted target
int linearSearch(int arr[], int n, int t) {
    int i;
    for (i=0; i<n; i++) {
        if (arr[i] == t) {
            return i; // exist, return target pos
        }
    }
    return -1; // not exist
}

// print the result
int main() {
    int n, target, i;

    printf("Input array size: \n");
    scanf("%d", &n);

    int arr[n];
    int arr_0[n];
    printf("Input elements of the array: \n");
    for (i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
        arr_0[i] = arr[i];
    }
    int target_0;
    printf("Input target: \n");
    scanf("%d", &target);
    target_0 = target;

    printf("The array: \n");
    for (i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nThe target: \n%d\n", target);

    for (i = 0; i<n; i++) {
        arr[i] = convertToBinary(arr[i]);
    }
    target = convertToBinary(target);

    printf("Converted array: \n");
    for (i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nConverted target: \n%d\n", target);


    int result = linearSearch(arr, n, target);
    printf("Search result: \n%d\n", result);

    printf("Original array: \n");
    for (i = 0; i<n; i++) {
        printf("%d ", arr_0[i]);
    }

    printf("\nOriginal target: \n%d", target_0);
    
    return 0;
    
}