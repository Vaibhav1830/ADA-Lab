#include <stdio.h>
#include <time.h>

void heapcom(int a[], int n) {
    int i, j, k, item;
    for (i = 1; i <= n; i++) {
        item = a[i];
        j = i;
        k = j / 2;
        while (k != 0 && item > a[k]) {
            a[j] = a[k];
            j = k;
            k = j / 2;
        }
        a[j] = item;
    }
}

void adjust(int a[], int n) {
    int item, i, j;
    j = 1;
    item = a[j];
    i = 2 * j;
    while (i <= n) {
        if (i + 1 <= n && a[i] < a[i + 1])
            i++;
        if (item < a[i]) {
            a[j] = a[i];
            j = i;
            i = 2 * j;
        } else {
            break;
        }
    }
    a[j] = item;
}

void heapsort(int a[], int n) {
    int i, temp;
    heapcom(a, n);
    for (i = n; i >= 2; i--) {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        adjust(a, i - 1);
    }
}

int main() {
    int i, n, a[21], ch = 1;  // a[21] so index 1 to 20 is usable
    clock_t start, end;

    while (ch) {
        printf("\nEnter the number of elements to sort (max 20): ");
        scanf("%d", &n);
        if (n > 20) {
            printf("Maximum allowed is 20 elements.\n");
            continue;
        }

        printf("Enter the elements:\n");
        for (i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        start = clock();
        heapsort(a, n);
        end = clock();

        printf("\nSorted list of elements:\n");
        for (i = 1; i <= n; i++)
            printf("%d\n", a[i]);

        printf("\nTime taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("\nDo you want to run again? (1 for Yes, 0 for No): ");
        scanf("%d", &ch);
    }

    return 0;
}
