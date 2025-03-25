#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void manualEntry() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter array elements: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array is: ");
    printArray(arr, N);

    clock_t start_time = clock();
    mergeSort(arr, 0, N - 1);
    clock_t end_time = clock();

    double time_taken = ((double)end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array is: ");
    printArray(arr, N);

    printf("Time taken to sort %d numbers is %f Secs\n", N, time_taken);
}

void timeForRanges() {
    for (int N = 500; N <= 14500; N += 1000) {
        int arr[N];
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 1000;
        }

        clock_t start_time = clock();
        mergeSort(arr, 0, N - 1);
        clock_t end_time = clock();

        double time_taken = ((double)end_time - start_time) / CLOCKS_PER_SEC;

        printf("Time taken to sort %d numbers is %f Secs\n", N, time_taken);
    }
}

int main() {
    int choice;
    do {
        printf("\n1: For manual entry of N value and array elements\n");
        printf("2: To display time taken for sorting number of elements N in the range 500 to 14500\n");
        printf("3: To exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manualEntry();
                break;
            case 2:
                timeForRanges();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
