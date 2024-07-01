/* В честь свята приготували великий пиріг, на святі було 3 гостя.
 * Перший гість може з’їсти пиріг за t1 годин,
 * другий гість може з’їсти пиріг за t2 годин,
 * третій гість може з'їсти пиріг за t3 годин.
 * Скільки часу потрібно гостям щоб з’їсти один пиріг?
 */

#include <stdio.h>
double calculate_time(double t1, double t2, double t3) {
    double total_time = (1.0 / t1 + 1.0 / t2 + 1.0 / t3);
    return 1.0 / total_time;
}
int main() {
    double t1, t2, t3;
    printf("Введіть три числа від 1 до 10000 (t1, t2, t3): ");
    if (scanf("%lf %lf %lf", &t1, &t2, &t3) != 3) {
        printf("Помилка вводу. Будь ласка, введіть три числа.\n");
        return 1;
    }
    if (t1 <= 0 || t2 <= 0 || t3 <= 0 || t1 > 10000 || t2 > 10000 || t3 > 10000) {
        printf("Помилка! Не виконується умова (1<n<10000)\n");
        return 1;
    }
    double result = calculate_time(t1, t2, t3);
    printf("Час, потрібний для з'їдання одного пирога всіма гостями разом: %.2f годин\n", result);

    if (result < 1) {
        double result_minutes = result * 60;
        printf("Це приблизно %.0f хвилин.\n", result_minutes);
    }
    return 0;
}


