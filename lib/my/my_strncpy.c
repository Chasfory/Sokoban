/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** Task02
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int p = 0;

    while (p != n) {
        dest[p] = src[p];
        p++;
    }
    return dest;
}