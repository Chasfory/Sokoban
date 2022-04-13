/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** Task03
*/

#include <stdio.h>

int my_strlen(char *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int lenght = my_strlen(dest);
    int a = 0;

    while (a < nb && src[a] != '\0') {
        dest[lenght + a] = src[a];
        a++;
    }
    dest[lenght + a] = '\0';
    return (dest);
}