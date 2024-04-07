#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_SIZE 100

int c[MAX_SIZE + 1];
int n, k;

void combinationsGenerator() {
    
    int i, j;
    //инициализация
    for (i = 0; i <= k; i++) {
        c[i] = i - 1;
    }

    //генерация
    while (1) {
        for (i = 0; i <= k; i++) {
            if (i > 0) {
                printf("%d ", c[i] + 1);
            }
        }
        printf("\n");

        //поиск первого элемента для инкремента
        j = k;
        while (j >= 0 && c[j] == n - k + j - 1) {
            j--;
        }
        if (j <= 0) {
            break;
        }

        //инкремент первого элемента
        c[j]++;

        //сброс всех элементов вправо
        for (i = j + 1; i <= k; i++) {
            c[i] = c[i - 1] + 1;
        }
    }
}

void error() {
    printf("Ошибка: введены некорректные значения.");
    exit(1);
}

int main() {
    SetConsoleOutputCP(1251);

    printf("Введите мощность множества: ");
    int isDigit = scanf("%d", &n);
    if (isDigit != 1)
        error();

    printf("Введите мощность выборки: ");
    isDigit = scanf("%d", &k);
    if (isDigit != 1)
        error();

    if (k > n || k <= 0 || n <= 0 || k > 100 || n > 100)
        error();

    combinationsGenerator();

    return 0;
}