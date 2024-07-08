/*Анаграмою слова називають перестановку всіх букв слова.
 * Наприклад зі слова SOLO можна отримати 12 анаграм: SOLO, LOSO, OSLO, OLSO, OSOL, OLOS, SLOO, OOLS, OOSL, LOOS, SOOL.
 * Напишіть програму, яка виводитиме кількість анаграм , які можуть вийти зі слова.
Вхідні дані: в одному рядку задане слово, кількість букв якого не перевищує 14.
Вихідні дані: кількість можливих анаграм.*/
#include <stdio.h>
#include <string.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

unsigned long long countAnagrams(char *str) {
    int n = strlen(str);
    int counts[256] = {0};

    for (int i = 0; i < n; i++) {
        counts[(int)str[i]]++;
    }

    unsigned long long denominator = 1;
    for (int i = 0; i < 256; i++) {
        if (counts[i] > 1) {
            denominator *= factorial(counts[i]);
        }
    }

    return factorial(n) / denominator;
}

int main() {
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);

    unsigned long long anagramCount = countAnagrams(word);
    printf("Кількість можливих анаграм: %llu\n", anagramCount);

    return 0;
}