#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_START 1000
#define N_END 5000
#define N_INC 1000
#define N_RUNS 5

void bubbleSort(int arr[], int n, int *swaps, int *comparisons) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swaps)++;
            }
        }
    }
}
void merge(int arr[], int l, int m, int r, int *swaps, int *comparisons) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            (*swaps)++;
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
void mergeSort(int arr[], int l, int r, int *swaps, int *comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, swaps, comparisons);
        mergeSort(arr, m + 1, r, swaps, comparisons);
        merge(arr, l, m, r, swaps, comparisons);
    }
}



void selectionSort(int arr[], int n, int *swaps, int *comparisons) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
        (*comparisons)++;
        if (arr[j] < arr[minIndex])
            minIndex = j;
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            (*swaps)++;
        }
    }
}

int main() {
    int i, j;
    int n = N_START;
    int swaps, comparisons;
    double time_elapsed;
    int ArrayBubble_Sort[n], ArrayBubble_Sortd[n], ArrayMerge_Sort[n], ArrayMerge_Sortd[n], ArraySelection_Sort[n], ArraySelection_Sortd[n];
    int NumberOfComparisonBubble_Sort[N_RUNS], NumberOfswappingBubble_Sort[N_RUNS], NumberOfComparisonBubble_Sortd[N_RUNS], NumberOfswappingBubble_Sortd[N_RUNS], NumberOfComparisonMerge_Sort[N_RUNS], NumberOfswappingMerge_Sort[N_RUNS], NumberOfComparisonMerge_Sortd[N_RUNS], NumberOfswappingMerge_Sortd[N_RUNS], NumberOfComparisonSelection_Sort[N_RUNS], NumberOfswappingSelection_Sort[N_RUNS], NumberOfComparisonSelection_Sortd[N_RUNS], NumberOfswappingSelection_Sortd[N_RUNS];
    double bubble_Sort_Time[N_RUNS], bubble_Sortd_Time[N_RUNS], Merge_Sort_Time[N_RUNS], Merge_Sortd_Time[N_RUNS], Selection_Sort_Time[N_RUNS], Selection_Sortd_Time[N_RUNS];
    srand(time(0));
    while (n <= N_END) {
        for (i = 0; i < N_RUNS; i++) {
            for (j = 0; j < n; j++) {
            ArrayBubble_Sort[j] = rand() % n;
            ArrayBubble_Sortd[j] = ArrayBubble_Sort[j];
            ArrayMerge_Sort[j] = ArrayBubble_Sort[j];
            ArrayMerge_Sortd[j] = ArrayBubble_Sort[j];
            ArraySelection_Sort[j] = ArrayBubble_Sort[j];
            ArraySelection_Sortd[j] = ArrayBubble_Sort[j];
            }
        // unsorted
        swaps = 0;
        comparisons = 0;
        clock_t start_time = clock();
        bubbleSort(ArrayBubble_Sort, n, &swaps, &comparisons);
        clock_t end_time = clock();
        time_elapsed = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        bubble_Sort_Time[i] = time_elapsed;
        NumberOfComparisonBubble_Sort[i] = comparisons;
        NumberOfswappingBubble_Sort[i] = swaps;
        // sorted
        swaps = 0;
        comparisons = 0;
        start_time = clock();
        bubbleSort(ArrayBubble_Sortd, n, &swaps, &comparisons);
        end_time = clock();
        time_elapsed = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        bubble_Sortd_Time[i] = time_elapsed;
        NumberOfComparisonBubble_Sortd[i] = comparisons;
        NumberOfswappingBubble_Sortd[i] = swaps;

        // unsorted
        swaps = 0;
        comparisons = 0;
        start_time = clock();
        mergeSort(ArrayMerge_Sort, 0, n - 1, &swaps, &comparisons);
        end_time = clock();
        time_elapsed = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        Merge_Sort_Time[i] = time_elapsed;
        NumberOfComparisonMerge_Sort[i] = comparisons;
        NumberOfswappingMerge_Sort[i] = swaps;

        // sorted
        swaps = 0;
        comparisons = 0;
        start_time = clock();
        mergeSort(ArrayMerge_Sortd, 0, n - 1, &swaps, &comparisons);
        end_time = clock();
        time_elapsed = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        Merge_Sortd_Time[i] = time_elapsed;
        NumberOfComparisonMerge_Sortd[i] = comparisons;
        NumberOfswappingMerge_Sortd[i] = swaps;

        // unsorted
        swaps = 0;
        comparisons = 0;
        start_time = clock();
        selectionSort(ArraySelection_Sort, n, &swaps, &comparisons);
        end_time = clock();
        time_elapsed = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        Selection_Sort_Time[i] = time_elapsed;
        NumberOfComparisonSelection_Sort[i] = comparisons;
        NumberOfswappingSelection_Sort[i] = swaps;

        // sorted
        swaps = 0;
        comparisons = 0;
        start_time = clock();
        selectionSort(ArraySelection_Sortd, n, &swaps, &comparisons);
        end_time = clock();
        time_elapsed = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        Selection_Sortd_Time[i] = time_elapsed;
        NumberOfComparisonSelection_Sortd[i] = comparisons;
        NumberOfswappingSelection_Sortd[i] = swaps;
        }
    }
    n+= N_INC;
}