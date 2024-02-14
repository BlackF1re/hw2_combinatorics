#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void print_combination(int* arr, int k, int n) {
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generate_combinations(int* arr, int start, int index, int k, int n) {
    if (index == k) {
        print_combination(arr, k, n);
        return;
    }

    for (int i = start; i < n - k + index + 1; i++) {
        arr[index] = i;
        generate_combinations(arr, i + 1, index + 1, k, n);
    }
}

void error() {
    printf("—опл€к.");
    exit(1);
}

int main() {
    SetConsoleOutputCP(1251);
    int n, k;

    printf("¬ведите мощность множества: ");
    int isDigit = scanf("%d", &n);
    if (isDigit != 1)
        error();

    printf("¬ведите мощность выборки: ");
    isDigit = scanf("%d", &k);
    if (isDigit != 1)
        error();

    if (k > n || k <= 0 || n <= 0)
        error();

    int* arr = (int*)malloc(k * sizeof(int));

    generate_combinations(arr, 0, 0, k, n);

    free(arr);
    return 0;
}