/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** Task19
*/

#include <stdio.h>

int sign(char const *str, int i)
{
    int s = 0;

    for (int i = 0; (str[i] <= '0' || str[i] >= '9'); i++) {
        if (str[i] == '-')
            s++;
    }
    return (s);
}

int take(char const *str, int i)
{
    int nb = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        nb += str[i] - '0';
        if (str[i + 1] >= '0' && str[i + 1] <= '9')
            nb *= 10;
        i++;
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    int a = 0;
    int nb = 0;

    for (a = 0; str[a] != '\0'; a++) {
        if (str[a] >= '0' && str[a] <= '9') {
            nb += (take(str, a));
            break;
        }
    }
    if (nb == 0)
        return (0);
    if ((sign(str, a)) % 2 == 1)
        return (-nb);
    else
        return (nb);
}