/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** task02
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen_cat(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return (len);
}

char *my_strcat(char const *dest, char const *src)
{
    int i;
    int cmp = my_strlen_cat(dest);
    int cmp_2 = my_strlen_cat(src);
    char *tmp = malloc(sizeof(char) * (my_strlen_cat(dest) +
    my_strlen_cat(src) + 1));

    if (tmp == NULL) {
        return NULL;
    }
    for (i = 0; i < cmp; i++) {
        tmp[i] = dest[i];
    }
    for (int b = 0; b < cmp_2; b++, i++) {
        tmp[i] = src[b];
    }
    tmp[i] = '\0';
    return (tmp);
}