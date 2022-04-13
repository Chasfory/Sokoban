/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** task03
*/

#include <unistd.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int p;
    int f = my_strlen(str) - 1;

    for (p = 0; p < f; f-- && p++) {
        char e = str[p];
        str[p] = str[f];
        str[f] = e;
    }
    return str;
}