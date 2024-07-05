/*Тема: два кола

Дано два кола, визначте кількість точок перетину

Вхідні дані: шість чисел х1, y1, r1, х2, y2, r2, де х1, y1, х2, y2 - координати центрів, а r1 та r2 - їх радіуси.

Вихідні дані: кількість точок перетину. Якщо точок перетину безкінечно багато, то вивести -1.*/
#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    double x1, y1, r1, x2, y2, r2;
    printf("Введіть координати центру та радіус першого кола та другого кола (x1, y1, r1, x2, y2, r2):\n");
    if (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2) != 6) {
        printf("Помилка! Будь ласка, введіть шість чисел.\n");
        return 1; }

    double d = distance(x1, y1, x2, y2);
    double sumr = r1 + r2;
    double diffr = fabs(r1 - r2);

    if (d == 0 && r1 == r2) {
        printf("-1\n");  // Безкінечно багато точок перетину
    } else if (d > sumr || d < diffr) {
        printf("0\n");  // Немає точок перетину
    } else if (d == sumr || d == diffr) {
        printf("1\n");  // Точки торкання
    } else {
        printf("2\n");  // Дві точки перетину
    }

    return 0;
}
