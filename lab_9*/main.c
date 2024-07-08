/*Розглянемо процес переходу від цілого x до цілого y вздовж цілих точок прямої.
Довжина кожного кроку має бути невід’ємною та бути або на одиницю більшою, або дорівнювати, або на одиницю меншою за довжину попереднього кроку. Довжина першого і останнього кроків повинна бути 1.
Створіть функцію, яка обчислює мінімальну кількість кроків, необхідних для переходу від x до y.
Він повинен обробляти 0 <= x <= y < 2 ^31 .*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool TInteger(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

int minSteps(int x, int y) {
    int distance = y - x;

    if (distance == 0) return 0;

    int steps = 0;
    int stepSize = 0;
    int totalSteps = 0;

    while (totalSteps < distance) {
        steps++;
        if (steps % 2 == 1) stepSize++;
        totalSteps += stepSize;
    }
    return steps;
}

int main() {
    char xStr[20], yStr[20];
    int x, y;

    printf("Введіть значення x: ");
    scanf("%s", xStr);
    printf("Введіть значення y: ");
    scanf("%s", yStr);

    if (!TInteger(xStr) || !TInteger(yStr)) {
        printf("Помилка! Введіть невід'ємні цілі числа.\n");
        return 1;
    }

    x = atoi(xStr);
    y = atoi(yStr);

    if (x < 0 || y < 0 || x > y) {
        printf("Помилка! Переконайтеся, що 0 <= x <= y.\n");
        return 1;
    }

    int result = minSteps(x, y);
    printf("Мінімальна кількість кроків: %d\n", result);

    return 0;
}