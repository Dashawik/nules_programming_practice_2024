/*Тема: задача на знаходження НСК

Знайти найменше спільне кратне р натуральних чисел

Вхідні дані: в першому рядку задано кількість чисел р(2 ≤ р ≤ 20),
а в другому рядку р натуральних чисел, розділені пробілом

Вихідні дані: найменше спільне кратне заданих чисел
 */

#include <stdio.h>
int find_nsd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int find_nsk(int a, int b) {
    return (a * b) / find_nsd(a, b);
}

int main() {
    int a;
    printf("Введіть кількість чисел (2 ≤ р ≤ 20)\n");
    scanf("%d", &a);

    if (a < 2 || a > 20) {
        printf("Кількість чисел повинна бути в діапазоні від 2 до 20\n");
        return 1;
    }

    int ArrInput[a];

    printf("Введіть %d натуральних чисел, розділені пробілом: ", a);

    for (int i = 0; i < a; i++)
        scanf("%d", &ArrInput[i]);

    int result= ArrInput[0];
    for (int i = 1; i < a; ++i) {
        result = find_nsk(result, ArrInput[i]);
    }

    printf("Найменше спільне кратне: %d\n", result);

    return 0;
}
