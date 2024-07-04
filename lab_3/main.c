/*Тема: задача з розрядами

Скільки можна сформувати чисел із р розрядів, використовуючи цифри 5 та 9,
 в яких три однакові цифри не стоять поруч?

Вхідні дані: ціле число р (р ≤ 30)

Вихідні дані: кількість чисел із р розрядів*/
#include <stdio.h>

long long countNumbers(int p) {
    if (p <= 0)
        return 0;
    if (p == 1)
        return 2;
    long long dp[p+1];
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i <= p; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[p];
}

int main() {
    int p;
    printf("Введіть кількість розрядів p (p ≤ 30): ");
    scanf("%d", &p);

    if (p <= 0 || p > 30) {
        printf("Неправильне значення p. Введіть число від 1 до 30.\n");
        return 1;
    }

    long long result = countNumbers(p);

    printf("Кількість чисел з %d розрядів, в яких три однакові цифри не стоять поруч: %lld\n", p, result);

    return 0;
}
