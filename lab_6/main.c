/*Тема: довжина вектора

Визначити довжину вектора за його координатами.

Вхідні дані: чотири цілі числа х1, у1, х2, у2 - кордина ти початку та кінця вектора відповідно

Вихідні дані: одне число - довжина вектора з точністю до шести знаків після коми*/
#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;
    int input;

    printf("Введіть координати x1, y1, x2, y2: ");
    input = scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if (input != 4) {
        printf("Помилка! Введіть чотири цілі числа.\n");;
        return 1;
    }

    double dx = x2 - x1;
    double dy = y2 - y1;
    double length = sqrt(dx * dx + dy * dy);//sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("Довжина вектора: %.6f\n", length);

    return 0;
}
